#include <iostream>
#include <limits>
#include <algorithm>
#include "CGestorAreaConhecimento.h"

using namespace std;

// Variáveis estáticas, compartilhadas entre objetos.
std::string CGestorAreaConhecimento::caminhoDiretorio = "dados/TabeladeAreasdoConhecimento/";

std::string CGestorAreaConhecimento::nomeArquivo      = "TabeladeAreasdoConhecimento-Assuntos-"; // padrão, sem o estado

std::map<std::string,std::string> CGestorAreaConhecimento::map_codigo_descricao;

CGestorAreaConhecimento::CGestorAreaConhecimento() {
    if(map_codigo_descricao.size() == 0)
      RecuperarEstado();
}

CGestorAreaConhecimento::CGestorAreaConhecimento(const std::string identificadorEstado) {
      RecuperarEstado(identificadorEstado);
}

CGestorAreaConhecimento::~CGestorAreaConhecimento() {
     SalvarEstado();
}

CCodigoAreaConhecimento CGestorAreaConhecimento::DefinirAreaConhecimento() {
  VisualizarTabelaAreaConhecimento();
  std::string codigo;
  while(true) {
  std::cout << "\nEntre com o codigo da área de conhecimento: ";
  std::getline(std::cin, codigo);
  auto search = map_codigo_descricao.find(codigo);
  if ( search != map_codigo_descricao.end())
    return CCodigoAreaConhecimento(codigo);
  else
    cerr << "\nCódigo inválido, tente novamente.\n";
  }
}

std::string CGestorAreaConhecimento::DescricaoAreaConhecimento(CCodigoAreaConhecimento& ac) {
  return map_codigo_descricao[ac];
}

void CGestorAreaConhecimento::VisualizarTabelaAreaConhecimento() {
  cout <<"\nMapa com código e descrição da área de conhecimento\n";
  for( auto& [codigo,descricao]: map_codigo_descricao )
    cout << codigo << ' ' << descricao << '\n';
}

void CGestorAreaConhecimento::VisualizarTabelaAreaConhecimento(std::vector<CCodigoAreaConhecimento>& vCodigo) {
  cout << "\nTabela de Áreas do Conhecimento\n";
  std::for_each(vCodigo.begin(), vCodigo.end(),
                [](CCodigoAreaConhecimento& codigo){ cout << codigo.CodigoDescricao() << '\n';});
  cout << '\n';
}

// bool CGestorAreaConhecimento::VerificarCodigo(std::string codigoASerVerificado)
// {
//   //..Implementar.
//   // precisa decompor o código, ex: LEP-0011 -> LEP e 11
//   // e verificar se esta no map.
// }

void CGestorAreaConhecimento::CaminhoDiretorio(const std::string _caminhoDiretorio)  { caminhoDiretorio = _caminhoDiretorio; };

const std::string  CGestorAreaConhecimento::CaminhoDiretorio()  const { return caminhoDiretorio; };

void CGestorAreaConhecimento::NomeArquivo(const std::string _nomeArquivo)            { nomeArquivo = _nomeArquivo; };

const std::string  CGestorAreaConhecimento::NomeArquivo() const  { return nomeArquivo; };

void CGestorAreaConhecimento::SalvarEstado(const std::string identificadorEstado) const
{
    std::string nomeCompleto = caminhoDiretorio + nomeArquivo + identificadorEstado + ".dat";
    std::ofstream arquivo (nomeCompleto);
    if(arquivo.fail()) {
      cerr << "\nNão conseguiu abrir o arquivo:" << nomeCompleto << " para escrita... encerrando!\n";
      exit(0);
    }
    arquivo << "Tabela de Áreas do Conhecimento\n"; // cabeçalho.
    for( auto& [codigo,descricao]: map_codigo_descricao )
      arquivo << codigo << ' ' << descricao << '\n';
    arquivo.close(); // opcional, descarrega o buffer e fecha o arquivo.
}

void CGestorAreaConhecimento::RecuperarEstado(const std::string identificadorEstado)
{
    std::string nomeCompleto = caminhoDiretorio + nomeArquivo + identificadorEstado + ".dat";
    std::ifstream arquivo (nomeCompleto);
    std::string codigo;
    std::string descricao;
    if(arquivo.fail()) {
      cerr << "\nNão conseguiu abrir o arquivo:" << nomeCompleto << " para leitura... encerrando!\n";
      exit(0);
    }
    map_codigo_descricao.clear(); // Apaga tudo pois vai recuperar do arquivo de disco.
    arquivo.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // ignora linha comentário
    while (! arquivo.eof() ) {
      arquivo >> codigo;
      getline(arquivo,descricao);
      map_codigo_descricao[codigo] = descricao;
    }
}

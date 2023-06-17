#include <iostream>
#include <limits>
#include <algorithm>
#include <filesystem>
#include "CGestorAreaConhecimento.h"

using namespace std;
namespace fs = std::filesystem;

// Variáveis estáticas, compartilhadas entre objetos.
std::filesystem::path  CGestorAreaConhecimento::caminhoDiretorio = "dados/TabeladeAreasdoConhecimento/";

std::filesystem::path  CGestorAreaConhecimento::nomeArquivo      = "TabeladeAreasdoConhecimento-Assuntos-EngenhariaPetroleo.dat"; // padrão, sem o estado

std::map<std::string,std::string> CGestorAreaConhecimento::map_codigo_descricao;

bool CGestorAreaConhecimento::mapNoDiscoAtualizado = true;

CGestorAreaConhecimento::CGestorAreaConhecimento() {
    if(map_codigo_descricao.size() == 0)
      RecuperarEstado(/*CGestorAreaConhecimento::nomeArquivo*/);
}

CGestorAreaConhecimento::CGestorAreaConhecimento(const std::string identificadorEstado) {
      RecuperarEstado(identificadorEstado);
}

CGestorAreaConhecimento::~CGestorAreaConhecimento() {
  if( mapNoDiscoAtualizado == false )
     SalvarEstado(CGestorAreaConhecimento::nomeArquivo);
}

CCodigoAreaConhecimento CGestorAreaConhecimento::DefinirAreaConhecimento() {
  //VisualizarTabelaAreaConhecimento();
  std::string codigo;
  while(true) {
  std::cout << "\nEntre com o codigo da área de conhecimento (q para sair): ";
  std::getline(std::cin, codigo);
  auto search = map_codigo_descricao.find(codigo);
  if ( search != map_codigo_descricao.end() or codigo == "q" or codigo == "Q")
    return CCodigoAreaConhecimento(codigo);
  else
    cerr << "\nCódigo inválido, tente novamente.\n";
  }
}

std::string CGestorAreaConhecimento::DescricaoAreaConhecimento(/*const*/ CCodigoAreaConhecimento& ac) {
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

void CGestorAreaConhecimento::CaminhoDiretorio(const std::filesystem::path& _caminhoDiretorio)
{ caminhoDiretorio = _caminhoDiretorio; };

const std::filesystem::path& CGestorAreaConhecimento::CaminhoDiretorio()  const
{ return caminhoDiretorio; };

void CGestorAreaConhecimento::NomeArquivo(const std::filesystem::path& _nomeArquivo)
{
  nomeArquivo = _nomeArquivo;
}

const std::filesystem::path&  CGestorAreaConhecimento::NomeArquivo() const
{ return nomeArquivo; };

bool CGestorAreaConhecimento::SalvarArquivo(std::filesystem::path caminhoCompleto)  const
{
    std::ofstream arquivo (caminhoCompleto.string());
    if(arquivo.fail()) {
      cerr << "\nNão conseguiu abrir o arquivo:" << caminhoCompleto << " para escrita... não salvou!\n";
      //exit(0);
      return false;
    }
    arquivo << "Tabela de Áreas do Conhecimento\n"; // cabeçalho.
    for( auto& [codigo,descricao]: map_codigo_descricao )
      arquivo << codigo << ' ' << descricao << '\n';
    arquivo.close(); // opcional, descarrega o buffer e fecha o arquivo.
    return true;
}

bool CGestorAreaConhecimento::RecuperarArquivo(std::filesystem::path caminhoCompleto)
{
std::cerr << "\nDEBUG12 CaminhoDiretorio()=" << CaminhoDiretorio();
std::cerr << "\nDEBUG12 NomeArquivo()=" << NomeArquivo();
std::cerr << "\nDEBUG12 caminhoCompleto=" << caminhoCompleto;
    std::ifstream arquivo (caminhoCompleto.string());
    if(arquivo.fail()) {
      cerr << "\nNão conseguiu abrir o arquivo:" << caminhoCompleto << " para leitura... não carregou!\n";
      //exit(0);
      return false;
    }
    std::string codigo;
    std::string descricao;
    map_codigo_descricao.clear(); // Apaga tudo pois vai recuperar do arquivo de disco.
    arquivo.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // ignora linha comentário
    while (! arquivo.eof() ) {
      arquivo >> codigo;
      getline(arquivo,descricao);
      map_codigo_descricao[codigo] = descricao;
    }
    return true;
}

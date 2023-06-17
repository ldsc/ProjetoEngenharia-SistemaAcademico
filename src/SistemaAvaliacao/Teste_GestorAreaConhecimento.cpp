#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "CGestorAreaConhecimento.h"
#include "CCodigoAreaConhecimento.h"

using namespace std;
// A classe CCodigoAreaConhecimento tem o objetivo de armazenar o código da disciplina e,
// ao mesmo tempo, gerenciar o arquivo que tem a lista de departamentos e códigos usados.
int main() {
  CGestorAreaConhecimento geradorAreaConhecimento;
  std::cout << "\nVisualizando a tabela codigo<->areaDoConhecimento estado atual:\n"
            << "\nNomeArquivo = " << CGestorAreaConhecimento::nomeArquivo << '\n';
  geradorAreaConhecimento.VisualizarTabelaAreaConhecimento();

  std::vector<CCodigoAreaConhecimento> vCodigo;
  char resp{'c'};
  while(resp == 'c') {
    vCodigo.push_back(geradorAreaConhecimento.DefinirAreaConhecimento());
    cout << "\nAdicionou no vetor o codigo : " << vCodigo.back().CodigoDescricao();
    cout << "\nContinuar (c) ou parar (q):";
    cin.get(resp); cin.get();
  }

  cout << "\nVisualizando a tabela codigo<->areaDoConhecimento para o vetor selecionado: ";
  cout << "\nTabela de Áreas do Conhecimento\n";
  std::for_each(vCodigo.begin(), vCodigo.end(),
                [](CCodigoAreaConhecimento& codigo){ cout << codigo.CodigoDescricao() << '\n';});
  cout << "\nPressione enter para continuar.";
  cin.get();

  std::string identificadorEstado = "-1";
  if(geradorAreaConhecimento.SalvarEstado(identificadorEstado))
   std::cout << "\nSalvou a tabela no estado -1, procure por arquivo [" << CGestorAreaConhecimento::nomeArquivo.string() << "]\n";

  geradorAreaConhecimento.RecuperarEstado("","TabeladeAreasdoConhecimento-Assuntos-Computacao.dat");
  std::cout << "\nVisualizando a tabela codigo<->areaDoConhecimento estado atual:\n"
            << "\nNomeArquivo = " << CGestorAreaConhecimento::nomeArquivo << '\n';
  geradorAreaConhecimento.VisualizarTabelaAreaConhecimento();

  cin.get();
  std::filesystem::path arquivo_engenharia { "TabeladeAreasdoConhecimento-Assuntos-EngenhariaPetroleo.dat"};
  geradorAreaConhecimento.RecuperarDiretorioArquivo(CGestorAreaConhecimento::caminhoDiretorio,arquivo_engenharia);
  std::cout << "\nVisualizando a tabela codigo<->areaDoConhecimento estado atual (engenharia?):\n"
            << "\nNomeArquivo = " << CGestorAreaConhecimento::nomeArquivo << '\n';
  geradorAreaConhecimento.VisualizarTabelaAreaConhecimento();
return 0;
}

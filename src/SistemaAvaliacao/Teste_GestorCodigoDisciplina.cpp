#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "CGestorCodigoDisciplina.h"
#include "CCodigoDisciplina.h"

using namespace std;
// A classe CCodigoDisciplina tem o objetivo de armazenar o código da disciplina e,
// ao mesmo tempo, gerenciar o arquivo que tem a lista de departamentos e códigos usados.
int main() {
  CGestorCodigoDisciplina gestorCodigoDisciplina;
  // std::cout << "\nVisualizando a tabela siglaDepartamento<->codigoUsado estado atual:\n";
  // gestorCodigoDisciplina.VisualizarTabelaDepartamentoUltimoCodigo();
  std::string sSiglaDepartamento;
  //std::string sCodigoDisciplina;
  //CCodigoDisciplina sCodigoDisciplina;
  cout << "\nVai repetir 5x..";
  for(int i=0; i<5; i++) {
    CCodigoDisciplina CodigoDisciplina = gestorCodigoDisciplina.CriarCodigoDisciplina();
    cout << "\nCódigo gerado = " << CodigoDisciplina << '\n';

    gestorCodigoDisciplina.SalvarEstado(std::to_string(i));
  }
  std::cout << "\nVisualizando a tabela siglaDepartamento<->codigoUsado estado atual:\n";
  gestorCodigoDisciplina.VisualizarTabelaDepartamentoUltimoCodigo();
  std::cout << "\nEntre com a sigla do novo departamento: ";
  std::getline(cin, sSiglaDepartamento);
  gestorCodigoDisciplina.AdicionarDepartamento(sSiglaDepartamento);
  std::cout << "\nVisualizando a tabela siglaDepartamento<->codigoUsado estado atual:\n";
  gestorCodigoDisciplina.VisualizarTabelaDepartamentoUltimoCodigo();
  std::cout << "\nLista arquivos no diretório dados/TabelaCodigoDisciplina/:\n";
  system("ls dados/TabelaCodigoDisciplina/");
  std::cout << "\nEntre com o identificador da tabela a ser recuperada\n"
               "(se o nome do arquivo = dados/TabelaCodigoDisciplina/mapSiglaCodigo-3.dat)\n"
               "o número 3 é o identificador do estado a ser recuperado):";
  std::string identificadorEstado;
  std::getline(cin, identificadorEstado);
  gestorCodigoDisciplina.RecuperarEstado(identificadorEstado);
  gestorCodigoDisciplina.VisualizarTabelaDepartamentoUltimoCodigo();
return 0;
}

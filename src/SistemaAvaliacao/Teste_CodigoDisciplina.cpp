#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "CCodigoDisciplina.h"

using namespace std;
// A classe CCodigoDisciplina tem o objetivo de armazenar o código da disciplina e,
// ao mesmo tempo, gerenciar o arquivo que tem a lista de departamentos e códigos usados.
int main() {
  CCodigoDisciplina geradorCodigoDisciplina;
  std::cout << "\nVisualizando a tabela siglaDepartamento<->codigoUsado estado atual:\n";
  geradorCodigoDisciplina.VisualizarTabelaDepartamentoUltimoCodigo();
  std::string siglaDepartamento;
  std::string codigoDisciplina;
  cout << "\nVai repetir 10x..";
  for(int i=0; i<10; i++) {
    std::cout << "\nEntre com a siglaDepartamento do departamento: ";
    std::getline(cin, siglaDepartamento);
    codigoDisciplina = geradorCodigoDisciplina(siglaDepartamento);
    //codigoDisciplina = geradorCodigoDisciplina.DefinirCodigo(siglaDepartamento);
    cout << "\nCódigo gerado = " << codigoDisciplina << '\n';
    geradorCodigoDisciplina.SalvarEstado(std::to_string(i));
  }
  std::cout << "\nVisualizando a tabela siglaDepartamento<->codigoUsado estado atual:\n";
  geradorCodigoDisciplina.VisualizarTabelaDepartamentoUltimoCodigo();
  std::cout << "\nEntre com a siglaDepartamento de departamento novo: ";
  std::getline(cin, siglaDepartamento);
  geradorCodigoDisciplina.AdicionarDepartamento(siglaDepartamento);
  std::cout << "\nVisualizando a tabela siglaDepartamento<->codigoUsado estado atual:\n";
  geradorCodigoDisciplina.VisualizarTabelaDepartamentoUltimoCodigo();
  std::cout << "\nLista arquivos no diretório dados/TabelaCodigoDisciplina/:\n";
  system("ls dados/TabelaCodigoDisciplina/");
  std::cout << "\nEntre com o identificador da tabela a ser recuperada\n"
               "(se o nome do arquivo = dados/TabelaCodigoDisciplina/mapSiglaCodigo-3.dat)\n"
               "o número 3 é o identificador do estado a ser recuperado):";
  std::string identificadorEstado;
  std::getline(cin, identificadorEstado);
  geradorCodigoDisciplina.RecuperarEstado(identificadorEstado);
  geradorCodigoDisciplina.VisualizarTabelaDepartamentoUltimoCodigo();
return 0;
}

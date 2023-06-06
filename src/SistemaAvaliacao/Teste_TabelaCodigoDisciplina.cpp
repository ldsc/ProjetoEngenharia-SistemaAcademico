#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "CTabelaCodigoDisciplina.h"

using namespace std;

int main() {
  CTabelaCodigoDisciplina tabelaCodigoDisciplina;
  std::cout << "\nVisualizando nossa tabela no estado atual:\n";
  tabelaCodigoDisciplina.Visualizar();
  std::string sigla;
  std::string codigo;
  cout << "\nVai repetir 10x..";
  for(int i=0; i<10; i++) {
    std::cout << "\nEntre com a sigla do departamento: ";
    std::getline(cin, sigla);
    codigo = tabelaCodigoDisciplina.DefinirCodigo(sigla);
    cout << "\nCódigo gerado = " << codigo << '\n';
    tabelaCodigoDisciplina.SalvarEstado(std::to_string(i));
  }
  std::cout << "\nVisualizando nossa tabela no estado atual:\n";
  tabelaCodigoDisciplina.Visualizar();
  std::cout << "\nEntre com a sigla de departamento novo: ";
  std::getline(cin, sigla);
  tabelaCodigoDisciplina.AdicionarDepartamento(sigla);
  std::cout << "\nVisualizando nossa tabela no estado atual:\n";
  tabelaCodigoDisciplina.Visualizar();
  system("ls dados/TabelaCodigoDisciplina/");
  std::cout << "\nEntre com o identificador da tabela\n \
                (se o nome arquivo = dados/TabelaCodigoDisciplina/mapSiglaCodigo-3.dat)\n \
                entre o número 3):";
  std::string identificadorEstado;
  std::getline(cin, identificadorEstado);
  tabelaCodigoDisciplina.RecuperarEstado(identificadorEstado);
  tabelaCodigoDisciplina.Visualizar();
return 0;
}


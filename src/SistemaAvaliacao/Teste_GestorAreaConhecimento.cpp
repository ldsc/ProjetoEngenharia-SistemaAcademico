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
  std::cout << "\nVisualizando a tabela codigo<->areaDoConhecimento estado atual:\n";
  geradorAreaConhecimento.VisualizarTabelaAreaConhecimento();
  std::cout << "\nSalvando a tabela no estado 1:\n";
  geradorAreaConhecimento.SalvarEstado("1");

  std::vector<CCodigoAreaConhecimento> vCodigo;
  char resp{'1'};
  while(resp == '1') {
    vCodigo.push_back(geradorAreaConhecimento.DefinirAreaConhecimento());
    cout << "\nAdicionou no vetor o codigo : " << vCodigo.back().CodigoDescricao();
    cout << "\nContinuar (1) ou parar (0):";
    cin.get(resp); cin.get();
  }

  cout << "\nVisualizando a tabela codigo<->areaDoConhecimento para o vetor selecionado: ";
  cout << "\nTabela de Áreas do Conhecimento\n";
  std::for_each(vCodigo.begin(), vCodigo.end(),
                [](CCodigoAreaConhecimento& codigo){ cout << codigo.CodigoDescricao() << '\n';});
  cout << "\nPressione enter para continuar. \nVai visualizar tabela de engenharia de petróleo:";
  cin.get();

  geradorAreaConhecimento.RecuperarEstado("EngenhariaPetroleo");
  cout << "\nVisualizando a tabela de áreas de conhecimentos associadas ao curso de engenharia de petróleo\n";
  geradorAreaConhecimento.VisualizarTabelaAreaConhecimento();
return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "CGestorAreaConhecimento.h"
#include "CCodigoAreaConhecimento.h"

using namespace std;
// A classe CCodigoAreaConhecimento tem o objetivo de armazenar o código da disciplina e,
// ao mesmo tempo, gerenciar o arquivo que tem a lista de departamentos e códigos usados.
int main() {
  CGestorAreaConhecimento geradorAreaConhecimento;
  std::cout << "\nVisualizando a tabela codigo<->areaDoConhecimento estado atual:\n";
  geradorAreaConhecimento.VisualizarTabelaAreaConhecimento();
  geradorAreaConhecimento.SalvarEstado("1");

  for(int i=0; i<10;i++) {
    CCodigoAreaConhecimento codigo(geradorAreaConhecimento.DefinirAreaConhecimento());
    cout << "\nGerou o codigo : " << codigo.CodigoDescricao();
  }
  geradorAreaConhecimento.RecuperarEstado("EngenhariaPetroleo");
  cout << "\nVisualizando a tabela de áreas de conhecimentos associadas ao curso de engenharia de petróleo\n";
  geradorAreaConhecimento.VisualizarTabelaAreaConhecimento();
return 0;
}

#include <iostream>
//#include <sstream>
#include <limits>
#include "CTabelaCodigoDisciplina.h"

using namespace std;

// Variáveis estáticas, compartilhadas entre objetos.
 std::string CTabelaCodigoDisciplina::caminhoDiretorio = "dados/TabelaCodigoDisciplina/";
 std::string CTabelaCodigoDisciplina::nomeArquivo      = "mapSiglaCodigo-"; // padrão, sem o estado

 std::map<std::string,int> CTabelaCodigoDisciplina::map_ultimoCodigoUsado;

// Implementação dos métodos da classe CTabelaCodigoDisciplina
// Recupera um estado específico. caminhoDiretorio + nomeArquivo + identificadorEstado
void CTabelaCodigoDisciplina::RecuperarEstado(std::string identificadorEstado)
{
    std::string nomeCompleto = caminhoDiretorio + nomeArquivo + identificadorEstado + ".dat";
    std::ifstream arquivoSiglaCodigo (nomeCompleto);
    std::string sigla;
    int ultimoCodigoUsado;
    if(arquivoSiglaCodigo.fail()) {
      cerr << "\nNão conseguiu abrir o arquivo:" << nomeCompleto << " para leitura... encerrando!\n";
      exit(0);
    }
    arquivoSiglaCodigo.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // ignora linha comentário
    while (! arquivoSiglaCodigo.eof() ) {
      arquivoSiglaCodigo >> sigla >> ultimoCodigoUsado;
      map_ultimoCodigoUsado[sigla] = ultimoCodigoUsado;
      // map_ultimoCodigoUsado.insert ( make_pair ( sigla , ultimoCodigoUsado );
      // map_ultimoCodigoUsado.insert ( {sigla , ultimoCodigoUsado} );
    }
}

// Salva um estado específico. caminhoDiretorio + nomeArquivo + "-" + identificadorEstado
void CTabelaCodigoDisciplina::SalvarEstado(std::string identificadorEstado)
{
    std::string nomeCompleto = caminhoDiretorio + nomeArquivo + identificadorEstado + ".dat";
    std::ofstream arquivoSiglaCodigo (nomeCompleto);
    if(arquivoSiglaCodigo.fail()) {
      cerr << "\nNão conseguiu abrir o arquivo:" << nomeCompleto << " para leitura... encerrando!\n";
      exit(0);
    }
    arquivoSiglaCodigo << "#SiglaDoDepartamento #PróximoCódigoVálido\n"; // cabeçalho.
    for( auto& [sigla,codigoNumerico]: map_ultimoCodigoUsado )
      arquivoSiglaCodigo << sigla << ' ' << codigoNumerico << '\n';
    arquivoSiglaCodigo.close(); // opcional, descarrega o buffer e fecha o arquivo.
}

std::string CTabelaCodigoDisciplina::DefinirCodigoDisciplina(std::string siglaDepartamento)
{
    int novoCodigo = ++map_ultimoCodigoUsado[siglaDepartamento];
    if(novoCodigo < 10)
      siglaDepartamento += "-000" ; // LEP-0001 LEP-0009
    else if(novoCodigo < 100)
      siglaDepartamento += "-00"  ; // LEP-0010 LEP-0099
    else if(novoCodigo < 1000)
      siglaDepartamento += "-0"   ; // LEP-0100 LEP-0999
    else
      siglaDepartamento += "-"    ; // LEP-0100 LEP-0999
  return siglaDepartamento +  std::to_string(novoCodigo);
}

void CTabelaCodigoDisciplina::Visualizar()
{
  cout <<"\nMapa com siglas dos departamentos e últimos códigos utilizados\n";
  for( auto& [sigla,codigoNumerico]: map_ultimoCodigoUsado )
    cout << sigla << ' ' << codigoNumerico << '\n';
}

// bool CTabelaCodigoDisciplina::VerificarCodigo(std::string codigoASerVerificado)
// {
//   //..Implementar.
//   // precisa decompor o código, ex: LEP-0011 -> LEP e 11
//   // e verificar se esta no map.
// }

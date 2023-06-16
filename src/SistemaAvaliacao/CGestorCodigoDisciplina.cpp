#include <iostream>
//#include <sstream>
#include <limits>
#include "CGestorCodigoDisciplina.h"

using namespace std;

// Variáveis estáticas, compartilhadas entre objetos.
 std::string CGestorCodigoDisciplina::caminhoDiretorio = "dados/TabelaCodigoDisciplina/";

 std::string CGestorCodigoDisciplina::nomeArquivo      = "mapSiglaCodigo-"; // padrão, sem o estado

 std::map<const std::string,int> CGestorCodigoDisciplina::map_ultimoCodigoUsado;

CGestorCodigoDisciplina::CGestorCodigoDisciplina() {
    if( map_ultimoCodigoUsado.size() == 0 )
      RecuperarEstado();
}

CGestorCodigoDisciplina::CGestorCodigoDisciplina(const std::string identificadorEstado) {
      RecuperarEstado(identificadorEstado);
}

CGestorCodigoDisciplina::~CGestorCodigoDisciplina() {
     SalvarEstado();
}

void CGestorCodigoDisciplina::AdicionarDepartamento()
{
  std::string siglaDepartamento/*, int codigoInicial = 0*/;
  do {
  cout << "\nEntre com a sigla do departamento (3 letras): ";
  getline(cin,siglaDepartamento);
  } while (siglaDepartamento.size() != 3);
  AdicionarDepartamento(siglaDepartamento,0);
}
  // /// Valida o codigo da disciplina (verifica se atende o padrão).
  // // O ideal é verificar na tabela de códigos! Aqui verifica apenas o padrão!
  // bool ValidaCodigo(CCodigoDisciplina& _codigoDisciplina)      {
  //   if ( CVerificaPadrao::AtendePadrao(_codigoDisciplina,"ccc-nnnn" )
  //     std::cout << "\nAtende o padrão.\n";
  //   else
  //     std::cout << "\nNão atende o padrão.\n";
  // }


void CGestorCodigoDisciplina::AdicionarDepartamento(std::string siglaDepartamento, int codigoInicial)
{
  if(map_ultimoCodigoUsado.contains(siglaDepartamento))
    cerr << "\nEste departamento já foi adicionado anteriormente!";
  else {
    map_ultimoCodigoUsado[siglaDepartamento] = codigoInicial;
    cout << "\nDepartamento [" << siglaDepartamento << "] adicionado ao map.";
  }
}

CCodigoDisciplina CGestorCodigoDisciplina::CriarCodigoDisciplina()  {
  VisualizarTabelaDepartamentoUltimoCodigo(); // Mostra a lista de departamentos e códigos usados.
  std::string siglaDepartamento;
  do {
  cout << "\nEntre com a sigla do departamento (3 letras):";
  std::getline(std::cin , siglaDepartamento);
  } while(! map_ultimoCodigoUsado.contains(siglaDepartamento));
  return CriarCodigoDisciplina(siglaDepartamento);
}

//
CCodigoDisciplina CGestorCodigoDisciplina::CriarCodigoDisciplina(std::string siglaDepartamento)
{
  // Se o departamento ainda não existe pede para criar antes de definir o código.
  if(! map_ultimoCodigoUsado.contains(siglaDepartamento)) {
        // AdicionarDepartamento(siglaDepartamento);
    cerr << "\nDepartamento inexistente."
            "\nAntes de criar codigo de disciplina precisa adicionar o departamento."
            "\nVai retornar código padrão.";
    return CCodigoDisciplina(std::string{CCodigoDisciplina::padrao});
    }
  int novoCodigo = ++map_ultimoCodigoUsado[siglaDepartamento];
  if(novoCodigo < 10)
    siglaDepartamento += "-000" ; // LEP-0001 LEP-0009
  else if(novoCodigo < 100)
    siglaDepartamento += "-00"  ; // LEP-0010 LEP-0099
  else if(novoCodigo < 1000)
    siglaDepartamento += "-0"   ; // LEP-0100 LEP-0999
  else
    siglaDepartamento += "-"    ; // LEP-0100 LEP-0999
  siglaDepartamento += std::to_string(novoCodigo);
  return CCodigoDisciplina(siglaDepartamento);
}

CCodigoDisciplina CGestorCodigoDisciplina::RetornarCodigoDisciplinaExistente(const std::string sCodigoDisciplina)  {
  // verificar se a disciplina existe...
  return CCodigoDisciplina(sCodigoDisciplina);
}

void CGestorCodigoDisciplina::VisualizarTabelaDepartamentoUltimoCodigo()
{
  cout <<"\nMapa com siglas dos departamentos e últimos códigos utilizados\n";
  for( auto& [sigla,codigoNumerico]: map_ultimoCodigoUsado )
    cout << sigla << ' ' << codigoNumerico << '\n';
}

// Implementação dos métodos da classe CGestorCodigoDisciplina
// Recupera um estado específico. caminhoDiretorio + nomeArquivo + identificadorEstado
void CGestorCodigoDisciplina::RecuperarEstado(std::string identificadorEstado)
{
    std::string nomeCompleto = caminhoDiretorio + nomeArquivo + identificadorEstado + ".dat";
    std::ifstream arquivoSiglaCodigo (nomeCompleto);
    std::string sigla;
    int ultimoCodigoUsado;
    if(arquivoSiglaCodigo.fail()) {
      cerr << "\nNão conseguiu abrir o arquivo:" << nomeCompleto << " para leitura... encerrando!\n";
      //exit(0); melhorar tratamento erro...deveria repetir pedido estado ou pedir caminho completo para arquivo.
    }
    map_ultimoCodigoUsado.clear(); // Apaga tudo pois vai recuperar do arquivo de disco.
    arquivoSiglaCodigo.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // ignora linha comentário
    while (! arquivoSiglaCodigo.eof() ) {
      arquivoSiglaCodigo >> sigla >> ultimoCodigoUsado;
      map_ultimoCodigoUsado[sigla] = ultimoCodigoUsado;
      // map_ultimoCodigoUsado.insert ( make_pair ( sigla , ultimoCodigoUsado );
      // map_ultimoCodigoUsado.insert ( {sigla , ultimoCodigoUsado} );
    }
}

// Salva um estado específico. caminhoDiretorio + nomeArquivo + "-" + identificadorEstado
void CGestorCodigoDisciplina::SalvarEstado(const std::string identificadorEstado) const
{
    std::string nomeCompleto = caminhoDiretorio + nomeArquivo + identificadorEstado + ".dat";
    std::ofstream arquivoSiglaCodigo (nomeCompleto);
    if(arquivoSiglaCodigo.fail()) {
      cerr << "\nNão conseguiu abrir o arquivo:" << nomeCompleto << " para escrita... encerrando!\n";
      exit(0);
    }
    arquivoSiglaCodigo << "#SiglaDoDepartamento #PróximoCódigoVálido\n"; // cabeçalho.
    for( auto& [sigla,codigoNumerico]: map_ultimoCodigoUsado )
      arquivoSiglaCodigo << sigla << ' ' << codigoNumerico << '\n';
    arquivoSiglaCodigo.close(); // opcional, descarrega o buffer e fecha o arquivo.
}



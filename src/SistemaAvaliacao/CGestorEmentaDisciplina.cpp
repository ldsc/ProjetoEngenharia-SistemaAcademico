#include "CGestorEmentaDisciplina.h"

// Variáveis estáticas, compartilhadas entre objetos.
std::string CGestorEmentaDisciplina::caminhoDiretorio = "dados/EmentaDisciplina/";
//std::string CGestorEmentaDisciplina::nomeArquivo      = "mapCodigoEmenta-"; // padrão, sem o estado

std::map<CCodigoDisciplina,shared_ptr<CGestorEmentaDisciplina> > CGestorEmentaDisciplina::map_codigoDisciplina_spEmentaDisciplina;


CGestorEmentaDisciplina::CGestorEmentaDisciplina() {
  DefinirEmenta();
}

CGestorEmentaDisciplina::~CGestorEmentaDisciplina(){ SalvarEstado(); };

void DefinirEmenta() {
    DefinirCodigoDisciplina();
    DefinirNomeDisciplina();
    DefinirPreRequisito();
    DefinirReferenciaBibliografica();
    DefinirSistemaAvaliacao();
    DefinirConteudoProgramatico();
    DefinirAssunto();
    DefinirVersao();
    SalvarEstado(); // salva a ementa em arquivo de disco
}

void CGestorEmentaDisciplina::DefinirCodigoDisciplina()
{
  codigoDisciplina = CCodigoDisciplina::DefinirCodigo();
  std::cout << "\nCódigo da disciplina definido automaticamente: " << codigoDisciplina;
}

void DefinirNomeDisciplina() {
  std::cout << "\nEntre com o nome da disciplina:";
  std::getline(std::cin , nome);
}

void CGestorEmentaDisciplina::DefinirPreRequisito()
{
  std::cout << "\nA disciplina tem pré-requisitos (s/n):";
  char resp{'s'};
  std::cin.get(resp); std::cin.get();
  if (resp == 'n' or resp == 'N')
    return;
  // CCurso::ListaDisciplinas("");
  // Precisamos da lista de disciplinas... Código e nome
  // Ex: LEP-0001 Fundamentos de Computação
  std::cout << "\nLista de códigos das disciplinas (conteúdo de dados/EmentaDisciplina/)):";
  system("ls dados/EmentaDisciplina/");
  std::string sCodigoDisciplinaPreRequisito;
  CCodigoDisciplina codigo;
  do {
    std::cout << "\nEntre com o código da disciplina pré-requisito (digite ctrl+d para encerrar a entrada):";
    getline(std::cin,sCodigoDisciplinaPreRequisito);
    if(std::cin.good()) {
      codigo.CodigoDisciplina(sCodigoDisciplinaPreRequisito);
      preRequisito.push_back(codigo);
    }
  } while(std::cin.good());
  std::cin.clear();
  std::unique(preRequisito.begin(), preRequisito.end()); // elimina repetições se houver
}

void CGestorEmentaDisciplina::DefinirReferenciaBibliografica()
{
  // CCurso::ListaDisciplinas("");
  // Precisamos da lista de bibliografias se tiver...
  std::string referencia;
  do {
    std::cout << "\nEntre com a referência bibliográfica\
                  \n Autor(es); Titulo; Editora; Edição; Ano; Observações.\
                  \n (digite ctrl+d para encerrar a entrada):";
    getline(std::cin,referencia);
    referenciaBibliografica.push_back(referencia);
  } while(std::cin.good());
  std::cin.clear();
}

void CGestorEmentaDisciplina::DefinirSistemaAvaliacao() {
  int numeroAvaliacoes{};
  ListarTiposAvaliacoes();
  std::cout << "\nEntre com o número de avaliações:";
  std::cin >> numeroAvaliacoes; std::cin.get();
  ETipoAvaliacao tipo{};
  for ( int i = 1; i <= numeroAvaliacoes; i++ ) {
    std::cout << "\nPara a avaliação ["<< i << "], entre com o tipo de avaliação:";
    tipo = MenuSelecaoTipoAvaliacao(); // opção inválida...tratar
    sistemaAvaliacao.push_back( tipo );
  }
}

void CGestorEmentaDisciplina::DefinirConteudoProgramatico(){
  std::cout << "\nEntre com o conteúdo programático (resumo), pressione ctrl+d para encerrar:";
  std::string linha;
  conteudoProgramatico = {};
  do {
    getline(std::cin,linha);
    if ( std::cin.good() )
      conteudoProgramatico += linha;
  } while(std::cin.good());
  std::cin.clear();
}

void CGestorEmentaDisciplina::DefinirAssuntos(){
  int i{1};
  CAssunto assunto_i;
  std::string sAssunto;
  CAssunto::ListarAssuntos();
  do{
    std::cout << "\nEntre com o assunto " << i << " (ctrl+d para encerrar):\n";
    std::getline(cin,sAssunto);
    if(cin.good())
      assunto.push_back(CAssunto{sAssunto});
  } while ( cin.good() );
}

void CGestorEmentaDisciplina::DefinirVersao() {
  int ano{2023};
  int semestre{1};
  std::cout << "\nEntre com o ano da ementa:\n";
  std::cin >> ano;
  std::cout << "\nEntre com o semestre da ementa (1,2,3 - verão):\n";
  std::cin >> semestre;
  versao = {ano,semestre}; // Versão da ementa <Ano,Semestre>
}

// Cria arquivo com a ementa:
// Ex: dados/EmentaDisciplina/LEP-0011-2019-1.dat
// Ex: dados/EmentaDisciplina/LEP-0011-2023-1.dat
void CGestorEmentaDisciplina::SalvarEstado(std::string identificadorEstado )
{
    std::string sVersao = to_string(versao.first) +"-"+ to_string(versao.second);
    std::string caminhoCompleto = caminhoDiretorio + CCodigoDisciplina +"-"+ sVersao + ".dat";
    std::ofstream arquivoEmenta (caminhoCompleto);
    if(arquivoEmenta.fail()) {
      cerr << "\nNão conseguiu abrir o arquivo:" << caminhoCompleto << " para escrita... encerrando!\n";
      exit(0);
    }
    arquivoEmenta << *this;
}

// Precisa receber o nome do arquivo na variável identificadorEstado
// note que não entra a extensão .dat.
void CGestorEmentaDisciplina::RecuperarEstado(std::string identificadorEstado )
{
   constexpr auto max_size = std::numeric_limits<std::streamsize>::max();
   std::string caminhoCompleto = caminhoDiretorio + identificadorEstado + ".dat";
    std::ifstream ementa (caminhoCompleto);
    std::string linha;
    size_t size{};
    ementa.ignore(max_size,'\n'); // ignora #EmentaDisciplina:
    ementa.ignore(max_size,'\n'); // ignora -> codigoDisciplina:
    getline(ementa,linha);
    codigoDisciplina.CodigoDisciplina (linha);
    ementa.ignore(max_size,'\n'); // ignora -> nome
    getline(ementa,nome);
    ementa.ignore(max_size,'\n'); // ignora -> preRequisito:
    ementa >> size;
    preRequisito.resize(size);
    for(size_t i = 0; i < preRequisito.size(); i++) {
      getline(ementa,linha);
      preRequisito[i].CodigoDisciplina(linha);
    }
    ementa.ignore(max_size,'\n'); // ignora -> Referencias bibliográficas
    ementa >> size;
    referenciaBibliografica.resize(size);
    for(size_t i = 0; i < referenciaBibliografica.size(); i++) {
      getline(ementa,referenciaBibliografica[i]);
    }
    ementa.ignore(max_size,'\n'); // ignora -> sistemaAvaliacao (tipo de avaliacao):
    ementa >> size;
    sistemaAvaliacao.resize(size);
    for(size_t i = 0; i < sistemaAvaliacao.size(); i++) {
      getline(ementa,linha);
      sistemaAvaliacao[i] = TipoAvaliacao(linha);
    }
    ementa.ignore(max_size,'\n'); // ignora -> conteudoProgramatico:
    getline(ementa,conteudoProgramatico); //várias linhas? separador??
    ementa.ignore(max_size,'\n'); // ignora -> assuntos:
    ementa >> size;
    assuntos.resize(size);
    for(size_t i = 0; i < assuntos.size(); i++) {
      getline(ementa,assuntos[i]);
    }
    ementa.ignore(max_size,'\n'); // ignora -> versao:
    int ano;
    ementa >> ano;
    char traco;
    ementa >> traco;
    int semestre;
    ementa >> semestre;
    versao = {ano,semestre};
}

std::ostream& operator<<(std::ostream& arquivo, CGestorEmentaDisciplina& ementa) {
    arquivo << "#EmentaDisciplina:\n"
          << "-> codigoDisciplina:\n"
          << codigoDisciplina
          << "\n-> nome:\n" << nome;
          << "\n-> preRequisito:\n"
          << preRequisito.size();
    std::copy(preRequisito.begin(),preRequisito.end(),std::ostream_iterator<CCodigoDisciplina>(arquivo, '\n'))
    arquivo << "\n-> Referencias bibliográficas\n"
           << referenciaBibliografica.size() << '\n';
    std::for_each(referenciaBibliografica.begin(),referenciaBibliografica.end(),[](auto&ref){ arquivo << ref << '\n'; });
    arquivo << "\n-> sistemaAvaliacao (tipo de avaliacao):\n"
          << sistemaAvaliacao.size() << '\n';
    std::for_each(sistemaAvaliacao.begin(),sistemaAvaliacao.end(),[](ETipoAvaliacao&tipo){ arquivo << tipo << '\n'; });
    arquivo << "\n-> conteudoProgramatico:\n"
           << conteudoProgramatico;
           << "\n-> assuntos:\n"
           << assunto.size() << '\n';
    std::copy(assunto.begin(),assunto.end(),std::ostream_iterator<CAssunto>(arquivo, '\n'))
    std::string sVersao = to_string(versao.first) +"-"+ to_string(versao.second);
    arquivo << "\n-> versao:\n" << sVersao;
    return os;
}

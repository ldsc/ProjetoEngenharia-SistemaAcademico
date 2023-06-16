#include <iostream>
#include <string>
#include <limits>
#include <iterator>
#include <utility>
#include <cctype>

#include "ETipoAvaliacao.h"
#include "CEmentaDisciplina.h"
// #include "CGestorCodigoDisciplina.h"
#include "CGestorEmentaDisciplina.h"

static std::string_view tracos {"===================================================="};
// Variáveis estáticas, compartilhadas entre objetos.
//std::string CEmentaDisciplina::caminhoDiretorio = "dados/EmentaDisciplina/";
//std::string CEmentaDisciplina::nomeArquivo      = "mapCodigoEmenta-"; // padrão, sem o estado

// std::map<CCodigoDisciplina,shared_ptr<CEmentaDisciplina> > CEmentaDisciplina::map_codigoDisciplina_spEmentaDisciplina;

// Definição dos métodos da classe.

// CEmentaDisciplina::CEmentaDisciplina(CCodigoDisciplina& _codigo) :  codigoDisciplina (_codigo) {
//   SalvarEstado();
// }
CEmentaDisciplina::CEmentaDisciplina(const std::string& _codigo) :  codigoDisciplina (_codigo) {
  //SalvarEstado(); esta vazia se salvar apaga a que exista!
}

// CEmentaDisciplina::CEmentaDisciplina(const CCodigoDisciplina& _codigo):codigoDisciplina(_codigo) {
//   RecuperarEstado();
// }

CEmentaDisciplina::~CEmentaDisciplina(){
  // Este salvamento esta sendo feito no gesto. Verificar melhor local.
  // if(  ementaAtivaModificada == true) {
  //   std::cout << "\nA ementa " << codigoDisciplina << "\nfoi modificada."
  //             << "\nDeseja salvar (s) ou descartar (d)? ";
  //   char resp{'s'};
  //   std::cin.get(resp); std::cin.get();
  //   if (resp != 'd')
  //     SalvarEstado();
  // };
}

void CEmentaDisciplina::MenuRevisao() {
  char resp = 's';
  while(true) {
  std::cout << "\n<----------------------------------->"
            << "\n<--------Menu Revisão Ementa-------->"
            << "\n<----------------------------------->"
            << "\nVisualizar ementa.................0"
            << "\ndefinir Estado....................1"
            << "\ndefinir Nome......................2"
            << "\ndefinir area do Conhecimento......3"
            << "\ndefinir pre-Requisito.............4"
            << "\ndefinir referencia Bibliografica..5"
            << "\ndefinir sisTema avaliacao.........6"
            << "\ndefinir conteudo Programatico.....7"
            << "\ndefinir Assunto...................8"
            << "\ndefinir verSao....................9"
            << "\nsair do menu de revisão/Quit......q : ";
  std::cin.get(resp); std::cin.get();
  std::cout << "\nSelecionou a opção " << resp
            << "\n<----------------------------------->";
  switch (resp) {
    case 'v':
    case 'V':
    case '0': Visualizar();                     break;
    case 'e':
    case 'E':
    case '1': DefinirEstado();                  break;
    case 'n':
    case 'N':
    case '2': DefinirNomeDisciplina();          break;
    case 'c':
    case 'C':
    case '3': DefinirCodigoAreaConhecimento();  break;
    case 'r':
    case 'R':
    case '4': DefinirPreRequisito();            break;
    case 'b':
    case 'B':
    case '5': DefinirReferenciaBibliografica(); break;
    case 't':
    case 'T':
    case '6': DefinirSistemaAvaliacao();        break;
    case 'p':
    case 'P':
    case '7': DefinirConteudoProgramatico();    break;
    case 'a':
    case 'A':
    case '8': DefinirAssunto();                 break;
    case 's':
    case 'S':
    case '9': DefinirVersao();                  break;
    case 'q':
    case 'Q':
    case '\n':
    default : return;
  }
  }
}

void CEmentaDisciplina::Definir() {
    //DefinirCodigoDisciplina();
    DefinirNomeDisciplina();
    //DefinirCodigoAreaConhecimento(gestorAreaConhecimento);
    DefinirCodigoAreaConhecimento();
    DefinirPreRequisito();
    DefinirReferenciaBibliografica();
    DefinirSistemaAvaliacao();
    DefinirConteudoProgramatico();
    DefinirAssunto();
    DefinirVersao();
    SalvarEstado(); // salva a ementa em arquivo de disco
}

// void CEmentaDisciplina::DefinirCodigoDisciplina()
// {
//   codigoDisciplina = CCodigoDisciplina::DefinirCodigo();
//   std::cout << "\nCódigo da disciplina definido automaticamente: " << codigoDisciplina;
// }

void CEmentaDisciplina::VisualizarEstado(){
  std::cout  << "\nEstado atual da ementa = ";
  switch(estado) {
    case EEstadoEmentaDisciplina::rascunho:
      std::cout << "Rascunho...............1\n"; break;
    case EEstadoEmentaDisciplina::aguardandoAprovacao:
      std::cout << "Aguardando Aprovacao...2\n"; break;
    case EEstadoEmentaDisciplina::ativa:
      std::cout << "Ativa..................3\n"; break;
    case EEstadoEmentaDisciplina::desativa:
      std::cout << "Desativa...............4\n"; break;
  }
}

void CEmentaDisciplina::DefinirEstado() {
  VisualizarEstado();
  int resp;
  std::cout << tracos
            << "\nQual o estado da ementa ?"
               "\nRascunho...............1"
               "\nAguardando Aprovação...2"
               "\nAtiva..................3"
               "\nDesativada.............4 : ";
  std::cin >> resp; std::cin.get();
  estado = static_cast<EEstadoEmentaDisciplina> (resp);
  VisualizarEstado();
  //ementaAtivaModificada = true;
}

void CEmentaDisciplina::DefinirNomeDisciplina() {
  std::cout << tracos << "\nEntre com o nome da disciplina:"
            << "\nNome atual (" << nome << ")";
  std::getline(std::cin , nome);
  // ementaAtivaModificada = true;
}

void CEmentaDisciplina::DefinirCodigoAreaConhecimento() {
  CGestorAreaConhecimento gestorAreaConhecimento;
  DefinirCodigoAreaConhecimento (gestorAreaConhecimento);
}

void CEmentaDisciplina::DefinirCodigoAreaConhecimento(CGestorAreaConhecimento& gestorAreaConhecimento){
  std::cout << tracos << "\nVisualizando a tabela codigo<->areaDoConhecimento:\n";
  gestorAreaConhecimento.VisualizarTabelaAreaConhecimento();
  char resp{'c'};
  std::cout << "\nCódigos atuais =\n";
  for(auto& e: vCodigoAreaConhecimento)
    std::cout << e << '\n';
  std::cout << "\nForneça os novos códigos:\n";
  vCodigoAreaConhecimento.resize(0);
  // ementaAtivaModificada = true;
  while(true) {
    //vCodigoAreaConhecimento.push_back(gestorAreaConhecimento.DefinirAreaConhecimento());
    vCodigoAreaConhecimento.push_back(gestorAreaConhecimento.DefinirAreaConhecimento());
    //std::cout << "\nAdicionou na disciplina a área de conhecimento : " << vCodigoAreaConhecimento.back().CodigoDescricao();
    std::cout << "\nAdicionou na disciplina a área de conhecimento : " << vCodigoAreaConhecimento.back() << '\n';
    // std::cout << "\nContinuar adicionando (c) ou parar (q):";
    // std::cin.get(resp); std::cin.get();
    if (vCodigoAreaConhecimento.back() == "q") {
      vCodigoAreaConhecimento.pop_back(); // retira o código "q"
      return;
      }
  }
}

void CEmentaDisciplina::DefinirPreRequisito(/*CGestorCodigoDisciplina& gestorCodigoDisciplina*/)
{
  std::cout << "\nLista dos pré-requisitos atuais =\n";
  for(auto& e: vPreRequisito)
    std::cout << e << '\n';

  std::cout << tracos << "\nA disciplina tem pré-requisitos (s/n):";
  char resp{'s'};
  std::cin.get(resp); std::cin.get();
  if (resp == 'n' or resp == 'N') {
    vPreRequisito.clear();
    // ementaAtivaModificada = true;
    return;
  }
  // CCurso::ListaDisciplinas("");
  // Precisamos da lista de disciplinas... Código e nome
  // Ex: LEP-0001 Fundamentos de Computação
  std::cout << "\nLista de códigos das disciplinas (conteúdo do diretório: "
            << CGestorEmentaDisciplina::caminhoDiretorio << ").";
  // usar filesystem para listar diretorio...
  std::system((std::string("tree ") + CGestorEmentaDisciplina::caminhoDiretorio).c_str());
  std::string sCodigoDisciplinaPreRequisito;
  do {
    std::cout << "\nEntre com o código da disciplina pré-requisito (digite 'q' para encerrar a entrada): ";
    std::getline(std::cin,sCodigoDisciplinaPreRequisito);
    if(std::cin.good() and sCodigoDisciplinaPreRequisito != "q") {
      // verificar se entrou com código válido...
      vPreRequisito.push_back(
        //CGestorCodigoDisciplina::RetornarCodigoDisciplinaExistente(sCodigoDisciplinaPreRequisito)
        //ou CCodigoDisciplina(sCodigoDisciplinaPreRequisito)
        sCodigoDisciplinaPreRequisito
      );
    }
  } while(sCodigoDisciplinaPreRequisito != "q");
  std::cin.clear();
  std::unique(vPreRequisito.begin(), vPreRequisito.end()); // elimina repetições se houver
  // ementaAtivaModificada = true;
}

void CEmentaDisciplina::DefinirReferenciaBibliografica()
{
  // CCurso::ListaDisciplinas("");
  std::cout << "\nLista das referencias atuais =\n";
  for(auto& e: vReferenciaBibliografica)
    std::cout << e << '\n';
  // Precisamos da lista de bibliografias se tiver...
  vReferenciaBibliografica.clear();
  std::string referencia;
  do {
    std::cout << tracos << "\nEntre com a referência bibliográfica "
              << vReferenciaBibliografica.size()
              << ":\nFormato: Autor(es); Titulo; Editora; Edição; Ano; Observações.\
                  \n(digite 'q' para encerrar a entrada): ";
    std::getline(std::cin, referencia);
    if(std::cin.good() and referencia != "q")
      vReferenciaBibliografica.push_back(referencia);
  } while(referencia != "q");
  std::cin.clear();
  // ementaAtivaModificada = true;
}

void CEmentaDisciplina::DefinirSistemaAvaliacao() {
  std::cout << "\nLista das avaliações atuais =\n";
  for(auto& e: vTipoAvaliacao)
    std::cout << ToString(e) << '\n';

  vTipoAvaliacao.clear();
  int numeroAvaliacoes{};
  std::cout << tracos << "\nEntre com o número de avaliações (mínimo 1): ";
  std::cin >> numeroAvaliacoes; std::cin.get();
  //ListarTiposAvaliacoes();
  ETipoAvaliacao tipo{};
  if( numeroAvaliacoes < 1)
    numeroAvaliacoes = 1; //minimo
  for ( int i = 1; i <= numeroAvaliacoes; i++ ) {
    std::cout << tracos << "\nPara a avaliação ["<< i << "], entre com o tipo de avaliação: ";
    tipo = MenuSelecaoTipoAvaliacao(); // opção inválida...tratar
    vTipoAvaliacao.push_back( tipo );
  }
  // ementaAtivaModificada = true;
}

void CEmentaDisciplina::DefinirConteudoProgramatico(){
  std::cout << "\nConteúdo programático atual =\n";
  std::cout << conteudoProgramatico << '\n';
  std::cout << tracos << "\nEntre com o conteúdo programático (resumo), pressione 'q' para encerrar:\n";
  std::string linha;
  conteudoProgramatico = {};
  do {
    std::getline(std::cin,linha);
    if ( std::cin.good() and linha != "q" )
      conteudoProgramatico += linha + "\n";
  } while(std::cin.good() and linha != "q" );
  std::cin.clear();
  // ementaAtivaModificada = true;
}

void CEmentaDisciplina::DefinirAssunto(){
 std::cout << "\nLista dos assuntos atuais =";
  for(auto& [sAssunto,sCargaHoraria]: vAssunto_CargaHoraria)
    std::cout << "Assunto: " << sAssunto << "\nCarga horária: " << sCargaHoraria << '\n';
  // vai solicitar os assuntos e cargas horárias
  vAssunto_CargaHoraria.clear();
  int i{1};
  std::string sAssunto;
  std::string sCargaHoraria;
  int cargaHoraria{0};
  int cargaHorariaTotal{0};
  //CAssunto::ListarAssuntos();
  while(true) {
    std::cout << tracos << "\nEntre com o assunto " << i++ << " (digite 'q' para encerrar):\n";
    std::getline(std::cin,sAssunto);
    if(sAssunto == "q" or sAssunto == "Q")
      break;//encerra o laço acima. return;
    std::cout << "\nEntre com a carga horária correspondente: ";
    std::getline(std::cin, sCargaHoraria);
    try {
          cargaHoraria = std::stoi(sCargaHoraria);
          if(cargaHoraria == 0) {
            std::cerr << "\nCarga Horária não pode ser zero!";
            continue;
            }
          vAssunto_CargaHoraria.push_back({sAssunto,cargaHoraria});
          cargaHorariaTotal +=  cargaHoraria;
        }
        catch (std::invalid_argument const& ex)
        {
            std::cerr << "CEmentaDisciplina::DefinirAssunto() a carga horária deve ser um número inteiro : "
                      << ex.what() << '\n';
            i--;
        }
    std::cout << "\nCarga Horaria Total = " << cargaHorariaTotal << '\n';
    }
  // ementaAtivaModificada = true;
}

void CEmentaDisciplina::DefinirVersao() {
  std::cout << "\nVersão atual =\n";
  std::cout << "\nAno: " << versao.first
            << "\nSemestre: "<< versao.second << '\n';
  int ano{2023};   // pegar ano corrente do sistema..
  int semestre{1}; // pegar mes do sistema..
  bool entradaOk ;
  do {
   entradaOk = true;
   std::cout << tracos << "\nEntre com o ano da ementa (ex: 2023):\n";
   std::cin >> ano;
   // if(ano > anoCorrente)
   //   continue;
   std::cout << "\nEntre com o semestre da ementa (1,2,3 - verão):\n";
   std::cin >> semestre; std::cin.get();
   if(semestre < 1 or semestre > 3)
     entradaOk = false;
  } while(! entradaOk); //
   versao = {ano,semestre}; // Versão da ementa <Ano,Semestre>
  // ementaAtivaModificada = true;
}

std::ofstream& operator<<(std::ofstream& arquivo, const CEmentaDisciplina& ementa) {
    arquivo << "#Ementa Disciplina: "
          //<< "-> codigoDisciplina:\n"
          << ementa.codigoDisciplina
          << "\n-> nome:\n"
          << ementa.nome
          << "\n-> Área do Conhecimento:\n"
          << ementa.vCodigoAreaConhecimento.size()  << '\n';

   std::copy(ementa.vCodigoAreaConhecimento.begin(),ementa.vCodigoAreaConhecimento.end(),std::ostream_iterator<std::string>(arquivo, "\n"));

    arquivo << "-> Pré-Requisito:\n"
          << ementa.vPreRequisito.size() << '\n';
    std::copy(ementa.vPreRequisito.begin(),ementa.vPreRequisito.end(),std::ostream_iterator<std::string>(arquivo, "\n"));

    arquivo << "-> Referencias Bibliográficas\n"
           << ementa.vReferenciaBibliografica.size() << '\n';

    std::copy(ementa.vReferenciaBibliografica.begin(),ementa.vReferenciaBibliografica.end(),std::ostream_iterator<std::string>(arquivo, "\n"));

    arquivo << "-> Sistema Avaliacao (tipos de avaliações):\n"
          << ementa.vTipoAvaliacao.size() << '\n';
    for( int i = 0; i < ementa.vTipoAvaliacao.size(); i++ )
      arquivo << static_cast<const std::string>(ToString( ementa.vTipoAvaliacao[i]) ) << '\n';

  arquivo << "-> Conteúdo Programatico:\n"
            << std::count(ementa.conteudoProgramatico.begin(),
                          ementa.conteudoProgramatico.end(),
                          '\n') << '\n'
            << ementa.conteudoProgramatico // já tem a quebra de linha

            << "-> Assuntos e Carga Horária:\n"
            << ementa.vAssunto_CargaHoraria.size() << '\n';

    for(int i = 0; i < ementa.vAssunto_CargaHoraria.size(); i++) {
      arquivo << ementa.vAssunto_CargaHoraria[i].first
              << '\n'
              << ementa.vAssunto_CargaHoraria[i].second << '\n';
    }

    std::string sVersao = std::to_string(ementa.versao.first) +"-"+ std::to_string(ementa.versao.second);
    arquivo << "-> versao:\n"
            << sVersao  << '\n' << std::flush;
    return arquivo;
}

// eliminar duplicacao operator <<
std::ostream& operator<<(std::ostream& arquivo, const CEmentaDisciplina& ementa) {
    arquivo << "#Ementa Disciplina: "
          //<< "-> codigoDisciplina:\n"
          << ementa.codigoDisciplina
          << "\n-> nome:\n"
          << ementa.nome
          << "\n-> Área do Conhecimento:\n"
          << ementa.vCodigoAreaConhecimento.size()  << '\n';

   std::copy(ementa.vCodigoAreaConhecimento.begin(),ementa.vCodigoAreaConhecimento.end(),std::ostream_iterator<std::string>(arquivo, "\n"));

    arquivo << "-> Pré-Requisito:\n"
          << ementa.vPreRequisito.size() << '\n';
    std::copy(ementa.vPreRequisito.begin(),ementa.vPreRequisito.end(),std::ostream_iterator<std::string>(arquivo, "\n"));

    arquivo << "-> Referencias Bibliográficas\n"
           << ementa.vReferenciaBibliografica.size() << '\n';

    std::copy(ementa.vReferenciaBibliografica.begin(),ementa.vReferenciaBibliografica.end(),std::ostream_iterator<std::string>(arquivo, "\n"));

    arquivo << "-> Sistema Avaliacao (tipos de avaliações):\n"
          << ementa.vTipoAvaliacao.size() << '\n';
    for( int i = 0; i < ementa.vTipoAvaliacao.size(); i++ )
      arquivo << static_cast<const std::string>(ToString( ementa.vTipoAvaliacao[i]) ) << '\n';

  arquivo << "-> Conteúdo Programatico:\n"
            << std::count(ementa.conteudoProgramatico.begin(),
                          ementa.conteudoProgramatico.end(),
                          '\n') << '\n'
            << ementa.conteudoProgramatico // já tem a quebra de linha

            << "-> Assuntos e Carga Horária:\n"
            << ementa.vAssunto_CargaHoraria.size() << '\n';

    for(int i = 0; i < ementa.vAssunto_CargaHoraria.size(); i++) {
      arquivo << ementa.vAssunto_CargaHoraria[i].first
              << '\n'
              << ementa.vAssunto_CargaHoraria[i].second << '\n';
    }

    std::string sVersao = std::to_string(ementa.versao.first) +"-"+ std::to_string(ementa.versao.second);
    arquivo << "-> versao:\n"
            << sVersao  << '\n' << std::flush;
    return arquivo;
}

// Cria arquivo com a ementa:
// Uma ementa pode estar sendo feita (rascunho), já foi finalizada mas ainda não foi aprovada, já foi aprovada(ativa), foi desativada.
// dados/EmentaDisciplina
// dados/EmentaDisciplina/rascunho/LEP-1523#r
// dados/EmentaDisciplina/aguardandoAprovacao/LEP-1523#f
// dados/EmentaDisciplina/ativa/LEP-1523#a
// dados/EmentaDisciplina/desativa/LEP-1523#d#ano-semestre
void CEmentaDisciplina::SalvarEstado(const std::string identificadorEstado ) const
{
    std::string sVersao = std::to_string(versao.first) +"-"+ std::to_string(versao.second);
    std::string subDiretorio;
    if( estado == EEstadoEmentaDisciplina::rascunho)
      subDiretorio = "rascunho/";
    else if( estado == EEstadoEmentaDisciplina::aguardandoAprovacao)
      subDiretorio = "aguardandoAprovacao/";
    else if( estado == EEstadoEmentaDisciplina::ativa)
      subDiretorio = "ativa/";
    else if( estado == EEstadoEmentaDisciplina::desativa)
      subDiretorio = "desativa/";

    //std::string caminhoCompleto = CGestorEmentaDisciplina::caminhoDiretorio + subDiretorio + codigoDisciplina.CodigoDisciplina() ;
    std::string caminhoCompleto = CGestorEmentaDisciplina::caminhoDiretorio + subDiretorio + codigoDisciplina ;
    if(estado == EEstadoEmentaDisciplina::desativa)
      caminhoCompleto += "#" + sVersao;
    std::ofstream arquivoEmenta (caminhoCompleto + ".dat");
    if(arquivoEmenta.fail()) {
      std::cerr << "\nNão conseguiu abrir o arquivo:" << caminhoCompleto << " para escrita... !\n";
      return;//exit(0);
    }
    arquivoEmenta << *this;
    arquivoEmenta.close();
}

// Precisa receber o nome do arquivo na variável identificadorEstado
// note que não entra a extensão .dat.
// Após leitura de linha com int, precisa ignorar o resto da linha se for usar getline.
// ex: 5'\n' requer ementa >>size; ementa.ignore(max_size,'\n');
void CEmentaDisciplina::RecuperarEstado(const std::string identificadorEstado)
{
    constexpr auto max_size = std::numeric_limits<std::streamsize>::max();
    std::string caminhoCompleto = CGestorEmentaDisciplina::caminhoDiretorio + identificadorEstado + ".dat";
    std::ifstream ementa (caminhoCompleto);
    if(ementa.fail()) {
    }
    std::string linha;
    size_t size{};
    ementa.ignore(max_size,'\n'); // ignora #EmentaDisciplina: LEP-0049
    ementa.ignore(max_size,'\n'); // ignora -> nome:
    std::getline(ementa,nome);
    ementa.ignore(max_size,'\n'); // ignora -> areaDoConhecimento:
    ementa >> size;               // lê o size
    ementa.ignore(max_size,'\n'); // ignora resto da linha
    vCodigoAreaConhecimento.resize(size);
    for(size_t i = 0; i < vCodigoAreaConhecimento.size(); i++) {
      std::getline(ementa,linha);
      vCodigoAreaConhecimento[i] = linha;
    }
    ementa.ignore(max_size,'\n'); // ignora -> preRequisito:
    ementa >> size;
    ementa.ignore(max_size,'\n'); // ignora resto da linha

    vPreRequisito.resize(size);
    for(size_t i = 0; i < vPreRequisito.size(); i++) {
      std::getline(ementa,vPreRequisito[i]);
    }
    ementa.ignore(max_size,'\n'); // ignora -> Referencias bibliográficas
    ementa >> size;
    ementa.ignore(max_size,'\n'); // ignora resto da linha
    vReferenciaBibliografica.resize(size);
    for(size_t i = 0; i < vReferenciaBibliografica.size(); i++) {
      std::getline(ementa,vReferenciaBibliografica[i]);
    }
    ementa.ignore(max_size,'\n'); // ignora -> (tipo de avaliacao):
    ementa >> size;
    ementa.ignore(max_size,'\n'); // ignora resto da linha
    vTipoAvaliacao.resize(size);
    int tipoAvaliacao{};
    for(size_t i = 0; i < vTipoAvaliacao.size(); i++) {
      std::getline(ementa,linha);
      vTipoAvaliacao[i] = ::TipoAvaliacao(linha);
    }
    ementa.ignore(max_size,'\n'); // ignora -> conteudoProgramatico:
    ementa >> size;
    ementa.ignore(max_size,'\n'); // ignora resto da linha
    //conteudoProgramatico = "";
    for(size_t i = 0; i < size; i++) {
          std::getline(ementa,linha);
          conteudoProgramatico += linha + '\n';
    }
    ementa.ignore(max_size,'\n'); // ignora -> assuntos e carga horária:
    ementa >> size;
    ementa.ignore(max_size,'\n'); // ignora resto da linha
    vAssunto_CargaHoraria.resize(size);
    // linha assunto
    // linha cargaHoraria
    std::string assunto;
    int cargaHoraria;
    for(size_t i = 0; i < vAssunto_CargaHoraria.size(); i++) {
      getline(ementa,assunto);
      ementa >> cargaHoraria;
      ementa.ignore(max_size,'\n'); // ignora resto da linha
      vAssunto_CargaHoraria[i] = {assunto,cargaHoraria};
    }
    ementa.ignore(max_size,'\n'); // ignora -> versao:
    int ano;
    ementa >> ano;
    char traco;
    ementa.get(traco);
    int semestre;
    ementa >> semestre;
    versao = {ano,semestre};
}

// std::ostream& operator<< (std::ostream& arquivo,std::pair<std::string,int> p) {
//    arquivo << p.first << '\n' << p.second;
//    return arquivo;
// }

void CEmentaDisciplina::CaminhoDiretorio(const std::string _caminhoDiretorio) {
 CGestorEmentaDisciplina::caminhoDiretorio =  _caminhoDiretorio;
}

const std::string  CEmentaDisciplina::CaminhoDiretorio() const {
  return CGestorEmentaDisciplina::caminhoDiretorio;
}

void CEmentaDisciplina::NomeArquivo(const std::string _nomeArquivo) {
 // não faz nada
}

const std::string  CEmentaDisciplina::NomeArquivo() const  {
 // não faz nada
  return "nãoTemNome";
}



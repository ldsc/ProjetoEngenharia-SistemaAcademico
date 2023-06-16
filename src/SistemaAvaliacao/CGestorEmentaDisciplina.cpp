#include <filesystem>
#include "CGestorEmentaDisciplina.h"
#include "CGestorCodigoDisciplina.h"

namespace fs = std::filesystem;

// Variáveis estáticas, compartilhadas entre objetos.
std::string CGestorEmentaDisciplina::caminhoDiretorio = "dados/EmentaDisciplina/";
//std::string CGestorEmentaDisciplina::nomeArquivo      = "mapCodigoEmenta-"; // padrão, sem o estado

//std::map<CCodigoDisciplina,shared_ptr<CGestorEmentaDisciplina> > CGestorEmentaDisciplina::map_codigoDisciplina_spEmentaDisciplina;

CGestorEmentaDisciplina::CGestorEmentaDisciplina() {
}

CGestorEmentaDisciplina::~CGestorEmentaDisciplina(){
}

void CGestorEmentaDisciplina::Menu() {
  char resp = 's';
  do {
  std::cout << "\n<---------------------------------->"
            << "\n<------ Menu Gestor Ementas ------->"
            << "\n<---------------------------------->"
            << "\n<---Geral--->"
            << "\n Listar ementas.................1"
            << "\n criar Nova ementa..............2"
            << "\n Carregar ementa do disco.......3";
  if(ementa != nullptr )
  std::cout << "\n<--- Ementa disciplina " << ementa->CodigoDisciplina() << " --->"
            << "\n Definir.............4"
            << "\n Revisar.............5"
            << "\n Ativar..............6"
            << "\n desaTivar...........7"
            << "\n Visualizar..........8"
            << "\n Salvar..............9";
  std::cout << "\nSair/Quit............q : ";
  std::cin.get(resp); std::cin.get();
  std::cout << "\nSelecionou a opção : " << resp
            << "\n<---------------------------------->\n";
  if( resp == 'q' or resp == 'Q')
    return;
  // else if(ementa == nullptr and resp != '1' and resp != '2' and resp != '3') {
  //   std::cerr << "\nPrecisa criar ou carregar a ementa antes de manipular a mesma.";
  //   continue; //resp = 100;
  //   }
  switch (resp) {
    case 'l': ListarEmentas();        break;
    case 'L': ListarEmentas();        break;
    case '1': ListarEmentas();        break;
    case 'n':
    case 'N':
    case '2': CriarEmenta();          break;
    case 'c':
    case 'C':
    case '3': CarregarEmentaDisco();  break;
    case 'd':
    case 'D':
    case '4': DefinirEmenta();        break;
    case 'r':
    case 'R':
    case '5': RevisarEmenta();        break;
    case 'a':
    case 'A':
    case '6': AtivarEmenta();         break;
    case 't':
    case 'T':
    case '7': DesativarEmenta();      break;
    case 'v':
    case 'V':
    case '8': VisualizarEmenta();     break;
    case 's':
    case 'S':
    case '9': SalvarEmenta();         break;
    default:
              std::cerr << "\nOpção inválida!";
  }
  } while (resp != 'q' or resp != 'Q');
}

// estado = rascunho
void CGestorEmentaDisciplina::CriarEmenta() {
    VerificarSeEParaSalvar();
    // Elimina a antiga para a qual apontava.
    ementa.reset();
    // Gera CCodigoDisciplina nova e passa para construtor ementa
    // CriarCodigoDisciplina() vai pedir o nome do departamento.
    //ementa = std::make_shared<CEmentaDisciplina> (CGestorCodigoDisciplina::CriarCodigoDisciplina());
    auto codigoDisciplina = CGestorCodigoDisciplina::CriarCodigoDisciplina();
    ementa = std::make_shared<CEmentaDisciplina> (codigoDisciplina.ToString());
    std::cout << "\nCriou ementa nova, vazia, estado rascunho, código: "
              << ementa->CodigoDisciplina() << '\n';
    ementaAtivaModificada = true;
}

// estado = rascunho
void CGestorEmentaDisciplina::CarregarEmentaDisco() {
std::cerr << "\nCGestorEmentaDisciplina::CarregarEmentaDisco()";
  VerificarSeEParaSalvar();
  // Elimina a antiga para a qual apontava.
  ementa.reset();

  ListarEmentas();
  std::cout << "\nInforme o nome do arquivo com a ementa (ex: rascunho/LEP-1523, aguardandoAprovacao/LEP-1523, ativa/LEP-1523 inativa/LEP-1523): ";
  std::string nomeArquivo;
  std::getline(std::cin, nomeArquivo); // LEP-1523-ano-versao LEP-1523-2023-1
  try {
  // Cria ementa vazia
  std::string sCodigoDisciplina = nomeArquivo.substr(nomeArquivo.size()-8,nomeArquivo.size());
  ementa = std::make_shared<CEmentaDisciplina> (CGestorCodigoDisciplina::RetornarCodigoDisciplinaExistente(sCodigoDisciplina));
  // carrega do disco
  std::cout << "\nVai recuperar do disco a disciplina " << ementa->CodigoDisciplina() << "\n";
  ementa->RecuperarEstado(nomeArquivo);
  ementaAtivaModificada = true;
  }
  catch(...) {
    std::cerr << "\nFalha no carregamento de ementa do disco!\n";
  }
}

// estado = rascunho, pede todos os dados
void CGestorEmentaDisciplina::DefinirEmenta() {
  ementaAtivaModificada = true;
  ementa->Definir();
}

// estado = rascunho
void CGestorEmentaDisciplina::RevisarEmenta() {
  //CarregarEmentaDisco();
  ementaAtivaModificada = true;
  ementa->MenuRevisao();
}

// estado = ativa
void CGestorEmentaDisciplina::AtivarEmenta() {
  ementaAtivaModificada = true;
  ementa->estado =  EEstadoEmentaDisciplina::ativa;
}

// estado = inativa
void CGestorEmentaDisciplina::DesativarEmenta() {
  ementaAtivaModificada = true;
  ementa->estado =  EEstadoEmentaDisciplina::desativa;
}

// Listar os diretórios
void CGestorEmentaDisciplina::ListarEmentas() {
// listar o diretorio
 std::cout << "\nConteúdo do diretório " << caminhoDiretorio;
 for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{caminhoDiretorio})
    {
        std::cout << '\n' << dir_entry ;
    }
 std::cout << '\n';
}

void CGestorEmentaDisciplina::VisualizarEmenta() {
 std::cout << *ementa;
}

void CGestorEmentaDisciplina::SalvarEmenta(){
 ementa->SalvarEstado();
 ementaAtivaModificada = false;
}

void CGestorEmentaDisciplina::VerificarSeEParaSalvar() {
  if(ementa != nullptr) {
    std::cout << "\nA ementa, código : " << ementa->CodigoDisciplina()
              << "\nfoi alterada, deseja salvar (s/n)? ";
    char resp = 'n';
    std::cin.get(resp); std::cin.get();
    if(resp != 'n')// or resp == 'S')
      SalvarEmenta();
    }
}

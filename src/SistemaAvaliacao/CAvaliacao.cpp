#include "CAvaliacao.h"

CAvaliacao::CAvaliacao(std::shared_ptr<CTurma> _turma): turma(_turma){}

CAvaliacao::~CAvaliacao(){}

void CAvaliacao::FormularAvaliacao()
{
  DefinirProfessores();
  DefinirDatas();
  DefinirLogomarcaTurma();
  DefinirInstrucoes();
  DefinirProblema();
  if(lerPerguntasDisco)
    LerPerguntasDisco(std::string nomeArquivo);
  else
    DefinirPerguntas();
  pathArquivo = ...
  SaidaDados(pathArquivo);
}

void CAvaliacao::DefinirProfessores(){
 do {
   turma->ListarProfessores(); // mostra id e nome
   int id{};
   std::cout<< "\nEntre com o id do professor (0 para sair): ";
   std::cin >> id; std::cin.get();
   // se estiver na lista adiciona
   for(int i=0; i < turma->vProfessor.size(); i++) {
      if(turma->vProfessor[i].Id() == id) {
           professor.Id(id);
           vProfessor.push_back(professor);
           break; // encerra o for pois esta na lista
      }
  } while( id != 0);
}

void CAvaliacao::DefinirDatas(){
  std::cout << "\nEntre com a dataInicio: ";
  std::getline(std::cin,dataInicio);
  std::cout << "\nEntre com a dataEntrega (pressione enter se for igual a dataInicio): ";
  std::getline(std::cin,dataEntrega);
  if( dataEntrega.size() <= 0 )
    dataEntrega = dataInicio;
}

void CAvaliacao::DefinirLogomarcaTurma()
{
  cout << "\nCódigo turma:    " << turma.CodigoTurma()
       << "\nNome turma:      " << turma.ementa.NomeDisciplina()
       << "\nCoordenador:     " << turma.coordenador->Nome()
       << "\nData início:     " << dataInicio
       << "\nData entrega:    " << dataEntrega
       << "\nNomeAluno:       "   << "______________________________________"
       << "\nDia que entregou: ______________________________________" // entregou no prazo?
}

void CAvaliacao::DefinirInstrucoes(std::string _instrucoes)
{
  if ( _instrucoes == "" ) {
    instrucoes.clear();
    cout << "\nEntre com as instruções, digite \"q\" para encerrar:\n";
    std::string linha{};
    do {
       getline(std::cin, linha);
       instrucoes += linha;

       } while ( linha != "q" );
    }
  else
    instrucoes = _instrucoes;
}

// repete código acima, pense em criar função auxiliar
void CAvaliacao::DefinirProblema(std::string _escopo = {})
{
  if ( problema.escopo == "" ) {
    problema.escopo.clear();
    cout << "\nEntre com o escopo do problema, digite \"q\" para encerrar:\n";
    std::string linha{};
    do {
       getline(std::cin, linha);
       problema.escopo += linha;

       } while ( linha != "q" );
    }
  else
    problema.escopo = _escopo;
}

// Método chamado quando as perguntas estão num arquivo de disco, cada linha uma pergunta.
void CAvaliacao::LerPerguntasDisco(std::string nomeArquivo)
{
  ifstream arquivoPerguntas(nomeArquivo);
  if ( arquivoPerguntas.fail() ) {
    cerr << "\nFalha ao abrir o arquivo com as perguntas : " << nomeArquivo;
    return;
  }
...le as perguntas do disco.
formato arquivo
/*
n -> número de perguntas
#start 1
pergunta
#end
pesoPergunta
#start 2
pergunta
asdasd
asdasd
#end
pesoPergunta
#start 3
pergunta
#end
pesoPergunta
*/
}

void CAvaliacao::DefinirPerguntas() {
  cout << "\nEntre com o número de perguntas: ";
  int n = 0;
  cin >> n; cin.get();
  pergunta.resize(n);
  for( size_t i = 0; i < pergunta.size(); i++ ) {
    if( pergunta[i] != "") {
      cout << "\nA pergunta  " << i+1 << " é o seguinte:"
	   << "\n" << pergunta[i];
      cout << "\nDeseja manter (m) ou atualizar (a)? ";
      char resp{'m'};
      cin >> resp; cin.get();
      if( resp == 'a' or resp == 'A')
	    AdicionarPergunta( i, pergunta[i] );
    }
    else
      	AdicionarPergunta( i, pergunta[i] );
  }
}

void CAvaliacao::AdicionarPergunta(int i, std::string _pergunta)
{
  if( _pergunta == "" ) {
    cout << "\nEntre com a pergunta, use  \"q\" para encerrar:";
    std::string linha{};
    while(true) {
      getline(cin, linha);
      if( linha != "q" )
         _pergunta += linha;
    };
    }
  else
    pergunta[i] = _pergunta ;
}

void CAvaliacao::VerificarIntegridadeAvaliacao()
{
  double pesoAcumulado = std::accumulate(pesoPergunta.begin(), pesoPergunta.end());
  if (  pesoAcumulado > 10  or pesoAcumulado < 10)
    cout << "\nSomatório dos pesos acima de 10 ou abaixo de 10. Corrigindo pesos para somatório ficar igual a 10.";
    for_each(pesoPergunta.begin(), pesoPergunta.end(), [](double& p)
        { p = 10.0*p / pesoAcumulado; });
}

void CAvaliacao::SaidaDados(std::ostream& out)
{
  ...abre arquivo e salva dados da prova...
}

void CAvaliacao::GerarRespostaPadrao()
{ // verificar a associacação com a resposta padrão.
  respostaPadrao.LerAvaliacao();      // mostra toda a avaliação.
  respostaPadrao.ResponderPerguntas();// pede a resposta de cada pergunta.
  respostaPadrao.Salvar(); // salva
}

//aqui

void CAvaliacao::Imprimir(int numeroCopias)
{
  if(numeroCopias == 0)
    std::cout << "\nInforme o número de cópias: ";
  std::cin >> numeroCopias; std::cin.get();
  //  ...comando para imprimir de acordo com plataforma...
}

// Se for online usa mecanismos de envio.
// Precisa acessar a lista de alunos da turma.
void CAvaliacao::DistribuirAvaliacao()
{
  std::cout << "\nEntregar as avaliações para os alunos/alunas.";
}

// void CAvaliacao::ReinicializarAAvalicao()
// {
//   vProfessor.resize(0);
//   dataInicio = dataFim = instrucoes = "";
//   problema = CProblema;
//   pergunta.resize(0);
//   respostaPadrao = CRespostaPadrao;
//   avaliacaoFinal = false;
// }

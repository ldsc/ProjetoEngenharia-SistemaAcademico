#include "CAvaliacao.h"

CAvaliacao::CAvaliacao()
{
  //initAttributes();
}

CAvaliacao::~CAvaliacao()
{
}

void CAvaliacao::SaidaDados(std::ostream& out)
{
}

void CAvaliacao::AdicionarLogomarcaTurma()
{
  cout << '\n' << turma.CodigoTurma()
       << '\n' << turma.ementa.NomeDisciplina()       
       << '\n' << turma.coordenador->Nome()
       << '\n' << dataInicio
       << '\n' << dataEntrega
       << '\n' << "Aluno: ______________________________________"
       << '\n' << "Dia que entregou: ______________________________________" // entregou no prazo?
}

void CAvaliacao::AdicionarInstrucoes(string _instrucoes) const
{
  if ( _instrucoes == "" ) {
    cout << "\nEntre com as instruções, use a linha \"end\" para encerrar:";
    string linha{};
    while(true) {
      getline(cin, linha);
      if( linha != "end" )
	instrucoes += linha;
    };
    }
  else
    instrucoes = _instrucoes;
}
// repete código acima, pense em criar função auxiliar
void CAvaliacao::AdicionarProblema(CProblema problema)
{
  if( problema.escopo == "" ) {
    cout << "\nEntre com as instruções, use a linha \"end\" para encerrar:";
    string linha{};
    while(true) {
      getline(cin, linha);
      if( linha != "end" )
	instrucoes += linha;
    };
    }
  else
    instrucoes = _instrucoes;
}

// static
// Método chamado quando as perguntas estão num arquivo de disco, cada linha uma pergunta.
void CAvaliacao::LerPerguntasDisco(string nomeArquivo)
{
  ifstream arquivoPerguntas(nomeArquivo);
  if ( arquivoPerguntas.fail() ) {
    cerr << "\nFalha ao abrir o arquivo com as perguntas : " << nomeArquivo;
  }
  // deseja adicionar as perguntas manualmente?...
  // chamar AdicionarPergunta()
}

void CAvaliacao::DistribuirAvaliacao()
{
  cout << "\nEntregar as avaliações para os alunos/alunas.";
}

void CAvaliacao::AdicionarPergunta(int i, string _pergunta)
{
  if( _pergunta == "" ) {
    cout << "\nEntre com a pergunta, use a linha \"end\" para encerrar:";
    string linha{};
    while(true) {
      getline(cin, linha);
      if( linha != "end" )
	_pergunta += linha;
    };
    }
  else
    pergunta[i] = _pergunta ;
}

void CAvaliacao::FormularAvaliacao()
{
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

void CAvaliacao::GerarRespostaPadrao()
{
  respostaPadrao.LerAvaliacao();
  respostaPadrao.ResponderPerguntas();
}

void CAvaliacao::VerificarIntegridadeAvaliacao()
{
  double pesoAcumulado = std::accumulate(pesoPergunta.begin(), pesoPergunta.end());
  if (  pesoAcumulado > 10 )
    cout << "\nSomatório dos pesos acima de 10. Corrigindo pesos.";
  for_each(pesoPergunta.begin(), pesoPergunta.end(), [](double& p)
        { p = 10.0*p / pesoAcumulado; });
}

void CAvaliacao::Imprimir(int numeroCopias)
{
  ...comando para imprimir de acordo com plataforma...
}

void CAvaliacao::InitAttributes()
{
  professor.resize(0);
  dataInicio = dataFim = instrucoes = "";
  problema = CProblema;
  pergunta.resize(0);
  respostaPadrao = CRespostaPadrao;
  avaliacaoFinal = false;
}

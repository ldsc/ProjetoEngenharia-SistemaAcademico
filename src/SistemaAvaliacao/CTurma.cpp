#include "CTurma.h"

CTurma::CTurma(string ano, string semestre, string _codigoDisciplina="", int id = 1)
{
  cout << "\nEntre com o código da disciplina (ex: LEP-0012):";
  string codigoDisciplina;
  getline(cin, codigoDisciplina);

  cout << "\nEntre com os dados do coordenador da disciplina:";
  cin >> coordenador;

  CProfessor professor_i;
  int i = 1;
  do {
    cout << "\nEntre com os dados do professor " << i++ << " (ctrtl+d para encerrar) :";
    cin >> professor_i;
    professor.push_back(professor_i);
  } while(cin.good());
  cin.clear();
  //std::vector<CAluno> aluno; alunos definidos posteriormente, na matrícula

  cout << "\nEntre com a sala da turma:";
  getline(cin,sala);

  cout << "\nEntre com a hora da aula da turma:";
  getline(cin,hora);

  // idealmente deveria gerar automaticamente
  cout << "\nEntre com o identificador da turma (1,2,3,4,...):";
  cin >> id; cin.get();

  cout << "\nEntre com o número limite de alunos:";
  cin >> limiteAlunos; cin.get();

  // Definindo o codigoTurma: 2023-2-LEP-0032-T1
  codigoTurma = ano + "-" + semestre + "-" + codigoDisciplina + "-T" + to_string(id);
  cout << "\nCriada a turma: " << codigoTurma << '\n';
}

CTurma::~CTurma()
{
  cout << "\nFinalizada/destruída a turma: " << codigoTurma << '\n';
}


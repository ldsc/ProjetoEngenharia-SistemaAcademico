#ifndef CTurma_H
#define CTurma_H

#include <string>
#include <vector>
#include "CAluno"
#include "CProfessor"
#include "CSistemaAvaliacao"

/// class CTurma, representa uma turma de uma dada disciplina.
/// Note que uma disciplina pode ter várias turmas, inclusive no mesmo semestre.
class CTurma
{
private:
  std::string codigoDisciplina; // permite acessar a ementa
  std::shared_ptr<CProfessor> coordenador;
  std::vector<shared_ptr<CProfessor>> professor;
  std::string sala;
  std::string hora;
  // Uma mesma disciplina pode ter várias turmas, inclusive com o mesmo coordenador e
  // mesma lista de professores e ementa, muda a lista de alunos e a sala pode ser a
  // mesma ou outra.
  int id;
  int numeroMaximoAlunos;
  // Uma mesma disciplina pode ter várias turmas, inclusive com o mesmo coordenador e
  // mesma lista de professores e ementa, normalmente muda a sala, a hora e o id.
  /// O codigoTurma é dado por: ano + "-" + semestre + "-" + codigoDisciplina + "-T" + to_string(id);
  std::string codigoTurma;
  CSistemaAvaliacao sistemaAvaliacao;
  std::vector<CAluno> aluno;

public:
  /// Construtor.
  CTurma(string ano, string semestre, string _codigoDisciplina="", int id = 1);

  /// Destrutor.
  virtual ~CTurma();

  /// O código da turma é gerado a partir do código da ementa(ex: LEP1732),
  /// do ano(2023), do semestre letivo(1/2/3), e do id da turma, turma 1, turma 2...
  /// @return string
  //std::string DefinirCodigoTurma(){};

  /// Se ainda não esta no vetor de professores adiciona.
  /// @param  professor
  void AdicionarProfessor(std::shared_ptr<CProfessor> _professor)
  { if(binary_search (professor.begin(), professor.end(), _professor) == false);
      professor.push_back(_professor);
  }

  /// @return bool
  /// @param  aluno 
  bool MatricularAluno(std::shared_ptr<CAluno> _aluno)
  {
   if(aluno.size() <= numeroMaximoAlunos && binary_search(aluno.begin(), aluno.end(), _aluno) == false)
     aluno.push_back(_aluno);
     return 1;
     }
   else {
     cout << "\nTurma sem vagas!\n";
     return 0;
   }
  }

  /// Informações sobre a aula.
  void Aula()
  { cout << "\nProfessores ministrando aulas...instruções podem depender da sala..";
  }

  /// @param   
  void Coordenador(std::shared_ptr< CProfessor > _coordenador)
  {
    coordenador = _coordenador;
  }
  /// @return CProfessor
  std::shared_ptr< CProfessor > Coordenador()
  {
   return coordenador;
  }
  /// @param  prof 
  void Professor(std::vector<std::shared_ptr<CProfessor> > _professor)
  {
    professor = _professor;
  }

  /// @return std::vector< std :: shared_ptr < CProfessor > >
  std::vector<std::shared_ptr<CProfessor> > Professor()
  {
    return professor;
  }

  /// @param  alu 
  void Aluno(std::vector< std::shared_ptr<Aluno> > _aluno)
  {
    aluno = _aluno;
  }

  /// @return std::vector< std :: shared_ptr < Aluno > >
  std::vector< std::shared_ptr<Aluno> > Aluno()
  { return aluno;
  }

  // Dica: a ementa disciplina deve ser igual ao codigo disciplina; representar também os arquivos de disco com as ementas.
  /// Mostra a ementa.
  /// @param  value
  void Ementa()
  {
    ifstream arquivoEmenta(std::string("ementas/") + codigoDisciplina + ".txt");
    string linha;
    while(!arquivoEmenta.eof()) {
      getline(arquivoEmenta,linha);
      cout << linha << '\n';
    }
  }

  /// @return CEmentaDisciplina
  CEmentaDisciplina Ementa()
  {
    CEmentaDisciplina ementa(codigoDisciplina);
    return ementa;
  }

  /// @param  sa 
  void Sala(string sa)
  { sala = sa;
  }

  /// @return string
  std::string Sala()
  { return sala;
  }

  /// @param  sa
  void Hora(string _hora)
  { hora = _hora;
  }

  /// @return string
  std::string Hora()
  { return hora;
  }

  /// @param sa
  void SistemaAvaliacao(CSistemaAvaliacao sa)
  { sistemaAvaliacao = sa;
  }

  /// @return CSistemaAvaliacao
  CSistemaAvaliacao SistemaAvaliacao()
  {
    return sistemaAvaliacao;
  }

  /// Set the value of id
  /// Uma mesma disciplina pode ter várias turmas, inclusive com o mesmo coordenador e
  /// mesma lista de professores e ementa, muda alista de alunos e a sala pode ser a
  /// mesma ou outra.
  /// @param value the new value of id
  void Id(int value)
  {
    id = value;
  }

  /// Get the value of id
  /// @return the value of id
  int Id()
  {
    return id;
  }

  // /// Set the value of codigoTurma
  // /// Uma mesma disciplina pode ter várias turmas, inclusive com o mesmo coordenador e
  // /// mesma lista de professores e ementa, muda a lista de alunos e a sala pode ser a
  // /// mesma ou outra. Note que o código da turma é gerado externamente.
  // /// @param value the new value of codigoTurma
  // void CodigoTurma(string value)
  // {
  //   codigoTurma = value;
  // }

  /// Get the value of codigoTurma
  /// @return the value of codigoTurma
  std::string CodigoTurma()
  {
    return codigoTurma;
  }
};
#endif // CTurma_H

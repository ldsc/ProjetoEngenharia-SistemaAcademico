#ifndef CTurma_H
#define CTurma_H

#include <string>
#include <vector>
#include <memory>
/// Representa uma turma de uma dada disciplina.
/// Note que uma disciplina pode ter várias turmas, inclusive no mesmo semestre.
class CTurma
{
private:
  // Attributes
  /// Ponteiro compartilhado para o professor coordenador
  std::shared_ptr<CProfessor> coordenador;
  /// Vetor com a lista de professores da disciplina, o primeiro da lista é o coordenador.
  std::vector<std::shared_ptr<CProfessor>> professor;
  /// Vetor com a lista de alunos
  std::vector<std::shared_ptr<CAluno>> aluno;
  /// Acesso a dados da ementa da disciplina.
  // Note que o código da disciplina tem, no início, o código da ementa, se as ementas tiverem numa base de dados poderia ler diretamente daqui esta base de dados. Neste caso armazenaria aqui o acesso a tabela com os dados das ementas.
  std::shared_ptr<CEmentaDisciplina> ementa;
  /// Note que a sala é um endereço físico, poderíamos ter uma tabela com todos os endereços de todas as salas, e um id_sala seria um identificador para acesso a esta informação. Aqui entraria o int id_sala e não string sala.
  string sala;
  // Uma mesma disciplina pode ter várias turmas, inclusive com o mesmo coordenador e mesma lista de professores e ementa, muda a lista de alunos e a sala pode ser a mesma ou outra. Note que o código da turma é gerado externamente.
  string codigoTurma;
  CSistemaAvaliacao sistemaAvaliacao;

  // Métodos
public:
  /// Constructors
  CTurma::CTurma(){}
  /// Destructors
  CTurma::~CTurma(){}

  /**
   * Set the value of coordenador
   * @param value the new value of coordenador
   */
  void Coordenador(std::shared_ptr<CProfessor>>  coord)  { coordenador = coord; }

  /**
   * Get the value of coordenador
   * @return the value of coordenador
   */
  CProfessor Coordenador()  {    return coordenador;  }

  /**
   * Set the value of professor
   * @param value the new value of professor
   */
  void Professor(std::vector<std::shared_ptr<CProfessor>>  prof)   {    professor = prof;  }

  /**
   * Get the value of professor
   * @return the value of professor
   */
  std::vector<std::shared_ptr<CProfessor>> Professor()  {   return professor;  }

  /// Adiciona novo professor no vetor de professores
  void AdicionarProfessor(std::shared_ptr<CProfessor> novoProfessor ) { professor.push_back(novoProfessor); }

  /**
   * Set the value of aluno
   * @param value the new value of aluno
   */
  void Aluno(std::vector<std::shared_ptr<Aluno>> alu)  {   aluno = alu;  }

  /**
   * Get the value of aluno
   * @return the value of aluno
   */
  std::vector<std::shared_ptr<Aluno>> Aluno()  {   return aluno;  }

  /**
   * Set the value of ementa
   * @param value the new value of ementa
   */
  void Ementa(CEmentaDisciplina value)  {    ementa = value;  }

  /**
   * Get the value of ementa
   * @return the value of ementa
   */
  CEmentaDisciplina Ementa()  {    return ementa;  }

  /**
   * Set the value of sala
   * @param value the new value of sala
   */
  void Sala(string sa)  {    sala = sa;  }

  /**
   * Get the value of sala
   * @return the value of sala
   */
  string Sala()  {    return sala;  }

  /**
   * Set the value of sistemaAvaliacao
   * @param value the new value of sistemaAvaliacao
   */
  void SistemaAvaliacao(CSistemaAvaliacao sa)  {    sistemaAvaliacao = sa;  }

  /**
   * Get the value of sistemaAvaliacao
   * @return the value of sistemaAvaliacao
   */
  CSistemaAvaliacao SistemaAvaliacao()  {    return sistemaAvaliacao;  }

  /// Representa uma aula.
  /// Deve ter um conteúdo associado (lista assuntos) e referencias para materiais externos.
  void Aula() {};

  /// Veja no google classroom exemplo de conteúdo associado a uma Atividade.
  /// Tem Explicação, uma lista de links para materiais externo, critério de avaliação, data entrega atividade.
  void Atividade();


};
#endif // CTurma_H

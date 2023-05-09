
#ifndef CAVALIACAOTURMA_H
#define CAVALIACAOTURMA_H

#include "CAvaliacao.h"

#include string
#include vetor



/**
  * class CAvaliacaoTurma
  * Classe de avaliacao da disciplina, contem vetor com avaliacoes.
  */

class CAvaliacaoTurma : public CAvaliacao
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  CAvaliacaoTurma();

  /**
   * Empty Destructor
   */
  virtual ~CAvaliacaoTurma();



  /**
   * Solicita dados iniciais da disciplina.
   */
  void EntradaDados()
  {
  }


  /**
   * Avalia a disciplina, notas dadas pelos alunos.
   */
  void Avaliar()
  {
  }


  /**
   * Calcula a media das notas dadas pelos alunos.
   */
  void Media()
  {
  }


  /**
   * Gera dados para gr�fico e Plota resultados.
   */
  void Plotar() const
  {
  }


  /**
   * @return string
   */
  string Nome() const
  {
  }


  /**
   * Sa�da dos dados do objeto para ostream
   * @param  out
   */
  void SaidaDados(std::ostream& out)
  {
  }

private:
  // Private attributes
  //  

  // Classe de avaliacao da disciplina, contem vetor com avaliacoes.
  // (< Nome do professor)
  string nomeProfessor;
  // < Nome da disciplina
  string nomeDisciplina;
  // < Cada aluno uma avaliacao
  std::vector< CAvaliacao > aluno;
  // < Vetor com as medias das avaliacoes de cada pergunta
  std::vector< double > media;

  // Private attribute accessor methods
  //  


  /**
   * Set the value of nomeProfessor
   * Classe de avaliacao da disciplina, contem vetor com avaliacoes.
   * (< Nome do professor)
   * @param value the new value of nomeProfessor
   */
  void setNomeProfessor(string value)
  {
    nomeProfessor = value;
  }

  /**
   * Get the value of nomeProfessor
   * Classe de avaliacao da disciplina, contem vetor com avaliacoes.
   * (< Nome do professor)
   * @return the value of nomeProfessor
   */
  string getNomeProfessor()
  {
    return nomeProfessor;
  }

  /**
   * Set the value of nomeDisciplina
   * < Nome da disciplina
   * @param value the new value of nomeDisciplina
   */
  void setNomeDisciplina(string value)
  {
    nomeDisciplina = value;
  }

  /**
   * Get the value of nomeDisciplina
   * < Nome da disciplina
   * @return the value of nomeDisciplina
   */
  string getNomeDisciplina()
  {
    return nomeDisciplina;
  }

  /**
   * Set the value of aluno
   * < Cada aluno uma avaliacao
   * @param value the new value of aluno
   */
  void setAluno(std::vector< CAvaliacao > value)
  {
    aluno = value;
  }

  /**
   * Get the value of aluno
   * < Cada aluno uma avaliacao
   * @return the value of aluno
   */
  std::vector< CAvaliacao > getAluno()
  {
    return aluno;
  }

  /**
   * Set the value of media
   * < Vetor com as medias das avaliacoes de cada pergunta
   * @param value the new value of media
   */
  void setMedia(std::vector< double > value)
  {
    media = value;
  }

  /**
   * Get the value of media
   * < Vetor com as medias das avaliacoes de cada pergunta
   * @return the value of media
   */
  std::vector< double > getMedia()
  {
    return media;
  }

  void initAttributes();

};

#endif // CAVALIACAOTURMA_H

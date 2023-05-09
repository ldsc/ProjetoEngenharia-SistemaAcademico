
#ifndef CAVALIACAO_H
#define CAVALIACAO_H

#include "CConteudoDidatico.h"
#include "CAvaliacaoProvaEscritaDiscursiva.h"
#include "CAvaliacaoListaExercicios.h"
#include "CAvaliacaoTurma.h"

#include string
#include vetor



/**
  * class CAvaliacao
  * Classe que representa uma avaliação criada, por exemplo, por um professor.
  * Pense nisso como sendo uma prova ou lista de exercícios criada pelo professor.
  * Note que quando um professor prepara uma avaliação ele tem um ou mais escopos e
  * perguntas associadas.
  * Note que esta avaliação será posteriormente "impressa" e entregue aos alunos.
  * 
  * Uma boa avaliação parte de um ou mais problemas, por isso temos uma lista de
  * problemas.
  * Uma boa avaliação tem uma lista de perguntas que estão relacionadas aos
  * problemas apresentados.
  * Note que esta correlação entre problemas e perguntas esta apenas no texto, não
  * faz sentido restringir isso computacionalmente. Quem gera a avaliação fará esta
  * vinculação no texto.
  * 
  * 
  */

class CAvaliacao : public CConteudoDidatico, public CAvaliacaoProvaEscritaDiscursiva, public CAvaliacaoListaExercicios, public CAvaliacaoTurma
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  CAvaliacao();

  /**
   * Empty Destructor
   */
  virtual ~CAvaliacao();



  /**
   * Obtem/recupera perguntas de um arquivo de disco
   * @param  nomeArquivo
   */
  static void LerPerguntasDisco(string nomeArquivo)
  {
  }


  /**
   * @return string
   */
  string Comentario() const
  {
  }


  /**
   * Sa�da dos dados
   * @param  out
   */
  void SaidaDados(std::ostream& out)
  {
  }


  /**
   * Quando a avaliação é impressa é necessário adicionar o código da turma.
   * Isto é importante pois a avaliação é um documento separado, pode ser extraviado
   * e o código da turma facilita encontrar a correspondência.
   */
  void ImprimirCodigoTurma()
  {
  }

private:
  // Private attributes
  //  

  std::vector<CProfessor> professor;
  string dataInicio;
  string dataEntrega;
  double peso;
  // Um problema define algo mais genérico e abrangente do que uma pergunta.
  // A partir de um ou mais problemas são elaboradas perguntas a serem respondidas por quem é avaliado.
  CProblema problema;
  // Vetor estatico com as perguntas (mesmas perguntas para todos os avaliados).
  // Note que as perguntas deverão estar vinculadas aos problemas colocados. A ideia é que não tenhamos perguntas perdidas, elas devem estar associadas ao problema (de engenharia) que foi colocado.
  // 
  std::vector<std::string> pergunta;
  std::vector<double> pesoPergunta;
  string comentario;
  CRespostaAvaliacao respostaPadrao;

  // Private attribute accessor methods
  //  


  /**
   * Set the value of professor
   * @param value the new value of professor
   */
  void setProfessor(std::vector<CProfessor> value)
  {
    professor = value;
  }

  /**
   * Get the value of professor
   * @return the value of professor
   */
  std::vector<CProfessor> getProfessor()
  {
    return professor;
  }

  /**
   * Set the value of dataInicio
   * @param value the new value of dataInicio
   */
  void setDataInicio(string value)
  {
    dataInicio = value;
  }

  /**
   * Get the value of dataInicio
   * @return the value of dataInicio
   */
  string getDataInicio()
  {
    return dataInicio;
  }

  /**
   * Set the value of dataEntrega
   * @param value the new value of dataEntrega
   */
  void setDataEntrega(string value)
  {
    dataEntrega = value;
  }

  /**
   * Get the value of dataEntrega
   * @return the value of dataEntrega
   */
  string getDataEntrega()
  {
    return dataEntrega;
  }

  /**
   * Set the value of peso
   * @param value the new value of peso
   */
  void setPeso(double value)
  {
    peso = value;
  }

  /**
   * Get the value of peso
   * @return the value of peso
   */
  double getPeso()
  {
    return peso;
  }

  /**
   * Set the value of problema
   * Um problema define algo mais genérico e abrangente do que uma pergunta.
   * A partir de um ou mais problemas são elaboradas perguntas a serem respondidas
   * por quem é avaliado.
   * @param value the new value of problema
   */
  void setProblema(CProblema value)
  {
    problema = value;
  }

  /**
   * Get the value of problema
   * Um problema define algo mais genérico e abrangente do que uma pergunta.
   * A partir de um ou mais problemas são elaboradas perguntas a serem respondidas
   * por quem é avaliado.
   * @return the value of problema
   */
  CProblema getProblema()
  {
    return problema;
  }

  /**
   * Set the value of pergunta
   * Vetor estatico com as perguntas (mesmas perguntas para todos os avaliados).
   * Note que as perguntas deverão estar vinculadas aos problemas colocados. A ideia
   * é que não tenhamos perguntas perdidas, elas devem estar associadas ao problema
   * (de engenharia) que foi colocado.
   * 
   * @param value the new value of pergunta
   */
  void setPergunta(std::vector<std::string> value)
  {
    pergunta = value;
  }

  /**
   * Get the value of pergunta
   * Vetor estatico com as perguntas (mesmas perguntas para todos os avaliados).
   * Note que as perguntas deverão estar vinculadas aos problemas colocados. A ideia
   * é que não tenhamos perguntas perdidas, elas devem estar associadas ao problema
   * (de engenharia) que foi colocado.
   * 
   * @return the value of pergunta
   */
  std::vector<std::string> getPergunta()
  {
    return pergunta;
  }

  /**
   * Set the value of pesoPergunta
   * @param value the new value of pesoPergunta
   */
  void setPesoPergunta(std::vector<double> value)
  {
    pesoPergunta = value;
  }

  /**
   * Get the value of pesoPergunta
   * @return the value of pesoPergunta
   */
  std::vector<double> getPesoPergunta()
  {
    return pesoPergunta;
  }

  /**
   * Set the value of comentario
   * @param value the new value of comentario
   */
  void setComentario(string value)
  {
    comentario = value;
  }

  /**
   * Get the value of comentario
   * @return the value of comentario
   */
  string getComentario()
  {
    return comentario;
  }

  /**
   * Set the value of respostaPadrao
   * @param value the new value of respostaPadrao
   */
  void setRespostaPadrao(CRespostaAvaliacao value)
  {
    respostaPadrao = value;
  }

  /**
   * Get the value of respostaPadrao
   * @return the value of respostaPadrao
   */
  CRespostaAvaliacao getRespostaPadrao()
  {
    return respostaPadrao;
  }

  void initAttributes();

};

#endif // CAVALIACAO_H

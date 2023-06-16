#ifndef CAVALIACAO_H
#define CAVALIACAO_H

// #include "CConteudoDidatico.h"
// #include "CAvaliacaoProvaEscritaDiscursiva.h"
// #include "CAvaliacaoListaExercicios.h"
// #include "CAvaliacaoTurma.h"
#include <string>
#include <vector>

/// class CAvaliacao
/// Classe que representa uma avaliação criada, por exemplo, por um professor.
/// Pense nisso como sendo uma prova ou lista de exercícios criada pelo professor.
/// Note que quando um professor prepara uma avaliação ele tem um ou mais escopos e perguntas associadas.
/// Note que esta avaliação será posteriormente "impressa" e entregue aos alunos.
/// 
/// Uma boa avaliação parte de um ou mais problemas, por isso temos uma lista de problemas.
/// Uma boa avaliação tem uma lista de perguntas que estão relacionadas aos problemas apresentados.
/// Note que esta correlação entre problemas e perguntas esta apenas no texto, não faz sentido restringir isso computacionalmente. Quem gera a avaliação fará esta vinculação no texto.
/// 

class CAvaliacao
{
private:
  std::vector<CProfessor> professor;
  string dataInicio;
  string dataEntrega;
  string instrucoes;

  // Um problema define algo mais genérico e abrangente do que uma pergunta.
  // A partir de um ou mais problemas são elaboradas perguntas a serem respondidas  
  // por quem é avaliado.
  CProblema problema;
  
  // Vetor estatico com as perguntas (mesmas perguntas para todos os avaliados).
  // Note que as perguntas deverão estar vinculadas aos problemas colocados. A ideia
  // é que não tenhamos perguntas perdidas, elas devem estar associadas ao problema
  // (de engenharia) que foi colocado.
  // 
  std::vector<std::string> pergunta;
  
  // Peso de cada pergunta (poderia ser um <pair>)
  std::vector<double> pesoPergunta;

  // A resposta padrão é a resposta do professor.
  CRespostaAvaliacao respostaPadrao;
  
  // Se for a avaliação final a nota é considerada pelo sistema de forma diferente.
  //   
  bool avaliacaoFinal;

public:
  // Constructors/Destructors  
  /// Empty Constructor
  explicit CAvaliacao();

  /// Empty Destructor
  virtual ~CAvaliacao();

  /// 
  /// Saída dos dados
  /// @param  out 
  void SaidaDados(std::ostream& out)
  {
  }

  /// Quando a avaliação é impressa é necessário adicionar o código da turma.
  /// Isto é importante pois a avaliação é um documento separado, pode ser extraviado
  /// e o código da turma facilita encontrar a correspondência.
  void AdicionarLogomarcaTurma()
  {
  }

  /// @param  instrucoes 
  void AdicionarInstrucoes(string _instrucoes = "") const
  {
  }

  /// @param  problema 
  void AdicionarProblema(CProblema problema)
  {
  }

  /// Tempo de reflexão sobre a avaliação.
  /// Caso seja avaliação padrão, como avaliação da disciplina, obtem/recupera
  /// perguntas padrões de um arquivo de disco.
  /// @param  nomeArquivo 
  static void LerPerguntasDisco(string nomeArquivo)
  {
  }

  /// 
  void DistribuirAvaliacao()
  {
  }

  /// @param  pergunta 
  void AdicionarPergunta(string _pergunta = "")
  {
  }

  /// 
  void FormularAvaliacao()
  {
  }

  /// 
  void GerarRespostaPadrao()
  {
  }

  /// 
  void VerificarIntegridadeAvaliacao()
  {
  }

  /// 
  /// @param  numeroCopias 
  void Imprimir(int numeroCopias)
  {
  }

  /// Set the value of professor
  /// @param value the new value of professor
  void Professor(std::vector<CProfessor> value)
  {
    professor = value;
  }

  /// Get the value of professor
  /// @return the value of professor
  std::vector<CProfessor> Professor()
  {
    return professor;
  }

  /// Set the value of dataInicio
  /// @param value the new value of dataInicio
  void DataInicio(string value)
  {
    dataInicio = value;
  }

  /// Get the value of dataInicio
  /// @return the value of dataInicio
  string DataInicio()
  {
    return dataInicio;
  }

  /// Set the value of dataEntrega
  /// @param value the new value of dataEntrega
  void DataEntrega(string value)
  {
    dataEntrega = value;
  }

  /// Get the value of dataEntrega
  /// @return the value of dataEntrega
  string DataEntrega()
  {
    return dataEntrega;
  }

  /// Set the value of instrucoes
  /// @param value the new value of instrucoes
  void Instrucoes(string value)
  {
    instrucoes = value;
  }

  /// Get the value of instrucoes
  /// @return the value of instrucoes
  string Instrucoes()
  {
    return instrucoes;
  }

  /// Set the value of problema
  /// Um problema define algo mais genérico e abrangente do que uma pergunta.
  /// A partir de um ou mais problemas são elaboradas perguntas a serem respondidas
  /// por quem é avaliado.
  /// @param value the new value of problema
  void Problema(CProblema value)
  {
    problema = value;
  }

  /// Get the value of problema
  /// Um problema define algo mais genérico e abrangente do que uma pergunta.
  /// A partir de um ou mais problemas são elaboradas perguntas a serem respondidas
  /// por quem é avaliado.
  /// @return the value of problema
  CProblema Problema()
  {
    return problema;
  }

  /// Set the value of pergunta
  /// Vetor estatico com as perguntas (mesmas perguntas para todos os avaliados).
  /// Note que as perguntas deverão estar vinculadas aos problemas colocados. A ideia
  /// é que não tenhamos perguntas perdidas, elas devem estar associadas ao problema
  /// (de engenharia) que foi colocado.
  /// 
  /// @param value the new value of pergunta
  void Pergunta(std::vector<std::string> value)
  {
    pergunta = value;
  }

  /// 
  /// Get the value of pergunta
  /// Vetor estatico com as perguntas (mesmas perguntas para todos os avaliados).
  /// Note que as perguntas deverão estar vinculadas aos problemas colocados. A ideia
  /// é que não tenhamos perguntas perdidas, elas devem estar associadas ao problema
  /// (de engenharia) que foi colocado.
  /// 
  /// @return the value of pergunta
  std::vector<std::string> Pergunta()
  {
    return pergunta;
  }

  /// Set the value of pesoPergunta
  /// @param value the new value of pesoPergunta
  void PesoPergunta(std::vector<double> value)
  {
    pesoPergunta = value;
  }

  /// Get the value of pesoPergunta
  /// @return the value of pesoPergunta
  std::vector<double> PesoPergunta()
  {
    return pesoPergunta;
  }

  /// Set the value of respostaPadrao
  /// @param value the new value of respostaPadrao
  void setRespostaPadrao(CRespostaAvaliacao value)
  {
    respostaPadrao = value;
  }

  /// Get the value of respostaPadrao
  /// @return the value of respostaPadrao
  CRespostaAvaliacao RespostaPadrao()
  {
    return respostaPadrao;
  }

  /// Set the value of avaliacaoFinal
  /// Se for a avaliação final a nota é considerada de forma diferente.
  /// 
  /// @param value the new value of avaliacaoFinal
  void AvaliacaoFinal(bool value)
  {
    avaliacaoFinal = value;
  }

  /// 
  /// Get the value of avaliacaoFinal
  /// Se for a avaliação final a nota é considerada de forma diferente.
  /// @return the value of avaliacaoFinal
  bool AvaliacaoFinal()
  {
    return avaliacaoFinal;
  }

  void InitAttributes();
};
#endif // CAVALIACAO_H

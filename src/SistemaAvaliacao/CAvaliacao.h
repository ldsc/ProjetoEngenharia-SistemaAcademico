#ifndef CAVALIACAO_H
#define CAVALIACAO_H

// #include "CConteudoDidatico.h"
// #include "CAvaliacaoProvaEscritaDiscursiva.h"
// #include "CAvaliacaoListaExercicios.h"
// #include "CAvaliacaoTurma.h"
#include <string>
#include <vector>

/// class CAvaliacao
/// Classe que representa uma avaliação criadapelo professor coordenador da turma.
/// Pense nisso como sendo uma prova ou lista de exercícios criada pelo professor.
/// Passos:
/// 1. O professor coordenador cria a avaliação (na memória).
/// 2. A seguir vai Formular a Avaliacao.
/// Define os demais professores.
/// Define as datas de inicio/entrega.
/// Define as instrucoes da prova.
/// Define o escopo do problema.
/// Define as perguntas e o peso de cada pergunta.
/// Define se é a avaliacaoFinal (seta-se um flag).
/// 3. Salvar e verificar integridade, se necessário revisar.
/// Salvar a avaliação em disco.
/// Verificar a integridade (conferir se esta tudo ok).
/// 4. GerarRespostaPadrao, um gabarito com as respostas dada pelo professor.
/// 5. Impressão e distribuição (para os alunos/alunas).
/// Imprime a avaliação.

/// A prova impressa será um arquivo de disco no formato txt com o
/*
Logomarca da turma
Instrucoes
Problema
Perguntas
*/
class CAvaliacao
{
private:
  std::shared_ptr<CTurma> turma;
  // Verificar como acessar os professores...
  // shared_ptr ou int id?
  std::vector<std::shared_ptr<CProfessor>> vProfessor;
  std::string dataInicio;
  std::string dataEntrega;
  std::string instrucoes;

  // Um problema define algo mais genérico e abrangente do que uma pergunta.
  // A partir de um ou mais problemas são elaboradas perguntas a serem respondidas  
  // por quem é avaliado.
  CProblema problema;
  
  // Vetor estatico com as perguntas (mesmas perguntas para todos os avaliados).
  // Note que as perguntas deverão estar vinculadas aos problemas colocados. A ideia
  // é que não tenhamos perguntas perdidas, elas devem estar associadas ao problema
  // (de engenharia) que foi colocado.
  std::vector<std::string> pergunta;
  
  /// Peso de cada pergunta (poderia ser um <pair>).
  std::vector<double> pesoPergunta;

  /// A resposta padrão é a resposta do professor.
  CRespostaAvaliacao respostaPadrao;
  
  /// Se for a avaliação final a nota é considerada pelo sistema de forma diferente.
  bool avaliacaoFinal;

public:
  /// Construtor.
  explicit CAvaliacao(std::shared_ptr<CTurma> _turma);

  /// Destrutor.
  virtual ~CAvaliacao();

  /// Todas as etapas associadas a formulação/geração da avaliação.
  void FormularAvaliacao();

  /// Define os professores que organizam a prova.
  void DefinirProfessores();

  /// Define as datas.
  void DefinirDatas();

  /// Quando a avaliação é impressa é necessário adicionar o código da turma.
  /// Isto é importante pois a avaliação é um documento separado, pode ser extraviado
  /// e o código da turma facilita encontrar a correspondência.
  void DefinirLogomarcaTurma();

  /// @param  instrucoes 
  void DefinirInstrucoes(std::string _instrucoes = {});

  /// @param  problema 
  void DefinirProblema(std::string _escopo = {});

  /// Tempo de reflexão sobre a avaliação.
  /// Caso seja avaliação padrão, como avaliação da disciplina, obtem/recupera
  /// perguntas padrões de um arquivo de disco.
  /// @param  nomeArquivo 
  static void LerPerguntasDisco(std::string nomeArquivo);

  /// Adiciona as perguntas e o peso de cada pergunta
  void DefinirPerguntas();

  ///
  void VerificarIntegridadeAvaliacao();
  /// Saída dos dados. Salva a avaliação em disco.
  void SaidaDados(std::ostream& out);

  /// O coordenador gera uma resposta padrão, um gabarito, respondendo as perguntas e salvando o resultado em um arquivo respostaPadrao.dat.
  void GerarRespostaPadrao();

  /// @param  numeroCopias
  void Imprimir(int numeroCopias());
  /// Se for um sistema online vai enviar as avaliações aos alunos.
  void DistribuirAvaliacao();

  /// ---------- set and get ---------------
  /// Vetor com os professores.
  void Professor(std::vector<CProfessor> value)  { professor = value; }

  /// Retorna vetor com os professores.
  std::vector<CProfessor> Professor() { return professor; }

  /// Seta data inicio.
  void DataInicio(std::string value)  { dataInicio = value; }

  /// Retorna a data inicio.
  std::string DataInicio() { return dataInicio; }

  /// Seta a data de entrega.
  void DataEntrega(std::string value) { dataEntrega = value; }

  /// Retorna a dataEntrega.
  std::string DataEntrega() { return dataEntrega;  }

  /// Seta as instrucoes.
  void Instrucoes(std::string value) { instrucoes = value; }

  /// Retorna as instrucoes.
  std::string Instrucoes() { return instrucoes; }

  /// Set o problema
  /// Um problema define algo mais genérico e abrangente do que uma pergunta.
  /// A partir de um ou mais problemas são elaboradas perguntas a serem respondidas
  /// por quem é avaliado.
  void Problema(CProblema value) { problema = value; }

  /// Obtem o valr do problema.
  /// Um problema define algo mais genérico e abrangente do que uma pergunta.
  /// A partir de um ou mais problemas são elaboradas perguntas a serem respondidas por quem é avaliado.
  CProblema Problema() { return problema;  }

  /// Seta o vetor de perguntas.
  /// Vetor com as perguntas (mesmas perguntas para todos os avaliados).
  /// Note que as perguntas deverão estar vinculadas aos problemas colocados.
  /// A ideia é que não tenhamos perguntas perdidas, elas devem estar associadas ao problema (de engenharia) que foi colocado.
  void Pergunta(std::vector<std::string> value) {  pergunta = value; }

  /// Retorna o vetor de perguntas.
  std::vector<std::string> Pergunta()  {    return pergunta;  }

  /// Seta o peso das perguntas.
  void PesoPergunta(std::vector<double> value)  {    pesoPergunta = value;  }

  /// Retorna o peso das perguntas.
  std::vector<double> PesoPergunta()  {    return pesoPergunta;  }

  /// Seta a resposta padrão.
  void RespostaPadrao(CRespostaAvaliacao value)  {    respostaPadrao = value;  }

  /// Retorna a resposta padrão.
  CRespostaAvaliacao RespostaPadrao()  {    return respostaPadrao;  }

  /// Informa se é a avaliação final (prova final).
  void AvaliacaoFinal(bool value)  {    avaliacaoFinal = value;  }

  /// Retorna o flag se é a avaliação final.
  bool AvaliacaoFinal()  {    return avaliacaoFinal;  }

private:
  /// Função auxiliar.
  void AdicionarPergunta(int i, std::string _pergunta);
};
#endif // CAvaliacao_H

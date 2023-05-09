#ifndef CRespostaAvaliacao_H
#define CRespostaAvaliacao_H

#include <string>
#include <vector>
#include <memory>

/// Representa uma resposta de uma avaliação.
/// Se a avaliação é uma prova, a resposta é o conjunto de respostas de um dado aluno (ou grupo de alunos)
class CRespostaAvaliacao
{
  // Attributes
private:
  /// Vetor com os dados dos autores
  std::vector<std::shared_ptr<CPessoa>> autor;
  // Visa verificar se foi entregue no prazo; pode estar em branco indicando entrega no prazo.
  std::string dataEntrega;
  /// Texto usado para relatar uma ocorrência com relação a avaliação.
  // Como exemplo uma cola. Neste caso a nota da avaliação será zero.
  // Pode-se definir algum marcador como #COLA=TRUE#
  std::string ocorrencia;
  /// Vetor com a lista de respostas. Estão associadas a lista de perguntas. Se o aluno não respondeu será uma string vazia.
  std::vector<std::string> resposta;
  /// Vetor com a lista de pessoas que avaliaram a prova.
  std::vector<std::shared_ptr<CPessoa> avaliador;
  // Nota para cada resposta.
  std::vector<double> notaResposta;

public:

  /**
   * Empty Constructor
   */
  CRespostaAvaliacao() {};

  /**
   * Empty Destructor
   */
  virtual ~CRespostaAvaliacao(){};

  /**
   */
  void ListarAutores()
  {
    cout << "\nLista autores:";
    for( auto pessoa : autor)
      cout << "\nNome: "  << pessoa.Nome() ;
  }

  /**
   */
  void ListarAvaliadores()
  {
    cout << "\nLista avaliadores:";
    for( auto pessoa : avaliador)
      cout << "\nNome: "  << pessoa.Nome() ;
  }


  /**
   * Visa ler toda a prova para entender o escopo e as perguntas.
   */
  void LerAvaliacao(CAvaliacao& avaliacao)
  { // aqui o aluno ou avaliador lê a avaliação
    avaliacao.LerInstrucoes();
    avaliacao.LerProblema();
    string resposta;
    for (size_t i = ; i< avaliacao.pergunta.size(); i++) {
      cout << "\nPergunta[" << i << "]:\n" << avaliacao.pergunta[i];
      cout << "\nQual a resposta? ";
      cin.getline(resposta);
    }
  }

  /**
   */
  void ResponderPerguntas()
  {
    // aqui quem faz a avaliação responde as perguntas
  }


  /**
   * Como tem prazo, tem de entregar dentro do prazo, pois fora do prazo terá punições.
   */
  void EntregarAvaliacao()
  {
    // Verificar se entregou no prazo. // Critério de punições definido no sistema de avaliação.
  }

  /**
   * Professor registra a data de entrega.
   */
  void RegistrarDataEntrega()
  {
  }

  /**
   * Tem de começar verificando se a data de entrega esta dentro do prazo e verificar
   * também se teve alguma ocorrência (como cola!).
   * 
   * O avaliador ou os avaliadores irão ler as respostas e dar notas considerando a
   * avaliação e a resposta padrão.
   * 
   */
  void AvaliarPerguntasEDarNotas()
  {
    notaResposta.resize(resposta.size());
    for (size_t i = ; i< resposta.size(); i++) {
      cout << "\nResposta[" << i << "]:\n" << resposta[i];
      cout << "\nQual a nota: ";
      cin  >> notaResposta[i]; cin.get();
    }
  }

  /**
   * Toda avaliação deve ser arquivada por um determinado prazo.
   * Normalmente 5 anos.
   */
  void Arquivar()
  { //nome do arquivo: Código da Turma + Número da avaliação(vem do sistema de avaliação) + nomeAutores ou id da avaliação e id da resposta.
  }

  /**
   * Set the value of autor
   * @param value the new value of autor
   */
  void Autor(std::vector<CPessoa> listaAutores)  {    autor = listaAutores;  }

  /**
   * Get the value of autor (vetor com a lista de autores da resposta)
   * @return the value of autor
   */
  std::vector<CPessoa> Autor()   {    return autor;  }

  /**
   * Set the value of dataEntrega
   * Visa verificar se foi entregue no prazo; pode estar em branco indicando entrega
   * no prazo.
   * @param value the new value of dataEntrega
   */
  void DataEntrega(std::string data)   {    dataEntrega = data;  }

  /**
   * Get the value of dataEntrega
   * Visa verificar se foi entregue no prazo; pode estar em branco indicando entrega
   * no prazo.
   * @return the value of dataEntrega
   */
  std::string DataEntrega()  {    return dataEntrega;  }

  /**
   * Set the value of ocorrencia
   * Usado para relatar uma ocorrência com relação a avaliação.
   * Como exemplo uma cola.
   * Neste caso a nota da avaliação será zero.
   * @param value the new value of ocorrencia
   */
  void Ocorrencia(std::string informe_de_ocorrencia)  {    ocorrencia = informe_de_ocorrencia;  }

  /**
   * Get the value of ocorrencia
   * Usado para relatar uma ocorrência com relação a avaliação.
   * Como exemplo uma cola.
   * Neste caso a nota da avaliação será zero.
   * @return the value of ocorrencia
   */
  std::string Ocorrencia()  {    return ocorrencia;  }

  /**
   * Set the value of resposta
   * @param value the new value of resposta
   */
  void Resposta(std::vector<std::string> vResposta)
  {
    resposta = vResposta;
  }

  /**
   * Get the value of resposta
   * @return the value of resposta
   */
  std::vector<std::string> Resposta()  {    return resposta;  }

  /**
   * Set the value of avaliador
   * @param value the new value of avaliador
   */
  void Avaliador(std::vector<std::string> vAvaliadores)  {    avaliador = vAvaliadores;  }

  /**
   * Get the value of avaliador
   * @return the value of avaliador
   */
  std::vector<std::string> Avaliador()  {    return avaliador;  }

  /**
   * Set the value of notaResposta
   * Nota para cada resposta.
   * @param value the new value of notaResposta
   */
  void NotaResposta(std::vector<double> vNotaResposta)  {    notaResposta = vNotaResposta;  }

  /**
   * Get the value of notaResposta
   * Nota para cada resposta.
   * @return the value of notaResposta
   */
  std::vector<double> NotaResposta()  {    return notaResposta;  }

};
#endif // CRespostaAvaliacao_H


#ifndef CRESPOSTAAVALIACAO_H
#define CRESPOSTAAVALIACAO_H

#include string
#include vector


class CRespostaAvaliacao
{
public:
  // Constructors/Destructors  



  /// 
  /// Empty Constructor
  CRespostaAvaliacao();

  /// 
  /// Empty Destructor
  virtual ~CRespostaAvaliacao();



  /// 
  void CRespostaPadrao()
  {
  }


  /// 
  /// Visa ler toda a prova para entender o escopo e as perguntas.
  void LerAvaliacao()
  {
  }


  /// 
  void ResponderPerguntas()
  {
  }


  /// 
  /// Tem de começar verificando se a data de entrega esta dentro do prazo e verificar
  /// também se teve alguma ocorrência (como cola!).
  /// 
  /// O avaliador ou os avaliadores irão ler as respostas e dar notas considerando a
  /// avaliação e a resposta padrão.
  /// 
  void AvaliarRespostasEDarNotas()
  {
  }


  /// 
  void ListarAvaliadores()
  {
  }


  /// 
  void ListarAutores()
  {
  }


  /// 
  /// Como tem prazo, tem de entregar dentro do prazo, pois fora do prazo terá
  /// punições.
  void EntregarAvaliacao()
  {
  }


  /// 
  /// Toda avaliação deve ser arquivada por um determinado prazo.
  /// Normalmente 5 anos.
  void Arquivar()
  {
  }


  /// 
  void RegistrarDataEntrega()
  {
  }


  /// 
  void ChecarIntegridadeRespostas()
  {
  }


  /// 
  void VistaDaAvaliacao()
  {
  }


  /// 
  /// @return bool
  /// @param  resposta 
  bool CompararRespostaComRespostaPadrao(CRespostaAvaliacao resposta)
  {
  }

private:
  // Private attributes  


  std::vector<CPessoa> autor;
  // Visa verificar se foi entregue no prazo; pode estar em branco indicando entrega  
  // no prazo.
  string dataEntrega;
  // Usado para relatar uma ocorrência com relação a avaliação.
  // Como exemplo uma cola.
  // Neste caso a nota da avaliação será zero.  
  string ocorrencia;
  std::vector<string> resposta;
  std::vector<string> avaliador;
  // Nota para cada resposta.  
  std::vector<double> notaResposta;

  // Public attribute accessor methods  



  /// 
  /// Set the value of autor
  /// @param value the new value of autor
  void setAutor(std::vector<CPessoa> value)
  {
    autor = value;
  }

  /// 
  /// Get the value of autor
  /// @return the value of autor
  std::vector<CPessoa> autor()
  {
    return autor;
  }

  /// 
  /// Set the value of dataEntrega
  /// Visa verificar se foi entregue no prazo; pode estar em branco indicando entrega
  /// no prazo.
  /// @param value the new value of dataEntrega
  void setDataEntrega(string value)
  {
    dataEntrega = value;
  }

  /// 
  /// Get the value of dataEntrega
  /// Visa verificar se foi entregue no prazo; pode estar em branco indicando entrega
  /// no prazo.
  /// @return the value of dataEntrega
  string dataEntrega()
  {
    return dataEntrega;
  }

  /// 
  /// Set the value of ocorrencia
  /// Usado para relatar uma ocorrência com relação a avaliação.
  /// Como exemplo uma cola.
  /// Neste caso a nota da avaliação será zero.
  /// @param value the new value of ocorrencia
  void setOcorrencia(string value)
  {
    ocorrencia = value;
  }

  /// 
  /// Get the value of ocorrencia
  /// Usado para relatar uma ocorrência com relação a avaliação.
  /// Como exemplo uma cola.
  /// Neste caso a nota da avaliação será zero.
  /// @return the value of ocorrencia
  string ocorrencia()
  {
    return ocorrencia;
  }

  /// 
  /// Set the value of resposta
  /// @param value the new value of resposta
  void setResposta(std::vector<string> value)
  {
    resposta = value;
  }

  /// 
  /// Get the value of resposta
  /// @return the value of resposta
  std::vector<string> resposta()
  {
    return resposta;
  }

  /// 
  /// Set the value of avaliador
  /// @param value the new value of avaliador
  void setAvaliador(std::vector<string> value)
  {
    avaliador = value;
  }

  /// 
  /// Get the value of avaliador
  /// @return the value of avaliador
  std::vector<string> avaliador()
  {
    return avaliador;
  }

  /// 
  /// Set the value of notaResposta
  /// Nota para cada resposta.
  /// @param value the new value of notaResposta
  void setNotaResposta(std::vector<double> value)
  {
    notaResposta = value;
  }

  /// 
  /// Get the value of notaResposta
  /// Nota para cada resposta.
  /// @return the value of notaResposta
  std::vector<double> notaResposta()
  {
    return notaResposta;
  }

  void initAttributes();

};

#endif // CRESPOSTAAVALIACAO_H

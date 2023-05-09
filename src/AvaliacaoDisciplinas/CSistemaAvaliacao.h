
#ifndef CSISTEMAAVALIACAO_H
#define CSISTEMAAVALIACAO_H

#include string

class CSistemaAvaliacao
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  CSistemaAvaliacao();

  /**
   * Empty Destructor
   */
  virtual ~CSistemaAvaliacao();



  /**
   */
  void DefinirNumeroAvaliacoesTipoPeso()
  {
  }


  /**
   */
  void FormularAvaliacao()
  {
  }


  /**
   */
  void FormularRespostaPadrao()
  {
  }


  /**
   */
  void DistribuirAvaliacao()
  {
  }


  /**
   */
  void ReceberRespostasAvaliacao()
  {
  }


  /**
   */
  void CorrigirRespostasAvaliacao()
  {
  }


  /**
   */
  void ArquivarAvaliacaoERespostas()
  {
  }

private:
  // Private attributes
  //  

  std::vector<CAvaliacao> avaliacao;
  // Toda disciplina deve ter um mínimo de duas avaliações e avaliação final para quem pegou recuperação.
  // 
  // PS:
  // Por padrão da uenf toda disciplina mínimo de duas provas.
  bool atendeCriteriosMinimos;
  std::vector<CRespostaAvaliacao> resposta;

  // Private attribute accessor methods
  //  


  /**
   * Set the value of avaliacao
   * @param value the new value of avaliacao
   */
  void setAvaliacao(std::vector<CAvaliacao> value)
  {
    avaliacao = value;
  }

  /**
   * Get the value of avaliacao
   * @return the value of avaliacao
   */
  std::vector<CAvaliacao> getAvaliacao()
  {
    return avaliacao;
  }

  /**
   * Set the value of atendeCriteriosMinimos
   * Toda disciplina deve ter um mínimo de duas avaliações e avaliação final para
   * quem pegou recuperação.
   * 
   * PS:
   * Por padrão da uenf toda disciplina mínimo de duas provas.
   * @param value the new value of atendeCriteriosMinimos
   */
  void setAtendeCriteriosMinimos(bool value)
  {
    atendeCriteriosMinimos = value;
  }

  /**
   * Get the value of atendeCriteriosMinimos
   * Toda disciplina deve ter um mínimo de duas avaliações e avaliação final para
   * quem pegou recuperação.
   * 
   * PS:
   * Por padrão da uenf toda disciplina mínimo de duas provas.
   * @return the value of atendeCriteriosMinimos
   */
  bool getAtendeCriteriosMinimos()
  {
    return atendeCriteriosMinimos;
  }

  /**
   * Set the value of resposta
   * @param value the new value of resposta
   */
  void setResposta(std::vector<CRespostaAvaliacao> value)
  {
    resposta = value;
  }

  /**
   * Get the value of resposta
   * @return the value of resposta
   */
  std::vector<CRespostaAvaliacao> getResposta()
  {
    return resposta;
  }

  void initAttributes();

};

#endif // CSISTEMAAVALIACAO_H

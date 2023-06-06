
#ifndef CSISTEMAAVALIACAO_H
#define CSISTEMAAVALIACAO_H

#include string
#include vector


class CSistemaAvaliacao
{
public:
  // Constructors/Destructors  



  /// 
  /// Empty Constructor
  CSistemaAvaliacao();

  /// 
  /// Empty Destructor
  virtual ~CSistemaAvaliacao();



  /// 
  void DefinirNumeroAvaliacoesTipoPeso()
  {
  }


  /// 
  void ArquivarAvaliacaoERespostas()
  {
  }


  /// 
  /// @param  respostaAvaliacao 
  void AdicionarRespostaAvaliacao(CRespostaAvaliacao respostaAvaliacao)
  {
  }


  /// 
  /// @param  avaliacao 
  void AdicionarAvaliacao(CAvaliacao avaliacao)
  {
  }

private:
  // Private attributes  


  std::vector<CAvaliacao> avaliacao;
  // Toda disciplina deve ter um mínimo de duas avaliações e avaliação final para
  // quem pegou recuperação.
  // 
  // PS:  
  // Por padrão da uenf toda disciplina mínimo de duas provas.
  bool atendeCriteriosMinimos;
  std::vector<CRespostaAvaliacao> resposta;
  std::vector<double> pesoAvaliacao;

  // Public attribute accessor methods  



  /// 
  /// Set the value of avaliacao
  /// @param value the new value of avaliacao
  void setAvaliacao(std::vector<CAvaliacao> value)
  {
    avaliacao = value;
  }

  /// 
  /// Get the value of avaliacao
  /// @return the value of avaliacao
  std::vector<CAvaliacao> avaliacao()
  {
    return avaliacao;
  }

  /// 
  /// Set the value of atendeCriteriosMinimos
  /// Toda disciplina deve ter um mínimo de duas avaliações e avaliação final para
  /// quem pegou recuperação.
  /// 
  /// PS:
  /// Por padrão da uenf toda disciplina mínimo de duas provas.
  /// @param value the new value of atendeCriteriosMinimos
  void setAtendeCriteriosMinimos(bool value)
  {
    atendeCriteriosMinimos = value;
  }

  /// 
  /// Get the value of atendeCriteriosMinimos
  /// Toda disciplina deve ter um mínimo de duas avaliações e avaliação final para
  /// quem pegou recuperação.
  /// 
  /// PS:
  /// Por padrão da uenf toda disciplina mínimo de duas provas.
  /// @return the value of atendeCriteriosMinimos
  bool atendeCriteriosMinimos()
  {
    return atendeCriteriosMinimos;
  }

  /// 
  /// Set the value of resposta
  /// @param value the new value of resposta
  void setResposta(std::vector<CRespostaAvaliacao> value)
  {
    resposta = value;
  }

  /// 
  /// Get the value of resposta
  /// @return the value of resposta
  std::vector<CRespostaAvaliacao> resposta()
  {
    return resposta;
  }

  /// 
  /// Set the value of pesoAvaliacao
  /// @param value the new value of pesoAvaliacao
  void setPesoAvaliacao(std::vector<double> value)
  {
    pesoAvaliacao = value;
  }

  /// 
  /// Get the value of pesoAvaliacao
  /// @return the value of pesoAvaliacao
  std::vector<double> pesoAvaliacao()
  {
    return pesoAvaliacao;
  }

  void initAttributes();

};

#endif // CSISTEMAAVALIACAO_H

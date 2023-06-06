#ifndef CEMENTADISCIPLINA_H
#define CEMENTADISCIPLINA_H

#include <string>
#include <vector>

class CEmentaDisciplina
{
public:
  /// Empty Constructor
  CEmentaDisciplina();

  /// Empty Destructor
  virtual ~CEmentaDisciplina();

  /// 
  void ListaAssuntos()
  {
  }

private:
  // Private attributes  
  CCodigoDisciplina codigo;
  std::string nome;
  std::vector<CCodigoDisciplina> preRequisito;
  std::vector<std::string> referencia;//CReferenciaBibliografica referencia;
  std::vector<ETipoAvaliacao> sistemaAvaliacao;
  string conteudoProgramatico;
  std::vector<CAssunto> ementa;
  int versao;

  // Public attribute accessor methods  



  /// 
  /// Set the value of codigo
  /// @param value the new value of codigo
  void setCodigo(CCodigoDisciplina value)
  {
    codigo = value;
  }

  /// 
  /// Get the value of codigo
  /// @return the value of codigo
  CCodigoDisciplina codigo()
  {
    return codigo;
  }

  /// 
  /// Set the value of nome
  /// @param value the new value of nome
  void setNome(string value)
  {
    nome = value;
  }

  /// 
  /// Get the value of nome
  /// @return the value of nome
  string nome()
  {
    return nome;
  }

  /// 
  /// Set the value of preRequisito
  /// @param value the new value of preRequisito
  void setPreRequisito(std::vector<CCodigoDisciplina> value)
  {
    preRequisito = value;
  }

  /// 
  /// Get the value of preRequisito
  /// @return the value of preRequisito
  std::vector<CCodigoDisciplina> preRequisito()
  {
    return preRequisito;
  }

  /// 
  /// Set the value of referencia
  /// @param value the new value of referencia
  void setReferencia(CReferenciaBibliografica value)
  {
    referencia = value;
  }

  /// 
  /// Get the value of referencia
  /// @return the value of referencia
  CReferenciaBibliografica referencia()
  {
    return referencia;
  }

  /// 
  /// Set the value of sistemaAvaliacao
  /// @param value the new value of sistemaAvaliacao
  void setSistemaAvaliacao(std::vector<ETipoAvaliacao> value)
  {
    sistemaAvaliacao = value;
  }

  /// 
  /// Get the value of sistemaAvaliacao
  /// @return the value of sistemaAvaliacao
  std::vector<ETipoAvaliacao> sistemaAvaliacao()
  {
    return sistemaAvaliacao;
  }

  /// 
  /// Set the value of conteudoProgramatico
  /// @param value the new value of conteudoProgramatico
  void setConteudoProgramatico(string value)
  {
    conteudoProgramatico = value;
  }

  /// 
  /// Get the value of conteudoProgramatico
  /// @return the value of conteudoProgramatico
  string conteudoProgramatico()
  {
    return conteudoProgramatico;
  }

  /// 
  /// Set the value of ementa
  /// @param value the new value of ementa
  void setEmenta(std::vector<CAssunto> value)
  {
    ementa = value;
  }

  /// 
  /// Get the value of ementa
  /// @return the value of ementa
  std::vector<CAssunto> ementa()
  {
    return ementa;
  }

  /// 
  /// Set the value of versao
  /// @param value the new value of versao
  void setVersao(int value)
  {
    versao = value;
  }

  /// 
  /// Get the value of versao
  /// @return the value of versao
  int versao()
  {
    return versao;
  }

  void initAttributes();

};

#endif // CEMENTADISCIPLINA_H

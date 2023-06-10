#ifndef CProblema_H
#define CProblema_H

#include <string>
#include <vector>

/// A classe CProblema se refere a um problema que precisa ser resolvido.
/// Tem a descrição do problema de forma objetiva.
class CProblema
{
public:
  /// Empty Constructor
  CProblema();

  /// Empty Destructor
  virtual ~CProblema();

  /// @return std::string
  std::string DescricaoDoProblema()
  {
    std::cout << "\nInstruções: Descreva o problema a ser resolvido."
              << "\nSempre focando em problemas associados ao curso (no nosso caso de engenharia).";
    return escopo;
  }

  /// @return std::string
  std::string DesenvolvimentoDaSolucao()
  {
  }

  /// @return std::string
  std::string DescricaoDaSolucao()
  {
  }


  /// 
  void ChecarAssuntosNaEmenta()
  {
  }

private:
  // Private attributes  


  std::string escopo;

  // Public attribute accessor methods  



  /// 
  /// Set the value of escopo
  /// @param value the new value of escopo
  void Escopo(std::string value)
  {
    escopo = value;
  }

  /// 
  /// Get the value of escopo
  /// @return the value of escopo
  std::string Escopo()
  {
    return escopo;
  }
};
#endif // CProblema_H

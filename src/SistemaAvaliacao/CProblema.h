
#ifndef CPROBLEMA_H
#define CPROBLEMA_H

#include <string>
#include <vector>


class CProblema
{
public:
  /// Empty Constructor
  CProblema();

  /// Empty Destructor
  virtual ~CProblema();

  /// @return string
  string DescricaoDoProblema()
  {
    std::cout << "\nInstruções: Descreva o problema a ser resolvido."
              << "\nSempre focando em problemas de engenharia.";
    return escopo;
  }

  /// @return string
  string DesenvolvimentoDaSolucao()
  {
  }

  /// @return string
  string DescricaoDaSolucao()
  {
  }


  /// 
  void ChecarAssuntosNaEmenta()
  {
  }

private:
  // Private attributes  


  string escopo;

  // Public attribute accessor methods  



  /// 
  /// Set the value of escopo
  /// @param value the new value of escopo
  void setEscopo(string value)
  {
    escopo = value;
  }

  /// 
  /// Get the value of escopo
  /// @return the value of escopo
  string escopo()
  {
    return escopo;
  }

  void initAttributes();

};

#endif // CPROBLEMA_H

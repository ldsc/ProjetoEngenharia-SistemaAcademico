#ifndef CCodigoAreaConhecimento_H
#define CCodigoAreaConhecimento_H

#include <iostream>
#include <string>
#include <string_view>

/// Representa o código de uma área de conhecimento.
// O código segue o padrão "n.nn.nn.nn-n", como exemplo: 1.00.00.00-3.
// A seguir uma amostra da
// Tabela de Áreas do Conhecimento
// 1.00.00.00-3 Ciências Exatas e da Terra
// 1.01.00.00-8 Matemática
// 1.01.01.00-4 Álgebra
// 1.01.01.01-2 Conjuntos
// 1.01.01.02-0 Lógica Matemática
// O código só pode ser criado pela classe gestora, de forma que será sempre um código válido.
// Com o código posso acessar a descrição.
class CCodigoAreaConhecimento
{
  /// Código da área do conhecimento.
  std::string codigo;

public:
  /// Padrão para código da area do conhecimento.
  static std::string_view padraoCodigo;

private:
  /// Construtor privado, só pode ser acessado pelo gestor, classe CGestorAreaConhecimento.
  /// Construtor sobrecarregado, o gestor gera o código.
  CCodigoAreaConhecimento(const std::string _codigo): codigo(_codigo)  { }

  /// Fornece a classe CGestorAreaConhecimento acesso as funcionalidades de CCodigoAreaConhecimento.
  // Na prática apenas o gestor vai poder criar um CCodigoAreaConhecimento.
  friend class CGestorAreaConhecimento;

public:
  /// Retorna padrão para o código da area do conhecimento.
  static std::string_view PadraoCodigo() { return padraoCodigo; }

  /// Retorna código area do conhecimento.
  std::string Codigo()                { return codigo; }

  /// Retorna descrição da área do conhecimento.
  std::string Descricao();
  /// Retorna descrição da área do conhecimento.
  std::string CodigoDescricao()       { return codigo + " " + Descricao(); };

  /// Retorna código area do conhecimento.
  std::string operator()()            { return codigo; }

  /// Converte o objeto CCodigoAreaConhecimento numa string.
  operator std::string()              { return codigo; }

  /// Converte o objeto CCodigoAreaConhecimento numa string.
  operator std::pair<std::string,std::string>() { return {codigo,Descricao()}; }

  /// Sobrecarga do operador de redirecionamento <<. Uso cout << codigo;
  friend std::ostream& operator<<(std::ostream& os, CCodigoAreaConhecimento& codigo) {
    os << codigo.codigo /*<< ' ' << codigo.descricao;*/;
    return os;
  }
};
#endif // CCodigoAreaConhecimento_H

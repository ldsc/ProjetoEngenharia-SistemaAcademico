#ifndef CCodigoDisciplina_H
#define CCodigoDisciplina_H

#include <iostream>
//#include <fstream>
#include <string>
#include <string_view>
//#include "CVerificaPadrao.h"

/// Representa o código de uma ementa/disciplina.
// O código segue o padrão "ccc-nnnn",
// sigla do departamente com 3 letras e número da disciplina com 4 números.
// como exemplo: LEP-0012.
// Note que é constante, após criado não pode ser modificado.
class CCodigoDisciplina
{
  /// Código da disciplina.
  /*const*/ std::string codigoDisciplina;

public:
  /// Padrão para código de disciplina.
  static const std::string_view padrao;

private:
  /// Construtor privado, só pode ser acessado pelo gestor, classe CGestorCodigoDisciplina.
  /// Construtor sobrecarregado, o gestor gera o código.
  explicit CCodigoDisciplina( std::string _codigoDisciplina)
    : codigoDisciplina (_codigoDisciplina) { }

  /// Construtor de cópia.
  explicit CCodigoDisciplina(CCodigoDisciplina& _codigoDisciplina)
    : codigoDisciplina (_codigoDisciplina.ToString()) { }

  /// Construtor move.
  explicit CCodigoDisciplina(const CCodigoDisciplina&& _codigoDisciplina)
  : codigoDisciplina(std::move(_codigoDisciplina.codigoDisciplina)) {};

// public:
   CCodigoDisciplina& operator=(CCodigoDisciplina& _codigoDisciplina) {
      this->codigoDisciplina = _codigoDisciplina.codigoDisciplina;
      return *this;
   }

public:
  /// Retorna padrão para o código de disciplina.
  static const std::string_view PadraoCodigoDisciplina() { return padrao;  }

  /// Retorna código disciplina.
  const std::string ToString()         const { return codigoDisciplina;  }

  /// Retorna código disciplina.
  const std::string operator()()       const { return codigoDisciplina;  }

  /// Converte o objeto CCodigoDisciplina numa string.
  operator const std::string()         const { return codigoDisciplina;  }

  /// Sobrecarga do operador de redirecionamento <<. Uso cout << codigoDisciplina;
  friend std::ostream& operator<<(std::ostream& os, CCodigoDisciplina& codigo) {
    os << codigo.codigoDisciplina;
    return os;
  }

// private:
//   /// Altera o valor do código, só pode ser acessado pelas classes amigas.
//   void CodigoDisciplina(std::string _codigo) { codigoDisciplina = _codigo;  }
  /// Fornece a classe CGestorCodigoDisciplina acesso as funcionalidades de CCodigoDisciplina.
  // Na prática apenas o gestor vai poder criar um CCodigoDisciplina.
  friend class CGestorCodigoDisciplina;
  //friend CEmentaDisciplina::CEmentaDisciplina(CCodigoDisciplina& _codigo);
  friend class CEmentaDisciplina; //novo
  friend class CGestorEmentaDisciplina; //novo
};
#endif // CCodigoDisciplina_H

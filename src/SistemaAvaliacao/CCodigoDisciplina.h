#ifndef CCodigoDisciplina_H
#define CCodigoDisciplina_H

#include <iostream>
//#include <fstream>
#include <string>
#include <string_view>
//#include "CVerificaPadrao.h"

/// Representa o código de uma ementa/disciplina.
// O código segue o padrão "xxx-nnnn",
// sigla do departamente com 3 letras e número da disciplina com 4 números.
// como exemplo: LEP-0012.
class CCodigoDisciplina
{
  /// Código da disciplina.
  std::string codigoDisciplina {"xxx-nnnn"};

public:
  /// Padrão para código de disciplina.
  static std::string_view padrao;

private:
  /// Construtor privado, só pode ser acessado pelo gestor, classe CGestorCodigoDisciplina.
  /// Construtor sobrecarregado, o gestor gera o código.
  CCodigoDisciplina(std::string _codigoDisciplina) { codigoDisciplina = _codigoDisciplina; }

  /// Fornece a classe CGestorCodigoDisciplina acesso as funcionalidades de CCodigoDisciplina.
  // Na prática apenas o gestor vai poder criar um CCodigoDisciplina.
  friend class CGestorCodigoDisciplina;

  // /// Valida o codigo da disciplina (verifica se atende o padrão).
  // // O ideal é verificar na tabela de códigos! Aqui verifica apenas o padrão!
  // bool ValidaCodigo(CCodigoDisciplina& _codigoDisciplina)      {
  //   if ( CVerificaPadrao::AtendePadrao(_codigoDisciplina,"ccc-nnnn" )
  //     std::cout << "\nAtende o padrão.\n";
  //   else
  //     std::cout << "\nNão atende o padrão.\n";
  // }
public:
  /// Retorna padrão para o código de disciplina.
  static std::string_view PadraoCodigoDisciplina() { return padrao;  }

  /// Retorna código disciplina.
  std::string CodigoDisciplina()      { return codigoDisciplina;  }

  /// Retorna código disciplina.
  std::string operator()()            { return codigoDisciplina;  }

  /// Converte o objeto CCodigoDisciplina numa string.
  operator std::string()              { return codigoDisciplina;  }

  /// Sobrecarga do operador de redirecionamento <<. Uso cout << codigoDisciplina;
  friend std::ostream& operator<<(std::ostream& os, CCodigoDisciplina& codigo) {
    os << codigo.codigoDisciplina;
    return os;
  }
};
#endif // CCodigoDisciplina_H

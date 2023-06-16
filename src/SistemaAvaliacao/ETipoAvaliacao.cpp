#include "ETipoAvaliacao.h"

ETipoAvaliacao& operator++(ETipoAvaliacao& ta) {
  if(ta == ETipoAvaliacao::semAvaliacao)
    ta = ETipoAvaliacao::provaObjetivaMultiplaEscolha;
  else
    ta = static_cast<ETipoAvaliacao>(int(ta)+1);
  return ta;
  // switch (ta) {
  // case ETipoAvaliacao::provaObjetivaMultiplaEscolha:
  //   return ;
  // case ETipoAvaliacao::provaEscritaDiscursiva:
  //   return ;
  // case ETipoAvaliacao::provaComputador:
  //   return ;
  // case ETipoAvaliacao::provaOral:
  //   return ;
  // case ETipoAvaliacao::listaExercicios:
  //   return ;
  // case ETipoAvaliacao::projeto:
  //   return ;
  // case ETipoAvaliacao::trabalhoDeCampo:
  //   return ;
  // case ETipoAvaliacao::avaliacaoTurma:
  //   return ;
}

/// Dado um tipo de avaliação (número) retorna o nome associado (texto).
std::string ToString(const ETipoAvaliacao& ta) {
  switch (ta) {
  case ETipoAvaliacao::provaObjetivaMultiplaEscolha:
    return "Prova Objetiva Multipla Escolha";
  case ETipoAvaliacao::provaEscritaDiscursiva:
    return "Prova Escrita Discursiva";
  case ETipoAvaliacao::provaComputador:
    return "Prova Computador";   
  case ETipoAvaliacao::provaOral:
    return "Prova Oral";
  case ETipoAvaliacao::listaExercicios:
    return "Lista Exercicios";
  case ETipoAvaliacao::projeto:
    return "Projeto";
  case ETipoAvaliacao::trabalhoDeCampo:
    return "Trabalho de Campo";
  case ETipoAvaliacao::avaliacaoTurma:
    return "Avaliacao Turma";
  case ETipoAvaliacao::semAvaliacaoSomentePresenca:
    return "Sem Avaliacao Somente Presenca";
  default: return "Prova Escrita Discursiva";
  }
}

std::ostream& operator<<(std::ostream&os,ETipoAvaliacao&ta) {
  os << ToString(ta) ;
  return os;
}

/// Dado um tipo de avaliação (texto) retorno o número associado.
ETipoAvaliacao TipoAvaliacao(std::string& tipo) {
  if      ( tipo == "Prova Objetiva Multipla Escolha" )
   return ETipoAvaliacao::provaObjetivaMultiplaEscolha;
  else if ( tipo == "Prova Escrita Discursiva" )
    return ETipoAvaliacao::provaEscritaDiscursiva;
  else if ( tipo == "Prova Computador" )
    return ETipoAvaliacao::provaComputador;
  else if ( tipo == "Prova Oral" )
    return ETipoAvaliacao::provaOral;
  else if ( tipo == "Lista Exercicios" )
    return ETipoAvaliacao::listaExercicios;
  else if ( tipo == "Projeto" )
    return ETipoAvaliacao::projeto;
  else if ( tipo == "Trabalho De Campo" )
    return ETipoAvaliacao::trabalhoDeCampo;
  else if ( tipo == "Avaliacao Turma" )
    return ETipoAvaliacao::avaliacaoTurma;
  else if ( tipo ==  "Sem Avaliacao Somente Presenca" )
    return ETipoAvaliacao::semAvaliacaoSomentePresenca;
return ETipoAvaliacao::provaEscritaDiscursiva; // default
}

void ListarTiposAvaliacoes() {
 std::cout << "\nLista com os tipos de avaliações:\n";
 for(ETipoAvaliacao tipo = ETipoAvaliacao::provaObjetivaMultiplaEscolha;
     tipo < ETipoAvaliacao::semAvaliacao; ++tipo)
     std::cout << ToString(tipo) << "\n";
}

ETipoAvaliacao MenuSelecaoTipoAvaliacao(){
 std::cout << "\nMenu de seleção do tipo de avaliação:\n";
 for(ETipoAvaliacao tipo = ETipoAvaliacao::provaObjetivaMultiplaEscolha; tipo < ETipoAvaliacao::semAvaliacao; ++tipo)
     std::cout  << std::left << std::setw(35) << std::setfill('.') << ToString(tipo)
                << static_cast<int>(tipo) << "\n";
 int selecao{};
 std::cin >> selecao; std::cin.get();
 return static_cast<ETipoAvaliacao>(selecao);
 //return ETipoAvaliacao{selecao};
}

#ifndef ETipoAvaliacao_H
#define ETipoAvaliacao_H

#include <iomanip>
#include <string>
//#include <vector>

/// Define enumeração com os tipos de avaliações.
enum class ETipoAvaliacao : short int {
    provaObjetivaMultiplaEscolha,
    provaEscritaDiscursiva,
    provaComputador,
    provaOral,
    listaExercicios,
    projeto,
    trabalhoDeCampo,
    avaliacaoTurma,
    semAvaliacao
};

ostream& operator<<(ostream&os,ETipoAvaliacao&ta) {
  os << TipoAvaliacao(ta) ;
}

/// Dado um tipo de avaliação (número) retorna o nome associado (texto).
std::string TipoAvaliacao(ETipoAvaliacao& ta) {
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
  }
}

/// Dado um tipo de avaliação (texto) retorno o número associado.
ETipoAvaliacao TipoAvaliacao(std::string& tipo) {
  if (tipo == "Prova Objetiva Multipla Escolha" )
   return ETipoAvaliacao::provaObjetivaMultiplaEscolha:
  else if (tipo == "Prova Escrita Discursiva" )
    return ETipoAvaliacao::provaEscritaDiscursiva;
  else if (tipo == "Prova Computador" )
    return ETipoAvaliacao::provaComputador;
  else if (tipo == "Prova Oral" )
    return ETipoAvaliacao::provaOral;
  else if (tipo == "Lista Exercicios" )
    return ETipoAvaliacao::listaExercicios;
  else if (tipo == "Projeto" )
    return ETipoAvaliacao::projeto;
  else if (tipo == "Trabalho De Campo" )
    return ETipoAvaliacao::trabalhoDeCampo;
  else if (tipo == "Avaliacao Turma" )
    return ETipoAvaliacao::avaliacaoTurma;
}

void ListarTiposAvaliacoes() {
 cout << "\nLista com os tipos de avaliações:\n";
 for(ETipoAvaliacao tipo = ETipoAvaliacao::provaObjetivaMultiplaEscolha;
     tipo < semAvaliacao+1; tipo++)
     cout << TipoAvaliacao(tipo) << "\n";
}

ETipoAvaliacao MenuSelecaoTipoAvaliacao(){
 cout << "\nMenu de seleção do tipo de avaliação:\n";
 for(ETipoAvaliacao tipo = ETipoAvaliacao::provaObjetivaMultiplaEscolha; tipo < semAvaliacao+1; tipo++)
     std::cout  << std::setw(50) << std::setfill('.') << TipoAvaliacao(tipo)
                << static_cast<int>(tipoAvaliacao) << "\n";
 shirt int selecao{};
 std::cin >> selecao; std::cin.get();
 return static_cast<ETipoAvaliacao>(selecao);
 //return ETipoAvaliacao{selecao};
}

#endif // ETipoAvaliacao_H

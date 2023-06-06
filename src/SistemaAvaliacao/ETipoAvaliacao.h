#ifndef ETIPOAVALIACAO_H
#define ETIPOAVALIACAO_H

#include <string>
//#include <vector>

enum class ETipoAvaliacao : short int {
    provaObjetivaMultiplaEscolha,
    provaEscritaDiscursiva,
    provaComputador,
    provaOral,
    listaExercicios,
    projeto,
    trabalhoDeCampo,
    avaliacaoTurma
};

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
    return "Trabalho De Campo";
  case ETipoAvaliacao::avaliacaoTurma:
    return "Avaliacao Turma";
  }
}
#endif // ETIPOAVALIACAO_H

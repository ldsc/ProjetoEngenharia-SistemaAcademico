#ifndef ETipoAvaliacao_H
#define ETipoAvaliacao_H

#include <iostream>
#include <iomanip>
#include <string>
//#include <vector>

/// Define enumeração com os tipos de avaliações.
enum class ETipoAvaliacao :  int {
    provaObjetivaMultiplaEscolha,
    provaEscritaDiscursiva,
    provaComputador,
    provaOral,
    provaPraticaLaboratorio,
    listaExercicios,
    projeto,
    trabalhoDeCampo,
    avaliacaoTurma,
    semAvaliacaoSomentePresenca,
    semAvaliacao
};

/// Incrementa o tipo de avaliação para próximo valor;
ETipoAvaliacao& operator++(ETipoAvaliacao& ta) ;

/// Dado um tipo de avaliação (número) retorna o nome associado (texto).
std::string ToString(const ETipoAvaliacao& ta);

/// Converte para string e redireciona para ostream.
std::ostream& operator<<(std::ostream&os,ETipoAvaliacao&ta);

/// Dado um tipo de avaliação (texto) retorna  um ETipoAvaliacao.
ETipoAvaliacao TipoAvaliacao(std::string& tipo) ;

/// Lista com os tipos de avaliações.
void ListarTiposAvaliacoes() ;

/// Menu de seleção do tipo de avaliação.
ETipoAvaliacao MenuSelecaoTipoAvaliacao();

#endif // ETipoAvaliacao_H

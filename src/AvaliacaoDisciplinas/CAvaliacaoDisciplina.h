#ifndef CAvaliacaoDisciplina_H
#define CAvaliacaoDisciplina_H

#include <iostream>     // Entrada e saida

#include "CAvaliacao.h" // Classe que representa uma dada avaliacao de disciplina da UENF.

/// Classe de avaliacao da disciplina, contem vetor com avaliacoes.
class CAvaliacaoDisciplina
{
 private:
  std::string nomeProfessor = "";   //< Nome do professor
  std::string nomeDisciplina = "";  //< Nome da disciplina
  std::vector<CAvaliacao> aluno;    //< Cada aluno uma avaliacao
  std::vector<double> media;        //< Vetor com as medias das avaliacoes de cada pergunta

public:
  /// Construtor. 
  CAvaliacaoDisciplina(){ }
  
  /// Destrutor.
  ~CAvaliacaoDisciplina(){}

  /// Solicita dados iniciais da disciplina.
  void EntradaDados();

  /// Avalia a disciplina, notas dadas pelos alunos.
  void Avaliar();

  /// Calcula a media das notas dadas pelos alunos.
  void Media();

  /// Gera dados para gráfico e Plota resultados.
  void Plotar() const;

  /// Retorna nome da disciplina e do professor.
  std::string Nome() const { return nomeDisciplina + "_" + nomeProfessor; }

  /// Saída dos dados do objeto para ostream
  void SaidaDados (std::ostream& out);
  
  /// Sobrecarga operador<< (salva dados em disco).
  friend std::ostream& operator<<(std::ostream& out, CAvaliacaoDisciplina& obj);
};
#endif

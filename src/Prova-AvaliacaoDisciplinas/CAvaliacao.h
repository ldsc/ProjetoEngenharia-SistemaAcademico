#ifndef CAvaliacao_H
#define CAvaliacao_H

#include <string>	// Uso de strings
#include <vector>	// Uso de vetores
#include <iostream>	// Uso de cin/cout
#include <fstream>	// Uso de ifstream(fin) e ofstream(fout) para acesso a arquivos disco

/// Classe que representa a avaliacao de uma disciplina
class CAvaliacaoDisciplina;

/// Classe que representa uma avaliacao individual (de um aluno)
class CAvaliacao
{
  // ---------------------------------------------------------------Atributos
 private:
  /// Vetor com as notas de cada item (nota de cada pergunta).
  std::vector<double> nota;     

  /// Codigo secreto do avaliador (evita dupla avaliacao).
  std::string codigoAvaliador{""};

  /// Comentário final do avaliador sobre a disciplina
  std::string comentario{""};

public:
  /// Vetor estatico com as perguntas (mesmas perguntas para todos os avaliadores).
  static std::vector<std::string> pergunta;

public:
  // ---------------------------------------------------------------Metodos
  /// Construtor
  CAvaliacao ();

  /// Destrutor
  virtual ~CAvaliacao ( ){}
  
  /// Obtem/recupera perguntas de um arquivo de disco
  static void LerPerguntasDisco(std::string nomeArquivo = "Perguntas.txt");

  /// Metodo de avaliacao, solicita as notas para cada pergunta
  void Avaliar();

  /// Retorna nota i
  double Nota(double i) const			{  return nota.at(i); }
  
  /// Retorna nota i (a sobrecarga operador[] permite usar aluno[i] para obter nota i do aluno)
  double operator[](double i)   const      	{  return nota.at(i); }

  /// Seta codigo do avaliador
  void CodigoAvaliador(std::string c)   	{  codigoAvaliador = c; }

  /// Retorna codigo do avaliador
  std::string CodigoAvaliador() const        	{  return codigoAvaliador; }

  /// Retorna comentario
  std::string Comentario() const       		{  return comentario; }

  /// Saída dos dados
  void SaidaDados(std::ostream& out);

  /// Sobrecarga operador<<, envia dados para tela ou disco (o mesmo que Saida())
  //friend std::ofstream& operator<<(std::ofstream& out, const CAvaliacao& obj);
  friend std::ostream& operator<<(std::ostream& out, const CAvaliacao& obj);

  /// Classe amiga, tem acesso aos dados de CAvaliacao
  friend class CAvaliacaoDisciplina;
};
#endif 

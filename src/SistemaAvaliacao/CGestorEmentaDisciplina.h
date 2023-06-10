#ifndef CGestorEmentaDisciplina_H
#define CGestorEmentaDisciplina_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "CEstadoPersistente.h"
#include "CCodigoDisciplina.h"
#include "ETipoAvaliacao.h"
#include "CAssunto.h" //

/// A ementa da disciplina contém um conjunto extenso de informações
/// que são armazenadas em arquivos localizados em dados/EmentaDisciplina/
/// O nome dos arquivos armazenados é da forma CCodigoDisciplina-Ano-Semestre.
/// ex: LEP-0132-2023-1
class CGestorEmentaDisciplina: public CEstadoPersistente
{
private:
  CCodigoDisciplina codigoDisciplina;
  std::string nome;
  std::vector<CCodigoDisciplina> preRequisito;
  std::vector<std::string> referenciaBibliografica; // CReferenciaBibliografica referencia;
  std::vector<ETipoAvaliacao> tipoAvaliacao;
  std::string conteudoProgramatico;
  std::vector<CAssunto> assunto;
  std::pair<int,int> versao; // Versão da ementa <Ano,Semestre>

public:
  // Gestão da lista de disciplinas localizadas em dados/EmentaDisciplina/
  /// Caminho para diretório onde os dados serão armazenados.
  static std::string caminhoDiretorio;
  /// Map com código da disciplina e shared_ptr para ementas.
  static std::map<CCodigoDisciplina,shared_ptr<CGestorEmentaDisciplina> > map_codigoDisciplina_spEmentaDisciplina;

public:
  /// Construtor.
  CGestorEmentaDisciplina();

  /// Destrutor.
  virtual ~CGestorEmentaDisciplina();

  /// Define ou redefine toda a ementa.
  void DefinirEmenta();

  /// Define o código da disciplina.
  void DefinirCodigoDisciplina();

  /// Retorna o código da disciplina
  std::string CodigoDisciplina()   { return codigoDisciplina; }

  /// Define o nome da disciplina.
  void DefinirNomeDisciplina();

  /// Seta o nome da disciplina.
  void Nome(string value)   { nome = value; }

  /// Retorna o nome da disciplina.
  std::string Nome()        { return nome; }

  /// Seta vetor com  os pré-requisitos.
  void PreRequisito(std::vector<std::string>& value)
                            { preRequisito = value; }

  /// Retorna vetor com os pré-requisitos.
  std::vector<std::string> PreRequisito()
                            { return preRequisito; }

  /// Definir os pré-requisitos.
  void DefinirPreRequisito();

  // Depois trocar por CReferenciaBibliografica
  /// Seta vetor com as referencias bibliográficas.
  void ReferenciaBibliografica(std::vector<std::string>& value)
                            { referenciaBibliografica = value; }

  // CReferenciaBibliografica
  /// Retorna vetor com as referencias bibliográficas.
  std::vector<std::string> ReferenciaBibliografica()
                            { return referenciaBibliografica; }

  /// Definir a referencia bibliográfica.
  void DefinirReferenciaBibliografica();

  /// Seta vetor com sistema de avaliação.
  void TipoAvaliacao(std::vector<ETipoAvaliacao>& value)
                            { tipoAvaliacao = value; }
  /// Retorna vetor com tipoAvaliacao.
  std::vector<ETipoAvaliacao> TipoAvaliacao()
                            { return tipoAvaliacao; }

  /// Define o sistema de avaliação.
  void DefinirSistemaAvaliacao();

  /// Set the value of conteudoProgramatico
  /// @param value the new value of conteudoProgramatico
  void ConteudoProgramatico(std::string value)
                            { conteudoProgramatico = value; }

  /// Get the value of conteudoProgramatico
  /// @return the value of conteudoProgramatico
  std::string conteudoProgramatico()
                            { return conteudoProgramatico; }

   void DefinirConteudoProgramatico();

  /// A ementa é uma lista de assuntos.
  void Assunto(std::vector<CAssunto> value)
                            { assunto = value; }

  /// Returna a lista de assuntos num vetor
  std::vector<CAssunto> Assunto()
                            { return assunto; }

  /// Definir a lista de assuntos.
  void DefinirAssunto();

  /// Set the value of versao
  /// @param value the new value of versao
  void Versao(std::pair<int,int> ano_semestre)
                            { versao = ano_semestre; }

  /// Get the value of versao
  /// @return the value of versao
  std::pair<int,int> Versao()
                            { return versao; }

  /// Definir a versão da ementa (ano e semestre).
  void DefinirVersao();

  /// Salva um estado específico. caminhoDiretorio + nomeArquivo + identificadorEstado
  // O identificadorEstado é dado por Ano-Semestre
  virtual void SalvarEstado(std::string identificadorEstado = {});
  /// Recupera um estado específico. caminhoDiretorio + nomeArquivo + identificadorEstado
  // O identificadorEstado é dado por Ano-Semestre
  virtual void RecuperarEstado(std::string identificadorEstado = {});

  /// Visualizar, mostra ementa na tela.
  void Visualizar() { std::cout << *this; };

  /// Sobrecarga operador redirecionamento para cout ou fout.
  std::ostream& operator<<(std::ostream& os, CGestorEmentaDisciplina& ementa);
};
#endif // CGestorEmentaDisciplina_H

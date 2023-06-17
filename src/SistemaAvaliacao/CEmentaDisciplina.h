#ifndef CEmentaDisciplina_H
#define CEmentaDisciplina_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
//#include "CEstadoPersistente.h"
// #include "CCodigoDisciplina.h"
#include "CGestorCodigoDisciplina.h"
#include "ETipoAvaliacao.h"
// #include "CCodigoAreaConhecimento.h"
#include "CGestorAreaConhecimento.h"

//#include "CAssunto.h"

// Uma ementa pode estar sendo feita (rascunho), já foi finalizada mas ainda não foi aprovada, já foi aprovada(ativa), foi desativada.
// dados/EmentaDisciplina
// dados/EmentaDisciplina/rascunho/LEP-1523.dat
// dados/EmentaDisciplina/aguardandoAprovacao/LEP-1523.dat
// dados/EmentaDisciplina/ativa/LEP-1523.dat
// dados/EmentaDisciplina/desativa/LEP-1523-ano-semestre.dat

enum class EEstadoEmentaDisciplina : int { rascunho = 1, aguardandoAprovacao, ativa, desativa};


/// A ementa da disciplina contém um conjunto extenso de informações relacionados a disciplina.
/// Ela mesmo se salva em disco com um nome de arquivo que considera o estado, código, versao, nome.
class CEmentaDisciplina: public CEstadoPersistente
{
private:
  //CCodigoDisciplina codigoDisciplina;
  const std::string codigoDisciplina;
  EEstadoEmentaDisciplina estado {EEstadoEmentaDisciplina::rascunho};
  std::string nome;
  //std::vector<CCodigoAreaConhecimento> vCodigoAreaConhecimento;
  std::vector<std::string> vCodigoAreaConhecimento;
  //std::vector<CCodigoDisciplina> vPreRequisito;
  std::vector<std::string> vPreRequisito;
  std::vector<std::string> vReferenciaBibliografica; // CReferenciaBibliografica referencia;
  std::vector<ETipoAvaliacao> vTipoAvaliacao;
  std::string conteudoProgramatico;
  /// O Assunto deve estar relacionado a uma (ou mais) áreas de conhecimento e ter uma descrição.
  //std::vector<CAssunto> assunto;
  std::vector< std::pair<std::string, int> > vAssunto_CargaHoraria;
  std::pair<int,int> versao{0,0}; // Versão da ementa <Ano,Semestre>

public:
  // Gestão da lista de disciplinas localizadas em dados/EmentaDisciplina/
  /// Caminho para diretório onde os dados serão armazenados.
  //static std::string caminhoDiretorio;
  /// Map com código da disciplina e shared_ptr para ementas. CEmentaDisciplina::mCodigoEmenta.
  //ps: O valor poderia apontar para uma path...
  // static std::map<CCodigoDisciplina,shared_ptr<CEmentaDisciplina> > map_codigoDisciplina_spEmentaDisciplina;

private:
public:
  /// Construtor. Recebe o código da disciplina, pode ser um código novo ou existente.
  //CEmentaDisciplina(CCodigoDisciplina& _codigo);
  explicit CEmentaDisciplina(const std::string& _codigo);
  // /// Construtor. O código precisa ser passado posteriormente. Usada para modificar uma ementa existente.
  // CEmentaDisciplina();

  friend class CGestorEmentaDisciplina;

public:
  /// Destrutor.
  virtual ~CEmentaDisciplina();

private:
  /// Menu de revisão, permite alterar itens específicos.
  void MenuRevisao();

  /// Define toda a ementa.
  void Definir();

  /// Define o código da disciplina.
  //void DefinirCodigoDisciplina();

  /// Visualizar o estado da ementa.
  void VisualizarEstado();

  /// Define o estado da disciplina.
  void DefinirEstado();

  /// Retorna o código da disciplina.
  std::string CodigoDisciplina()   { return codigoDisciplina; }

  /// Define o nome da disciplina.
  void DefinirNomeDisciplina();

  /// Seta o nome da disciplina.
  void Nome(std::string value)   { nome = value; }

  /// Retorna o nome da disciplina.
  std::string Nome()        { return nome; }

  /// Define os códigos das áreas de conhecimento (vetor).
  void DefinirCodigoAreaConhecimento();
  /// Define os códigos das áreas de conhecimento (vetor).
  void DefinirCodigoAreaConhecimento(CGestorAreaConhecimento& gestorAreaConhecimento);

  /// Seta o código da área de conhecimento (vetor).
  //void CodigoAreaConhecimento(std::vector<CCodigoAreaConhecimento>  value)   { vCodigoAreaConhecimento = value; }
  void CodigoAreaConhecimento(std::vector<std::string>  value)   { vCodigoAreaConhecimento = value; }

  /// Retorna o vetor com os códigos das áreas de conhecimento.
  //std::vector<CCodigoAreaConhecimento>  CodigoAreaConhecimento()        { return vCodigoAreaConhecimento; }
  std::vector<std::string>  CodigoAreaConhecimento()        { return vCodigoAreaConhecimento; }

  /// Definir os pré-requisitos.
  void DefinirPreRequisito(/*CGestorCodigoDisciplina& gestorCodigoDisciplina*/);

  /// Seta vetor com  os pré-requisitos.
  void PreRequisito(std::vector<std::string>& value) { vPreRequisito = value; }

  /// Retorna vetor com os pré-requisitos.
  std::vector<std::string> PreRequisito() { return vPreRequisito; }

  /// Definir a referencia bibliográfica.
  void DefinirReferenciaBibliografica();

  // Depois trocar por CReferenciaBibliografica
  /// Seta vetor com as referencias bibliográficas.
  void ReferenciaBibliografica(std::vector<std::string>& value)
                            { vReferenciaBibliografica = value; }

  // CReferenciaBibliografica
  /// Retorna vetor com as referencias bibliográficas.
  std::vector<std::string> ReferenciaBibliografica()
                            { return vReferenciaBibliografica; }

  /// Define o sistema de avaliação.
  void DefinirSistemaAvaliacao();

  /// Seta vetor com sistema de avaliação.
  void TipoAvaliacao(std::vector<ETipoAvaliacao>& value)
                            { vTipoAvaliacao = value; }

  /// Retorna vetor com vTipoAvaliacao.
  std::vector<ETipoAvaliacao> TipoAvaliacao()
                            { return vTipoAvaliacao; }

  ///  Define o conteudo programatico
  void DefinirConteudoProgramatico();

  /// Seta conteudoProgramatico.
  void ConteudoProgramatico(std::string value)
                            { conteudoProgramatico = value; }

  /// Retorna conteudoProgramatico.
  std::string ConteudoProgramatico()
                            { return conteudoProgramatico; }


  /// Definir a lista de assuntos.
  void DefinirAssunto();

  /// A ementa é uma lista de assuntos.
  void Assunto(std::vector< std::pair<std::string,int> > value)
                            { vAssunto_CargaHoraria = value; }

  /// Returna a lista de assuntos num vetor
  std::vector< std::pair<std::string,int> > Assunto()
                            { return vAssunto_CargaHoraria; }

  /// Seta versão.
  void Versao(std::pair<int,int> ano_semestre)
                            { versao = ano_semestre; }

  /// Definir a versão da ementa (ano e semestre).
  void DefinirVersao();

  /// Retorna versão.
  std::pair<int,int> Versao()
                            { return versao; }

  /// Visualizar, mostra ementa na tela.
  void Visualizar() { std::cout << *this; };

  /// Sobrecarga operador redirecionamento para cout ou fout.
  friend std::ofstream& operator<<(std::ofstream& os, const CEmentaDisciplina& ementa);
  friend std::ostream&  operator<<(std::ostream& os, const CEmentaDisciplina& ementa);

  // ----------- Do estado CEstadoPersistente .h
  virtual void CaminhoDiretorio(const std::filesystem::path& _caminhoDiretorio) override;
  virtual const std::filesystem::path&  CaminhoDiretorio() const override;
  virtual void NomeArquivo(const std::filesystem::path& _nomeArquivo)  override;
  virtual const std::filesystem::path& NomeArquivo() const   override;

protected:
  /// Salva estado do objeto ou dados associados no arquivo com a path completa.
  virtual bool SalvarArquivo(std::filesystem::path caminhoCompleto) const override;
  /// Salva estado do objeto ou dados associados no arquivo com a path completa.
  virtual bool RecuperarArquivo(std::filesystem::path caminhoCompleto) override;
};
#endif // CEmentaDisciplina_H

#ifndef CGestorEmentaDisciplina_H
#define CGestorEmentaDisciplina_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include <filesystem>
#include "CEstadoPersistente.h"
// #include "CCodigoDisciplina.h"
// #include "CGestorCodigoDisciplina.h"
#include "CEmentaDisciplina.h"

/// Gerencia as ementas das disciplinas.
class CGestorEmentaDisciplina
{
  bool ementaAtivaModificada = false;

public:
  // Gestão da lista de disciplinas localizadas em dados/EmentaDisciplina/
  /// Caminho para diretório onde os dados serão armazenados.
  static std::filesystem::path caminhoDiretorio;

  static std::filesystem::path nomeArquivo;
  /// Map com código da disciplina e path para ementas.
  //static std::map<CCodigoDisciplina,std::filesystem::path > map_codigoDisciplina_path;

  /// Map com código da disciplina e ementas.
  //static std::map<CCodigoDisciplina,CEmentaDisciplina > map_codigoDisciplina_ementa;
  std::shared_ptr<CEmentaDisciplina> ementa;

public:
  /// Construtor.
  explicit CGestorEmentaDisciplina();

  /// Destrutor.
  virtual ~CGestorEmentaDisciplina();

  // Menu com opções do gestor de ementas.
  void Menu() ;

  /// Criar ementa, cria ementa nova, zerada, ou modifica uma existente.
  void CriarEmenta();
  /// Carrega ementa do disco.
  void CarregarEmentaDisco();
  /// Definir ementa vai pedir, um a um os dados da ementa.
  void DefinirEmenta();
  /// Revisar ementa permite alterar as informações da ementa (a ementa já existe). Vai perguntar o que quer atualizar.
  void RevisarEmenta();
  /// Ativar ementa muda o estado da ementa para  ativa, requer aprovação nos conselhos.
  void AtivarEmenta();
  /// Desativar ementa. Quando a disciplina deixa de existir. É movida para diretório de ementas inativas.
  void DesativarEmenta();
  /// Lista as ementas
  void ListarEmentas();
  /// Visualiza uma ementa específica
  void VisualizarEmenta();
  /// Salva  a ementa no disco (o estado define o diretório)
  void SalvarEmenta();

private:
  /// Se a ementa ativa foi modificada pergunta se é para salvar.
  void VerificarSeEParaSalvar();
};
#endif // CGestorEmentaDisciplina_H

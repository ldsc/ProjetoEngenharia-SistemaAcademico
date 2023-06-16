#ifndef CGestorCodigoDisciplina_H
#define CGestorCodigoDisciplina_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "CEstadoPersistente.h"
#include "CCodigoDisciplina.h"

/// Gerencia os códigos das disciplinas.
// Cada laboratório tem uma sigla de 3 letras, como exemplo: LEP.
// Cada disciplina do laboratório tem um número, como exemplo: 0123.
/// O código das disciplinas segue um padrão: ccc-nnnn ex: LEP-0123.
// Para gerar um novo código temos de verificar qual o último código utilizado.
// Soluções:
// 1: Arquivo único com o próximo código disponível.
// ex: dados/TabelaCodigoDisciplina/mapSiglaCodigo-.dat com o conteudo.
// LEP 130
// FIS 75
// -> LEP-0130 se criar uma nova disciplina o código será LEP-0131.
// -> FIS-0075 neste caso, 0075 é o último código utilizado...
// Podemos usar um std::map<std::string,int> map_ultimoCodigoUsado;

// 2: O diretório dados/TabelaCodigoDisciplina/ tem arquivos, MTM.dat, FIS.dat, LEP.dat com a lista de códigos das disciplinas por laboratório (ordenado).
// Neste caso o arquivo tem a lista de todos os códigos utilizados e o nome da disciplina.
class CGestorCodigoDisciplina: public CEstadoPersistente
{
public:
  /// Caminho para diretório onde os dados serão armazenados.
  static std::string caminhoDiretorio;
  /// Nome do arquivo onde os dados serão armazenados.
  static std::string nomeArquivo;
  /// Map com as siglas dos laboratórios e código disponibilizado. O código vai crescendo de 0001 até 9999.
  static std::map<const std::string,int> map_ultimoCodigoUsado;

public:
  /// Construtor, recupera o último estado armazenado em disco, recuperando a tabela com sigla dos departamentos e último código utilizado.
  explicit CGestorCodigoDisciplina() ;

  /// Construtor, recupera um estado especifico (ex: um backup).
  explicit CGestorCodigoDisciplina(const std::string identificadorEstado);

  /// Destrutor, salva em arquivo os dados dos códigos utilizados/criados.
  virtual ~CGestorCodigoDisciplina();

  /// Adiciona um novo departamento.
  static void AdicionarDepartamento();

  // Se informar nome de departamento existente desconsidera e emite alerta.
  static void AdicionarDepartamento(const std::string siglaDepartamento, const int codigoInicial = 0);

  /// Define o código da disciplina pede a sigla do departamento.
  static CCodigoDisciplina CriarCodigoDisciplina();

  /// Define o código da disciplina com base na sigla do departamento.
  /// Também poderia alterar e já modificar o arquivo (+seguro).
  static CCodigoDisciplina CriarCodigoDisciplina(const std::string siglaDepartamento);
  
  /// Define o código da disciplina com base em código pré-existente.
  static CCodigoDisciplina RetornarCodigoDisciplinaExistente(const std::string sCodigoDisciplina) ;

  /// @return bool
  //...no caso da universidade ter um padrão de código a verificar...
  //bool VerificarCodigo(std::string codigoASerVerificado) ;

  // /// Recebe sigla departamento e gera código disciplina. ex: codigo = gestorCodigo(siglaDepartamento);
  static CCodigoDisciplina  operator()(const std::string siglaDepartamento)
     { return CriarCodigoDisciplina(siglaDepartamento); }

  /// Visualizar tabela codigos.
  static void VisualizarTabelaDepartamentoUltimoCodigo() ;
  static void Visualizar()  { VisualizarTabelaDepartamentoUltimoCodigo(); };

  // Implementa Métodos da classe persistente
public:
  /// Seta caminho para o diretório com os arquivos siglaDepartamento - código usado.
  virtual void CaminhoDiretorio(const std::string _caminhoDiretorio)  { caminhoDiretorio = _caminhoDiretorio; };
  /// Retorna caminho para o diretório com os arquivos siglaDepartamento - código usado.
  virtual const std::string  CaminhoDiretorio()  const                      { return caminhoDiretorio; };
  /// Seta nome arquivo com a base de dados.
  virtual void NomeArquivo(const std::string _nomeArquivo)            { nomeArquivo = _nomeArquivo; };
  /// Retorna nome arquivo com a base de dados.
  virtual const std::string  NomeArquivo()    const                         { return nomeArquivo; }
  /// Salva um estado específico. caminhoDiretorio + nomeArquivo + identificadorEstado
  virtual void SalvarEstado(const std::string identificadorEstado = {}) const;
  /// Recupera um estado específico. caminhoDiretorio + nomeArquivo + identificadorEstado
  virtual void RecuperarEstado(std::string identificadorEstado = {});
};
#endif // CGestorCodigoDisciplina_H

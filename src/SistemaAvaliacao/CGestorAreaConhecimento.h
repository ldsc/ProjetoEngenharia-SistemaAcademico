#ifndef CGestorAreaConhecimento_H
#define CGestorAreaConhecimento_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <map>
#include "CEstadoPersistente.h"
#include "CCodigoAreaConhecimento.h"

/// Gerencia as areas de conhecimento.
// O código segue o padrão "n.nn.nn.nn-n", como exemplo: 1.00.00.00-3.
// A seguir uma amostra, note o código e logo a seguir a breve descrição.
// Tabela de Áreas do Conhecimento
// 1.00.00.00-3 Ciências Exatas e da Terra
// 1.01.00.00-8 Matemática
// 1.01.01.00-4 Álgebra
// 1.01.01.01-2 Conjuntos
// 1.01.01.02-0 Lógica Matemática
class CGestorAreaConhecimento: public CEstadoPersistente
{
public:
  /// Caminho para diretório onde os dados serão armazenados.
  static std::string caminhoDiretorio;
  /// Nome do arquivo onde os dados serão armazenados.
  static std::string nomeArquivo;
  /// Map com as siglas dos laboratórios e código disponibilizado. O código vai crescendo de 0001 até 9999.
  static std::map<std::string,std::string> map_codigo_descricao;

public:
  /// Construtor, recupera o último estado armazenado em disco, recuperando a tabela com código da área do conhecimento e descrição.
  explicit CGestorAreaConhecimento() ;
  /// Construtor, recupera um estado especifico (ex: um backup).
  CGestorAreaConhecimento(const std::string identificadorEstado);

  /// Destrutor, salva em arquivo os dados dos códigos utilizados/criados.
  virtual ~CGestorAreaConhecimento() ;

  /// Mostra as areas do conhecimento e pede para usuário escolher qual quer.
  // A Area de conhecimento é apenas o código.
  static CCodigoAreaConhecimento DefinirAreaConhecimento();

  /// Dado o código da área de conhecimento retorna a descrição.
  static std::string DescricaoAreaConhecimento(CCodigoAreaConhecimento& ac);
  
  /// @return bool
  //...no caso da universidade ter um padrão de código a verificar...
  //bool VerificarCodigo(std::string codigoASerVerificado) ;

  /// Retorna o código como uma string.
  //std::string  operator()()  { return codigo; }

  /// Visualizar tabela AreaConhecimento (código e descrição).
  static void VisualizarTabelaAreaConhecimento();
  virtual void Visualizar()           { VisualizarTabelaAreaConhecimento(); };

  /// Visualizar tabela de area de conhecimento a partir de vetor de codigoASerVerificado
  static void VisualizarTabelaAreaConhecimento(std::vector<CCodigoAreaConhecimento>& vCodigo);

  // Implementa Métodos da classe persistente
public:
  /// Seta caminho para o diretório com os arquivos siglaDepartamento - código usado.
  virtual void CaminhoDiretorio(const std::string _caminhoDiretorio);

  /// Retorna caminho para o diretório com os arquivos siglaDepartamento - código usado.
  virtual const std::string  CaminhoDiretorio() const;
  /// Seta nome arquivo com a base de dados.
  virtual void NomeArquivo(const std::string _nomeArquivo);
  /// Retorna nome arquivo com a base de dados.
  virtual const std::string  NomeArquivo()   const;
  /// Salva um estado específico. caminhoDiretorio + nomeArquivo + identificadorEstado
  virtual void SalvarEstado(const std::string identificadorEstado = {}) const;

  /// Recupera um estado específico. caminhoDiretorio + nomeArquivo + identificadorEstado
  virtual void RecuperarEstado(const std::string identificadorEstado = {});
};
#endif // CGestorAreaConhecimento_H

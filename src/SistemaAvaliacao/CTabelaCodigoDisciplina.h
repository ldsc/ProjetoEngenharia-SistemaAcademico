#ifndef CTabelaCodigoDisciplina_H
#define CTabelaCodigoDisciplina_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "CEstadoPersistente.h"

/// Gerencia os códigos das disciplinas.
// Cada laboratório tem uma sigla de 3 letras, como exemplo: LEP.
// Soluções:
// 1: Arquivo único com o próximo código disponível, ex: dados/TabelaCodigoDisciplina/mapSiglaCodigo-0130.dat
// Ex: LEP 130 -> LEP-0130 é o código disponível, se criar uma nova disciplina com este código incrementa este valor.
//     FIS 75  -> FIS-0075 é o código disponível...
// Neste caso podemos usar um std::map<std::string,int> map_ultimoCodigoUsado;
// Armazena LEP 130

// 2: O diretório dados/TabelaCodigoDisciplina/ tem arquivos, MTM.dat, FIS.dat, LEP.dat com a lista de códigos das disciplinas por laboratório.
// Neste caso o arquivo tem a lista de todos os códigos utilizados.
// Já o código das disciplinas varia de: LEP-0001 até LEP-9999.
class CTabelaCodigoDisciplina: public CEstadoPersistente
{
public:
  /// Caminho para diretório onde os dados serão armazenados.
  static std::string caminhoDiretorio;
  /// Nome do arquivo onde os dados serão armazenados.
  static std::string nomeArquivo;
  /// Map com as siglas dos laboratórios e código disponibilizado. O código vai crescendo de 0001 até 9999.
  static std::map<std::string,int> map_ultimoCodigoUsado;
  /// Último código de disciplina utilizado.
  static std::string codigoDisciplina;

public:
  /// Construtor, recupera o último estado armazenado em disco, recuperando a tabela com sigla dos departamentos e último código utilizado.
  CTabelaCodigoDisciplina() {
    if(map_ultimoCodigoUsado.size() == 0)
      RecuperarEstado();
  }
  /// Construtor, recupera um estado especifico (ex: um backup).
  CTabelaCodigoDisciplina(std::string identificadorEstado) {
      RecuperarEstado(identificadorEstado);
  }

  /// Destrutor, salva em arquivo os dados dos códigos utilizados/criados.
  virtual ~CTabelaCodigoDisciplina() {
     SalvarEstado();
  }

  /// @return string
  /// Também poderia alterar e já modificar o arquivo (+seguro).
  std::string DefinirCodigoDisciplina(std::string siglaDepartamento);
  
  /// @return bool
  //...no caso da universidade ter um padrão de código a verificar...
  //bool VerificarCodigo(std::string codigoASerVerificado) ;

  /// Seta um novo código informando a sigla do departamento e o código.
  /// Note que se já existe este departamento vai substituir o anterior, se não existe por padrão inicia com 0.
  /// @param string sigla, int novoCodigo
  void AdicionarDepartamento(std::string siglaDepartamento, int codigoInicial = 0)
  {
    map_ultimoCodigoUsado[siglaDepartamento] = codigoInicial ;
  }

  /// Retorna último código utilizado.
  /// @return the value of codigo
  std::string CodigoDisciplina()      {  return codigoDisciplina;  }
  /// Retorna último código utilizado.
  std::string operator()()  {  return codigoDisciplina;  }

  /// Visualizar tabela codigos
  void Visualizar();

  // Implementa Métodos da classe persistente
public:
  virtual void CaminhoDiretorio(std::string _caminhoDiretorio)  { caminhoDiretorio = _caminhoDiretorio; };
  virtual std::string  CaminhoDiretorio()                       { return caminhoDiretorio; };
  virtual void NomeArquivo(std::string _nomeArquivo)            { nomeArquivo = _nomeArquivo; };
  virtual std::string  NomeArquivo()                            { return nomeArquivo; };
  // virtual void SalvarEstado() = 0;
  // virtual void RecuperarEstado() = 0;
  /// Salva um estado específico. caminhoDiretorio + nomeArquivo + identificadorEstado
  virtual void SalvarEstado(std::string identificadorEstado = {});
  virtual void RecuperarEstado(std::string identificadorEstado = {});
};
#endif // CCODIGODISCIPLINA_H

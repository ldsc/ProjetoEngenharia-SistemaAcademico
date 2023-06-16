#ifndef CEstadoPersistente_H
#define CEstadoPersistente_H

#include <string>

/// Representa uma interface para um estado do objeto que persiste em disco, podendo ser salvo ou recuperado.
/// Note que teremos nos herdeiros dois atributos:
/// O caminho para o diretório onde os estados serão armazernados e o nome do arquivo que armazena o estado.
/// SalvarEstado() e RecuperarEstado() salvam e recuperam o último estado, sem definir um identificador.
/// SalvarEstado(id) e RecuperarEstado(id) salvam e recuperam um estado identificado.
class CEstadoPersistente
{
public:
  virtual void CaminhoDiretorio(const std::string _caminhoDiretorio) = 0 ;
  virtual const std::string  CaminhoDiretorio() const                      = 0 ;
  virtual void NomeArquivo(const std::string _nomeArquivo)           = 0 ;
  virtual const std::string  NomeArquivo() const                           = 0 ;

  // /// Salva último estado.
  // virtual void SalvarEstado() = 0;
  // /// Recupera último estado.
  // void RecuperarEstado() = 0;
  /// Salva um estado específico. caminhoDiretorio + nomeArquivo + "-" + identificadorEstado
  // ex: dados/TabelaCodigoDisciplina-Estado.dat
  virtual void SalvarEstado(const std::string identificadorEstado = {} ) const   = 0 ;
  /// Recupera um estado específico.
  virtual void RecuperarEstado(const std::string identificadorEstado = {} ) = 0 ;
};
#endif

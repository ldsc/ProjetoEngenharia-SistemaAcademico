#ifndef CEstadoPersistente_H
#define CEstadoPersistente_H

#include <string>
#include <filesystem>

/// Representa uma interface para um estado do objeto que persiste em disco, podendo ser salvo ou recuperado.
/// Note que teremos nos herdeiros dois atributos:
/// O caminho para o diretório onde os estados serão armazernados (normalmente um static string)
/// O nome do arquivo que armazena o estado (o nome é construído de acordo com demandas específicas, ou seja, varia caso a caso).
/// SalvarEstado() e RecuperarEstado() salvam e recuperam o último estado, sem definir um identificador específico. Usam o caminho dado por caminhoDiretorio/nomeArquivo.
/// SalvarEstado(id) e RecuperarEstado(id) salvam e recuperam um estado identificado.
/// Em alguns casos o id substitui o nome do arquivo:
///  ex: nome do arquivo = id. Usam o caminho dado por caminhoDiretorio/id.
/// em outros casos o id complementa o nome do arquivo:
///  ex: nome do arquivo = nome.stem()+id+nome.extension().
class CEstadoPersistente
{
public:
  /// Seta o caminho do diretório onde estão os arquivos.
  virtual void CaminhoDiretorio(const std::filesystem::path& _caminhoDiretorio) = 0 ;
  /// Retorna o caminho do diretório onde estão os arquivos.
  virtual const std::filesystem::path&  CaminhoDiretorio() const                = 0 ;
  /// Seta o nome do arquivo.
  virtual void NomeArquivo(const std::filesystem::path& _nomeArquivo)           = 0 ;
  /// Retorna o nome do arquivo.
  virtual const std::filesystem::path& NomeArquivo() const                      = 0 ;

  /// Salva último estado ou um estado específico.
  // ex: se path = dados/TabelaCodigoDisciplina-.dat vai salvar dados no arquivo
  // dados/TabelaCodigoDisciplina-identificadorEstado.dat
  inline bool SalvarEstado(const std::string identificadorEstado , std::filesystem::path _nomeArquivo )   {
    NomeArquivo(_nomeArquivo);
    std::filesystem::path caminhoCompleto = CaminhoDiretorio()/_nomeArquivo;
    caminhoCompleto.replace_filename(caminhoCompleto.stem().string()+ identificadorEstado + caminhoCompleto.extension().string());
 // std::cerr << "\nDEBUG22 CaminhoDiretorio()=" << CaminhoDiretorio();
 // std::cerr << "\nDEBUG22 NomeArquivo()=" << NomeArquivo();
 // std::cerr << "\nDEBUG22 caminhoCompleto=" << caminhoCompleto;
    return SalvarArquivo(caminhoCompleto);
  }
  /// Salva estado no arquivo CaminhoDiretorio()/NomeArquivo.stem()+identificadorEstado+NomeArquivo.extension().
  inline bool SalvarEstado(const std::string identificadorEstado) const {
    std::filesystem::path caminhoCompleto = CaminhoDiretorio()/NomeArquivo();
    caminhoCompleto.replace_filename(caminhoCompleto.stem().string()+ identificadorEstado + caminhoCompleto.extension().string());
 // std::cerr << "\nDEBUG23 CaminhoDiretorio()=" << CaminhoDiretorio();
 // std::cerr << "\nDEBUG23 NomeArquivo()=" << NomeArquivo();
 // std::cerr << "\nDEBUG23 caminhoCompleto=" << caminhoCompleto;
    return SalvarArquivo(caminhoCompleto);
  }
  /// Salva estado no arquivo CaminhoDiretorio()/NomeArquivo().
  inline bool SalvarEstado() const {
 // std::cerr << "\nDEBUG25 CaminhoDiretorio()=" << CaminhoDiretorio();
 // std::cerr << "\nDEBUG25 NomeArquivo()=" << NomeArquivo();
 // std::cerr << "\nDEBUG25 caminhoCompleto=" << CaminhoDiretorio()/NomeArquivo(); //bug

    return SalvarArquivo(CaminhoDiretorio()/NomeArquivo());
  }
  /// Salva estado do objeto ou dados associados no diretorio/arquivo.
  bool SalvarDiretorioArquivo(const std::filesystem::path& _diretorio, const std::filesystem::path& _arquivo){
     CaminhoDiretorio(_diretorio);
     NomeArquivo(_arquivo);
     std::filesystem::path caminhoCompleto = _diretorio/_arquivo;
 // std::cerr << "\nDEBUG24 CaminhoDiretorio()=" << CaminhoDiretorio();
 // std::cerr << "\nDEBUG24 NomeArquivo()=" << NomeArquivo();
 // std::cerr << "\nDEBUG24 caminhoCompleto=" << caminhoCompleto;
    if(std::filesystem::exists(caminhoCompleto))
      return SalvarArquivo(caminhoCompleto);
    else
      return false;
  }

  /// Recupera último estado ou um estado específico.
  // Cada classe herdeira terá seu próprio comportamento, o que importa é que deve poder salvar e recuperar o estado.
  // ex: se path = dados/TabelaCodigoDisciplina-.dat
  // recupera do arquivo dados/TabelaCodigoDisciplina-identificadorEstado.dat
  /// Salva último estado ou um estado específico.
  // ex: se path = dados/TabelaCodigoDisciplina-.dat vai salvar dados no arquivo
  // dados/TabelaCodigoDisciplina-identificadorEstado.dat
  inline bool RecuperarEstado(const std::string identificadorEstado, std::filesystem::path _nomeArquivo )   {
    NomeArquivo(_nomeArquivo);
    std::filesystem::path caminhoCompleto = CaminhoDiretorio()/_nomeArquivo;
    caminhoCompleto.replace_filename(caminhoCompleto.stem().string()+ identificadorEstado + caminhoCompleto.extension().string());
// std::cerr << "\nDEBUG2 CaminhoDiretorio()=" << CaminhoDiretorio();
// std::cerr << "\nDEBUG2 NomeArquivo()=" << NomeArquivo();
// std::cerr << "\nDEBUG2 caminhoCompleto=" << caminhoCompleto;
    if(std::filesystem::exists(caminhoCompleto))
      return RecuperarArquivo(caminhoCompleto);
    else
      return false;
  }
  /// Salva estado no arquivo CaminhoDiretorio()/NomeArquivo.stem()+identificadorEstado+NomeArquivo.extension().
  inline bool RecuperarEstado(const std::string identificadorEstado)   {
    std::filesystem::path caminhoCompleto = CaminhoDiretorio()/NomeArquivo();
    caminhoCompleto.replace_filename(caminhoCompleto.stem().string()+ identificadorEstado + caminhoCompleto.extension().string());
// std::cerr << "\nDEBUG1 CaminhoDiretorio()=" << CaminhoDiretorio();
// std::cerr << "\nDEBUG1 NomeArquivo()=" << NomeArquivo();
// std::cerr << "\nDEBUG1 caminhoCompleto=" << caminhoCompleto;
    if(std::filesystem::exists(caminhoCompleto))
      return RecuperarArquivo(caminhoCompleto);
    else
      return false;
  }

  /// Salva estado no arquivo CaminhoDiretorio()/NomeArquivo().
  inline bool RecuperarEstado()  {
     std::filesystem::path caminhoCompleto = CaminhoDiretorio()/NomeArquivo();
// std::cerr << "\nDEBUG0 CaminhoDiretorio()=" << CaminhoDiretorio();
// std::cerr << "\nDEBUG0 NomeArquivo()=" << NomeArquivo();
// std::cerr << "\nDEBUG0 caminhoCompleto=" << caminhoCompleto;
    if(std::filesystem::exists(caminhoCompleto))
      return RecuperarArquivo(caminhoCompleto);
    else
      return false;
  }
  /// Recupera os dados a partir de diretorio e caminho arquivo.
  // Seta diretorio e seta nome arquivo
  bool RecuperarDiretorioArquivo(const std::filesystem::path& _diretorio, const std::filesystem::path& _arquivo){
     CaminhoDiretorio(_diretorio);
     NomeArquivo(_arquivo);
     std::filesystem::path caminhoCompleto = _diretorio/_arquivo;
// std::cerr << "\nDEBUG11 CaminhoDiretorio()=" << CaminhoDiretorio();
// std::cerr << "\nDEBUG11 NomeArquivo()=" << NomeArquivo();
// std::cerr << "\nDEBUG11 caminhoCompleto=" << caminhoCompleto;
    if(std::filesystem::exists(caminhoCompleto))
      return RecuperarArquivo(caminhoCompleto);
    else
      return false;
  }

protected:
  /// Salva estado do objeto ou dados associados no arquivo. .
  virtual bool RecuperarArquivo(std::filesystem::path caminhoCompleto) = 0;
  /// Salva estado do objeto ou dados associados no arquivo.
  virtual bool SalvarArquivo(std::filesystem::path caminhoCompleto)  const = 0;
};
#endif



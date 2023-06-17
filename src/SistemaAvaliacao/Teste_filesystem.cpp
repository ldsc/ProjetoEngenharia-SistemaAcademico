#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

 std::filesystem::path caminhoDiretorio = "dados/TabelaCodigoDisciplina/";
 std::filesystem::path nomeArquivo      = "teste-.dat"; // padrão, sem o estado

 // troca um pedaço da string por outro
std::string& replace(std::string& origem, const std::string& troqueIsso, const std::string& porIsso) {
    size_t posicaoInicial = origem.find(troqueIsso);
    if(posicaoInicial == std::string::npos)
        return origem;
    origem.replace(posicaoInicial, troqueIsso.length(), porIsso);
    return origem;
}
// Salva um estado específico. caminhoDiretorio + nomeArquivo + "-" + identificadorEstado
void SalvarEstado(std::string identificadorEstado={})
{
    std::filesystem::path caminhoCompleto = caminhoDiretorio / nomeArquivo ;
    // Adiciona no caminho a informação do estado
    if(identificadorEstado.size() != 0) {
      std::string sCaminhoCompleto = caminhoCompleto.string();
      caminhoCompleto = replace(sCaminhoCompleto,".dat",identificadorEstado+".dat");
      }
    std::ofstream arquivoSiglaCodigo (caminhoCompleto.string());
    if(arquivoSiglaCodigo.fail()) {
      cerr << "\nNão conseguiu abrir o arquivo:" << caminhoCompleto << " para leitura... encerrando!\n";
      exit(0);
    }
    arquivoSiglaCodigo
          << "#SiglaDoDepartamento #PróximoCódigoVálido\n" // cabeçalho.
          << "LEP" << ' ' << 5000 << '\n'
          << "MTM" << ' ' << 4400 << '\n'
          << "FIS" << ' ' << 3333 << '\n'
          << "QUI" << ' ' << 6234 << '\n';
    arquivoSiglaCodigo.close(); // opcional, descarrega o buffer e fecha o arquivo.
}

// Implementação dos métodos da classe CTabelaCodigoDisciplina
// Recupera um estado específico. caminhoDiretorio + nomeArquivo + identificadorEstado
void RecuperarEstado(std::string identificadorEstado={})
{
    std::filesystem::path caminhoCompleto = caminhoDiretorio / nomeArquivo ;
    // Adiciona no caminho a informação do estado
    if(identificadorEstado.size() != 0) {
      std::string sCaminhoCompleto = caminhoCompleto.string();
      caminhoCompleto = replace(sCaminhoCompleto,".dat",identificadorEstado+".dat");
      }
    std::ifstream arquivoSiglaCodigo (caminhoCompleto.string());
    std::string sigla;
    int ultimoCodigoUsado;
    if(arquivoSiglaCodigo.fail()) {
      cerr << "\nNão conseguiu abrir o arquivo:" << caminhoCompleto << " para leitura... encerrando!\n";
      exit(0);
    }
    arquivoSiglaCodigo.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // ignora linha comentário
    while (! arquivoSiglaCodigo.eof() ) {
      arquivoSiglaCodigo >> sigla >> ultimoCodigoUsado;
      //map_ultimoCodigoUsado[sigla] = ultimoCodigoUsado;
      std::cout << "\nsigla=" << sigla << "\ncodigo=" << ultimoCodigoUsado << endl;
    }
}


void InformacoesPath(fs::path& p) {
std::cout   << "\nPath completa: " << p
            << "\nNote que o Caminho corrente pode ser decomposto nas seguintes partes:"
            << "\nroot_name()="       << p.root_name()
            << "\nroot_directory()="  << p.root_directory()
            << "\nroot_path()="       << p.root_path()
            << "\nroot_path().string() =" << p.root_path().string()
            << "\nparent_path()="     << p.parent_path()
            << "\nfilename()="        << p.filename()
            << "\nextension()="       << p.extension();
std::cout   << "\nis_block_file (device)     = " << is_block_file(p)
            << "\nis_character_file (device) = " << is_character_file(p)
            << "\nis_directory               = " << is_directory(p)
            << "\nis_fifo                    = " << is_fifo(p)
            << "\nis_other                   = " << is_other(p)
            << "\nis_regular_file            = " << is_regular_file(p)
            << "\nis_socket                  = " << is_socket(p)
            << "\nis_symlink                 = " << is_symlink    (p)
            << "\nexists                     = " << fs::exists(p) << '\n';
            if(fs::exists(p))
              std::cout << "\nis_empty                   = " << fs::is_empty(p);
}

int main() {
  std::string sEntrada;
  std::cout << "\nEntre com o caminhoDiretorio [" << caminhoDiretorio << "]:";
  std::getline(cin,sEntrada);
  caminhoDiretorio = sEntrada;
  std::cout << "\nEntre com o nomeArquivo [" << nomeArquivo << "]:";
  std::getline(cin,sEntrada);
  nomeArquivo = sEntrada;

  InformacoesPath(caminhoDiretorio);
  InformacoesPath(nomeArquivo);

  std::cout << "\nVai salvar o estado SalvarEstado();";
  SalvarEstado();
  std::cout << "\nVai recuperar o estado SalvarEstado();";
  RecuperarEstado();

  std::cout << "\nVai salvar o estado SalvarEstado(NomeEstado);";
  SalvarEstado("NomeEstado");
  std::cout << "\nVai recuperar o estado SalvarEstado(NomeEstado);";
  RecuperarEstado("NomeEstado");
  return 0;
}

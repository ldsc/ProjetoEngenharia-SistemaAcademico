// /home/andreduartebueno/Dropbox/workdir/ProjetoEngenharia-SistemaAcademico/MaterialAuxiliar/TabeladeAreasdoConhecimento-Assuntos.txt

CCodigoDisciplina:
contém o código de uma disciplina. É uma string com padrão definido.
- static std::string o padrão
- std::string o código

CGestorCodigoDisciplina:
gerencia a criação de códigos de disciplina.
Usa diretório TabelaCodigoDisciplina e arquivo mapSiglaCodigo-.dat ou mapSiglaCodigo-N.dat sendo N a versão da tabela (marcador do estado/versão).

CGestorMapChaveValor sendo chave um padrão e valor um texto.
- static std::string caminho
- static std::string nomeArquivo
- Visualiza a tabela.
- Procura pelo código (padrão).
- Procura pelo texto associado ao padrão.
- Salva
- Recupera

CGestorMapChaveValor<CPadrao<"n.nn.nn.nn-n">,std::string> TabelaAreaConhecimento("caminho","nomeArquivo");

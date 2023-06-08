Tarefas:

1)
CCodigoDisciplina
- Atualmente mistura dois conceitos, a gestão do código e o código em sí.
- A gestão do código é a geração do código de forma a não ter repetições.
Tem um arquivo com a sigla do departamento e o último código utilizado.
- O código se refere a sigla-numero.
Separar em dois:
- CCodigoDisciplina
- CGestaoCodigoDisciplina

[ok] 2)
Vamos usar strings como códigos, por exemplo, CCodigoDisciplina é uma classe que armazena uma string que representa um código de disciplina;
Sua criação é feita pela classe CGestaoCodigoDisciplina, de forma que tem um padrão.
Teremos outros casos.

Pense em criar uma classe CVerificaPadrao que tem uma string e uma função de verificação do padrão.
// c=caracter, n=número,

Que deve ser reescrita para cada classe herdeira.
ex:
bool CCodigoDisciplina::VerificaPadrao(std::string& sCodigo) {
  static std::string_view sPadrao = "ccc-nnnn";
  return VerificaPadrao(sCodigo,sPadrao);
  //ou   return VerificaPadrao(sCodigo,"ccc-nnnn");
}

3)
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

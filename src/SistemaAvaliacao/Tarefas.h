Tarefas:

[] 7) eliminar uso de system, achar mecanismo genérico;
- substituir tree por arvore gerada com filesystem.

[] 6) usar path nos endereços criados;
Generaliza e viabiliza outros usos, mas requer usar lib filesystem.

[] 5) Pense em generalizar este sistema de gestão de tabela de dados usando map.
CGestorMapChaveValor sendo chave um padrão e valor um texto.
- static std::string caminho
- static std::string nomeArquivo
- Visualiza a tabela.
- Procura pelo código (padrão).
- Procura pelo texto associado ao padrão.
- Salva
- Recupera

CGestorMapChaveValor<CPadrao<"n.nn.nn.nn-n">,std::string> TabelaAreaConhecimento("caminho","nomeArquivo");

[ok] 2)
Vamos usar strings como códigos, por exemplo, CCodigoDisciplina é uma classe que armazena uma string que representa um código de disciplina;
Sua criação é feita pela classe CGestorCodigoDisciplina, de forma que tem um padrão.
Teremos outros casos.

[ok] 1)
CCodigoDisciplina
- Atualmente mistura dois conceitos, a gestão do código e o código em sí.
- A gestão do código é a geração do código de forma a não ter repetições.
Tem um arquivo com a sigla do departamento e o último código utilizado.
- O código se refere a sigla-numero.
Separar em dois:
- CCodigoDisciplina
- CGestorCodigoDisciplina

[parcial] 3) Pense em criar uma classe CVerificaPadrao que tem uma string e uma função de verificação do padrão.
// c=caracter, n=número,
Criou mas não esta usando.... ver usos...

Que deve ser reescrita para cada classe herdeira.
ex:
bool CCodigoDisciplina::VerificaPadrao(std::string& sCodigo) {
  static std::string_view sPadrao = "ccc-nnnn";
  return VerificaPadrao(sCodigo,sPadrao);
  //ou   return VerificaPadrao(sCodigo,"ccc-nnnn");
}


[parcial] 4) Precisa criar mecanismo para lidar com os assuntos;
Como já temos a tabela da CAPES/CNPQ com as áreas de conhecimento vamos usar ela.

Com base em CCodigoDisciplina criar CCodigoAreaConhecimento
Com base em CGestorCodigoDisciplina criar CGestorCodigoAreaConhecimento.
diretorios dados/TabeladeAreasdoConhecimento/TabeladeAreasdoConhecimento-Assuntos.txt

A ideia é que uma ementa de disciplina esteja associada aos assuntos da capes/cnpq, evitando ser totalmente avulsa.
Idealmente as avaliações também devem ter os assuntos associados, de  forma que podemos pegar o sistema de avaliações, que contem as avaliações e verificar quantos porcento do conteúdo foi coberto pelas avaliações.
Um curso também pode e deve ter assuntos associados, assim, podemos analisar a lista de disciplinas obrigatórias do curso e quantos porcento da demanda do cursoPadrao do mec é atendido.
Isto faria deste sistema algo útil para ser utilizado pelos professores, pois poderemos verificar se o mínimo esta sendo atendido.

Falta criar os cursos...e adicionar no curso a lista de áreas de conhecimento.


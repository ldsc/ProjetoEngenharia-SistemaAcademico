#include <iostream> // uso de cin/cout
#include <iomanip>  // uso de setw
#include <iterator> // uso de copy

#include "CAvaliacao.h"

using namespace std;

vector<string> CAvaliacao::pergunta; // atributo estatico, as perguntas sao compartilhadas.

void CAvaliacao::LerPerguntasDisco(string nomeArquivo) {
  ifstream fin(nomeArquivo);        // Abre arquivo com as perguntas
  if (!fin) {
    cerr << "\n-->ERRO: Não localizou o arquivo de perguntas (" << nomeArquivo << ").\n";
    exit(0);
  }
  string perguntaEspecifica;
  pergunta.clear();		    // zera vetor de perguntas
  while(! fin.eof()) {
      getline(fin , perguntaEspecifica);
      pergunta.push_back(perguntaEspecifica);
    }
  fin.close();                      // fecha arquivo com as perguntas
  pergunta.pop_back();              // remove linha em branco, pergunta em branco
}

CAvaliacao::CAvaliacao (): codigoAvaliador(10,' ') { 
  if (pergunta.size() == 0)
    LerPerguntasDisco();
  nota.resize( pergunta.size() );  // vetor de notas com mesmo tamanho do vetor de perguntas
}

/// Metodo de avaliacao
void CAvaliacao::Avaliar() {
  cout << "\n======================================================="
       << "\nApos ler a pergunta com atenção, de sua nota."
       << "\nValor entre -3 (muito ruim), 0 (neutro), 3 (muito bom)."
       << "\n=======================================================\n\a"<< endl;
  for(int i = 0; i < nota.size(); i++) {
      cout << "-> Pergunta " << setw(2) << i << ":\n-> " << pergunta[i] << " : ";
      cin >> nota[i]; cin.get();
    }
  cout << "\nAgora faça um comentário sobre a disciplina (digite todo o texto e ao final enter):\n";
  getline(cin,comentario);  
}

void CAvaliacao::SaidaDados(std::ostream& out) {
  out << CodigoAvaliador()  << ' ';
  for( auto nota_i : nota )
    out << nota_i << '  ';
  out << ' ' << comentario;
}

// void CAvaliacao::Saida(ofstream& out, const CAvaliacao& avaliacao) {
//   out << avaliacao.codigoAvaliador  << ' ';
//    for(int i = 0; i < obj.nota.size(); i++) 
//        out << avaliacao.nota[i] << ' ';
//    out << ' ' << comentario;
// }

ostream& operator<<(ostream& out, const CAvaliacao& avaliacao) {
  out << avaliacao.CodigoAvaliador()  << ' ';
  copy(avaliacao.nota.begin(),avaliacao.nota.end(),ostream_iterator<double>(out, ' '));
  out << ' ' << avaliacao.comentario;
  return out;
}

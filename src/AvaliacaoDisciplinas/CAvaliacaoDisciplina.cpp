#include <iomanip>			// Uso de setw.

#include "CGnuplot.h"			// Acesso a gráficos do gnuplot.

#include "CAvaliacaoDisciplina.h"	// Classe que representa a avaliação de uma disciplina.

using namespace std;

/// Solicita dados iniciais
void CAvaliacaoDisciplina::EntradaDados() {

  cout << "Entre com o nome da disciplina: ";
  getline(cin, nomeDisciplina);

  cout << "Entre com o nome do professor: ";
  getline(cin,nomeProfessor);

  cout << "Entre com o número de alunos que farão a avaliação: ";
  int nAlunos; 	  cin >> nAlunos; cin.get();
  aluno.resize(nAlunos);

  media.resize( CAvaliacao::pergunta.size() ); // Le vetor das perguntas no ini­cio do programa
}

/// Avalia a disciplina, notas dadas pelos alunos
void CAvaliacaoDisciplina::Avaliar() {  
    for (int i = 0;  i < aluno.size(); i++) {
      string codigo;
      cout << "---> Aluno(" << i << ")\nEntre com seu codigo (10 digitos):";
      getline(cin, codigo);
      aluno[i].CodigoAvaliador(codigo);
      cout << "\nAgora faca sua avaliacao de forma criteriosa.\n";
      aluno[i].Avaliar();
    }
}

/// Avalia a disciplina, notas dadas pelos alunos
// void CAvaliacaoDisciplina::Avaliar() {
//     for (int i = 0;  i < aluno.size(); i++) {
//       string codigo;
//       do {
//       bool codigoValido {true};
//       cout << "---> Aluno(" << i << ")\nEntre com seu codigo (10 digitos):";
//       getline(cin, codigo);
//       // Verifica se codigo ja foi utilizado
//       for (int j = 0;  j < aluno.size(); j++) {
//           if ( aluno[j].CodigoAvaliador() == codigo ) {
//               codigoValido = false;
//               cout  << "\nO codigo: " << codigo << " ja foi utilizado pelo aluno " << j << endl;
//           }
//         }
//       } while ( codigoValido == false );
//       aluno[i].CodigoAvaliador(codigo);
//       cout << "\nAgora faca sua avaliacao de forma criteriosa.\n\n";
//       aluno[i].Avaliar();
//     }
// }

/// Calcula a media das notas
void CAvaliacaoDisciplina::Media() {
  for (int j = 0;  j < media.size(); j++) {
      media[j] = 0.0;
      for(int i = 0; i < aluno.size(); i++)
	media[j] += aluno[i][j]; //aluno[i](j); // ou aluno[i].Nota(j);
      media[j] /= (double)aluno.size();
    }
    
  // salva resultados em disco
  string nomeArquivo = Nome() + ".medias";
  ofstream fout( nomeArquivo.c_str() );
  for (int j = 0;  j < media.size(); j++)
    fout << j << " " << media[j] << endl;
  fout.close();
}

// /// Gera dados para grafico e Plota resultados (usa pstream.h)
// void CAvaliacaoDisciplina::Plotar() {
// //string nomeArquivo = nomeDisciplina + "_" + nomeProfessor + ".medias";
//   string nomeArquivo = Nome() + ".medias";
//   ofstream fout( nomeArquivo.c_str() );
//   for (int j = 0;  j < media.size(); j++)
//     fout << j << " " << media[j] << endl;
//   fout.close();
// 
//   string nomeGrafico = Nome() + ".eps";
//   redi::opstream gnuplot("gnuplot");
//   gnuplot << "plot [0:" << media.size() << "][-3:3] \"" 
// 	  << nomeArquivo << "\" using 1:2 title \""  << nomeGrafico << "\"" << endl
// 	  << "set terminal postscript" << endl 
// 	  << "set output \"" << nomeGrafico << "\"" << endl << "replot" << endl;
//   cin.get();
//   gnuplot.close();
// }

// Ao usar static usa o mesmo gráfico para todas as plotagens;
// se quizer um gráfico para cada disciplina colocar grafico como atributo da classe.
void CAvaliacaoDisciplina::Plotar() const {
  static CGnuplot grafico;			
  grafico.PlotVector(media, Nome());
  cout << "\nDigite enter para continuar." << endl;
  cin.get();
}

void CAvaliacaoDisciplina::SaidaDados (std::ostream& out) {
 out   <<  setw(20) << "\nNome da disciplina: "<<  setw(20) << nomeDisciplina 
       <<  setw(20) << "\nNome professor: "    <<  setw(20) << nomeProfessor << endl;
 for (int i = 0;  i < aluno.size(); i++)
    out <<  aluno[i] << endl;
}

/// Sobrecarga operador<<
ostream& operator<<(ostream& out, CAvaliacaoDisciplina& obj) {
  out   <<  setw(20) << "\nNome da disciplina: "<<  setw(20) << obj.nomeDisciplina 
        <<  setw(20) << "\nNome professor: "    <<  setw(20) << obj.nomeProfessor << endl;
  for (int i = 0;  i < obj.aluno.size(); i++)
    out <<  obj.aluno[i] << endl;
  return out;
}

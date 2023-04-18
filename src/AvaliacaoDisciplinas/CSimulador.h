#ifndef CSimulador_h
#define CSimulador_h


#include "CAvaliacao.h"			  // Classe que representa uma avaliação específica.
#include "CAvaliacaoDisciplina.h" // Classe que representa a avaliação de uma disciplina.

using namespace std;

/// Um simulador que testa as classes de avaliacao.
class CSimulador
{
 public:
  void Run() { 
      TestarCAvaliacao(); 
      TestarCAvaliacaoDisciplina(); 
      TestarCAvaliacaonDisciplina(); 
}

 private:
  /// Testa uma avaliação.
  void TestarCAvaliacao() {
    cout << "\n==================> Setar seu terminar para codificação ISO8859-1.";
    cout << "\n==================> Usando uma avaliação específica(um aluno):\n";
    CAvaliacao avaliacao;
    avaliacao.CodigoAvaliador("asdqwesd");
    avaliacao.Avaliar();
    cout << "\nResultado:\n" << avaliacao;
  } 
  
  /// Testa avaliação de uma disciplina.
  void TestarCAvaliacaoDisciplina() {
    cout << "\n==================> Usando avaliação de uma disciplina x(n alunos):\n";
    CAvaliacaoDisciplina disciplina_x;
    disciplina_x.EntradaDados();
    disciplina_x.Avaliar();
    ofstream arquivoAvaliacoes((disciplina_x.Nome() + ".dat").c_str());
    arquivoAvaliacoes << disciplina_x;
    arquivoAvaliacoes.close();
    disciplina_x.Media();
    disciplina_x.Plotar();
    cout << "\nResultado:\n" << disciplina_x;
  }
  
  /// Testa avaliação de várias disciplinas.
  void TestarCAvaliacaonDisciplina(){
    cout << "\n==================> Usando avaliação de várias disciplinas:\n";
    int nDisciplinas;
    cout << "Entre com o número de disciplinas: ";
    cin >> nDisciplinas; cin.get();
  
    vector<CAvaliacaoDisciplina> disciplina(nDisciplinas); // Várias disciplinas, nDisciplinas
  
    for (int i = 0;  i < disciplina.size(); i++) {
      cout << "======================== Disciplina[" << i << "] ========================\n";
      disciplina[i].EntradaDados();
      disciplina[i].Avaliar();

      ofstream arquivoAvaliacoes( (disciplina[i].Nome() + ".dat")/*.c_str()*/ );
      arquivoAvaliacoes << disciplina[i];
      arquivoAvaliacoes.close();

      disciplina[i].Media();
      disciplina[i].Plotar();
      //cout << "\nResultado:\n" << disciplina[i];
    }
  }
};
#endif

#ifndef CSimulador_h
#define CSimulador_h


#include "CAvaliacao.h"			  // Classe que representa uma avalia��o espec�fica.
#include "CAvaliacaoDisciplina.h" // Classe que representa a avalia��o de uma disciplina.

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
  /// Testa uma avalia��o.
  void TestarCAvaliacao() {
    cout << "\n==================> Setar seu terminar para codifica��o ISO8859-1.";
    cout << "\n==================> Usando uma avalia��o espec�fica(um aluno):\n";
    CAvaliacao avaliacao;
    avaliacao.CodigoAvaliador("asdqwesd");
    avaliacao.Avaliar();
    cout << "\nResultado:\n" << avaliacao;
  } 
  
  /// Testa avalia��o de uma disciplina.
  void TestarCAvaliacaoDisciplina() {
    cout << "\n==================> Usando avalia��o de uma disciplina x(n alunos):\n";
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
  
  /// Testa avalia��o de v�rias disciplinas.
  void TestarCAvaliacaonDisciplina(){
    cout << "\n==================> Usando avalia��o de v�rias disciplinas:\n";
    int nDisciplinas;
    cout << "Entre com o n�mero de disciplinas: ";
    cin >> nDisciplinas; cin.get();
  
    vector<CAvaliacaoDisciplina> disciplina(nDisciplinas); // V�rias disciplinas, nDisciplinas
  
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

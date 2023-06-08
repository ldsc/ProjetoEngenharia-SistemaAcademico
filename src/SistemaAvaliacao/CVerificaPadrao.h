#ifndef CVerificaPadrao_H
#define CVerificaPadrao_H

#include <string>
#include <string_view>
#include <cctype> // int isdigit( int ch ); // int isalpha( int ch );
/// Classe usada para verificar se uma string atende determinado padrão.
/// O padrão é definido por:
/// c - uma letra
/// n - um número
/// Outros caracteres serão comparados um a um entre o SCodigo e o sPadrao.
/// # - jogo da velha
/// / - barra
/// - - menos
/// + - mais
/// . - um ponto
/// ....
/// Note que poderia utilizar expressões regulares.
class CVerificaPadrao {
public:
 /// Verifica o padrão, retorna verdadeiro se atende o padrão.
 static bool Verificar(std::string& sCodigo, std::string_view& sPadrao) {
  // O size deve ser o mesmo
  if( sCodigo.size() != sPadrao.size() )
    return 0;
  // Os caracteres devem atender o padrão
  for(size_t i = 0; i < sPadrao.size(); i++) {
     switch(sPadrao[i]) {
       case 'c': if(! std::isalpha(sCodigo[i])); return 0; break;
       case 'n': if(! std::isdigit(sCodigo[i])); return 0; break;
       default : if( sPadrao[i] != sCodigo[i] ); return 0; break;
    }
  }
 }
 /// Verifica o padrão, retorna verdadeiro se atende o padrão.
 static bool AtendePadrao(std::string& sCodigo, std::string_view& sPadrao) {
   return Verificar(sCodigo,sPadrao);
 }
};
#endif

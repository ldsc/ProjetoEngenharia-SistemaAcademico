#include "CCodigoAreaConhecimento.h"
#include "CGestorAreaConhecimento.h"

// Variáveis estáticas, compartilhadas entre objetos.
std::string_view CCodigoAreaConhecimento::padraoCodigo = "n.nn.nn.nn-n";

std::string CCodigoAreaConhecimento::Descricao()  {
    //std::string sCodigo = codigo;
    return CGestorAreaConhecimento::DescricaoAreaConhecimento(*this);
}

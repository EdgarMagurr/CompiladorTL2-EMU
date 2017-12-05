#include <iostream>
#include "Lexico.h"

using namespace std;

int main()
{
    Lexico lex;
    lex.asignar_entrada(";|:|||<><><===!=293.0##    %?¡´´    .int.2203.2332.2\"abqwewfgvfbvrtb12323f+abc####\"adios12_,");

    while(lex.simbolo.compare("$")!=0)
    {
        lex.siguiente_simbolo();
        cout << lex.simbolo << "    " << lex.tipo_simbolo(lex.tipo) << endl;
    }
    return 0;
}

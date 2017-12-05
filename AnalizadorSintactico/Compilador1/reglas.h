#ifndef REGLAS_H_INCLUDED
#define REGLAS_H_INCLUDED

#include <iostream>

#include "pila.h"
#include "simbolo.h"

using namespace std;

lista<simbolo> TablaSimbolos;
lista<string> tablaError;

char vectorParametros[20], vectorArgumentos[20];
int countP, countA, countArgs;

string tabs = "";
int i = 0;

void aumenta(){
    i ++;
    tabs = tabs + "   ";
}

void reduce(){
    i --;
    tabs = "";
    for(int x = 0; x < i; x++){
        tabs = tabs + "   ";
    }
}

void inicializarVP(){
    for (int i = 0; i < 20; i++){
        vectorParametros[i]=0;
    }
}

void inicializarVA(){
    for (int i = 0; i < 20; i++){
        vectorArgumentos[i]=0;
    }
}

class Regla{
protected:
    string ambito;
    char tipoTS;
    simbolo SIM;
public:
    virtual void muestra(){}
    virtual char validaTipo(string){}
    virtual void validaTipo(char, string){}
    virtual void mostrarLista(){
        TablaSimbolos.imprimir();
    }
};

//PROGRAMA
class R1 : public Regla{
    protected:
        Regla *Def;
    public:
        R1(Pila &p){
            p.pop();
            Def = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << "<PROGRAMA>\n";
            aumenta();
            if(Def != NULL) Def->muestra();
            reduce();
            cout << "</PROGRAMA>\n";
        }

        char validaTipo(string ambito){
			if(Def != NULL) Def->validaTipo(ambito);
		}
};

//DEFINICIONES
class R3 : public Regla{
     protected:
        Regla *Def;
        Regla *Defs;
    public:
        R3(Pila &p){
            p.pop();
            Defs = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            Def = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<DEFINICIONES>\n";
            aumenta();
            if(Def != NULL) Def->muestra();
            if(Defs != NULL) Defs->muestra();
            reduce();
            cout << tabs << "</DEFINICIONES>\n";
        }

        char validaTipo(string ambito){
			if(Def != NULL) Def->validaTipo(ambito);
			if(Defs != NULL) Defs->validaTipo(ambito);
		}
};

//DEFINICION
class R4 : public Regla{
    protected:
        Regla *DefVar;
    public:
        R4(Pila &p){
            p.pop();
            DefVar = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<DEFINICION>\n";
            aumenta();
            if(DefVar != NULL) DefVar->muestra();
            reduce();
            cout << tabs << "</DEFINICION>\n";
        }

        char validaTipo(string ambito){
			if(DefVar!= NULL) DefVar->validaTipo(ambito);
		}
};

//DEFINICIION
class R5 : public Regla{
    protected:
        Regla *DefFunc;
    public:
        R5(Pila &p){
            p.pop();
            DefFunc = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<DEFINICION>\n";
            aumenta();
            if(DefFunc != NULL) DefFunc->muestra();
            reduce();
            cout << tabs << "</DEFINICION>\n";
        }

        char validaTipo(string ambito){
            if(DefFunc != NULL) DefFunc->validaTipo(ambito);
		}
};

//DEFVAR
class R6 : public Regla{
    protected:
        string tipo, id;
        Regla *ListVar;
    public:
        R6(Pila &p){
            p.pop();
            p.pop(); //punto y coma
            p.pop();
            ListVar = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            id = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            tipo = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<DEF_VAR>\n";
            aumenta();
            cout << tabs << "< " << tipo << " >";
            cout << " < " << id << " >\n";
            if(ListVar != NULL) ListVar->muestra();
            cout << tabs << endl;
            reduce();
            cout << tabs << "</DEF_VAR>\n";
        }

        char validaTipo(string ambito){
            if(!TablaSimbolos.buscarVar(id, ambito)){
                tipoTS = tipo[0];
                SIM.setALL(id, tipoTS, ambito);
                TablaSimbolos.insertar(SIM);
            }
            else{
                tablaError.insertarError(1, id);
            }

            if(ListVar != NULL) ListVar->validaTipo(tipoTS, ambito);
        }
};

//LISTAVAR
class R8 : public Regla{
    protected:
        string id;
        Regla *ListVar;
    public:
        R8(Pila &p){
            p.pop();
            ListVar = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            id = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            p.pop(); //coma
        }

        void muestra(){
            cout << tabs << "<LISTA_VAR>\n";
            aumenta();
            cout << tabs << " < " << id << " >\n";
            if(ListVar != NULL) ListVar->muestra();
            reduce();
            cout << tabs << "</LISTA_VAR>\n";
        }

        void validaTipo(char tipoTS, string ambito){
            if(!TablaSimbolos.buscarVar(id, ambito)){
                SIM.setALL(id, tipoTS, ambito);
                TablaSimbolos.insertar(SIM);
            }
            else{
                tablaError.insertarError(1, id);
            }

            if(ListVar != NULL) ListVar->validaTipo(tipoTS, ambito);
        }
};

//DEFFUNC
class R9 : public Regla{
    protected:
        string tipo, id, pa, pc;
        Regla *Par, *BloqFunc;
    public:
        R9(Pila &p){
            p.pop();
            BloqFunc = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            pc = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            Par = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            pa = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            id = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            tipo = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<DEF_FUNC>\n";
            aumenta();
            cout << tabs << "< " << tipo << " >";
            cout << " < " << id << " >";
            cout << " < " << pa << " >";
            if(Par != NULL) Par->muestra();
            cout << " < " << pc << " >\n";
            if(BloqFunc != NULL) BloqFunc->muestra();
            reduce();
            cout << tabs << "</DEF_FUNC>\n";
        }

        char validaTipo(string ambito){
            if(!TablaSimbolos.buscarVar(id, ambito)){
                inicializarVP();
                countP = 0;
                tipoTS = tipo[0];
            }
            else{
                tablaError.insertarError(1, id);
            }

            if(Par != NULL) Par->validaTipo(id);

            SIM.setALL(id, tipoTS, ambito, vectorParametros);
            TablaSimbolos.insertar(SIM);

            if(BloqFunc != NULL) BloqFunc->validaTipo(id);
        }

};

//PARAMETROS
class R11 : public Regla{
    protected:
        string tipo, id;
        Regla *ListPar;
    public:
        R11(Pila &p){
            p.pop();
            ListPar = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            id = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            tipo = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<PARAMETROS>\n";
            aumenta();
            cout << tabs << "< " << tipo << " >";
            cout << " < " << id << " >";
            if(ListPar != NULL) ListPar->muestra();
            reduce();
            cout << tabs << "</PARAMETROS>\n";
        }

        char validaTipo(string ambito){
            if(!TablaSimbolos.buscarVar(id, ambito)){
                tipoTS = tipo[0];
                SIM.setALL(id, tipoTS, ambito);
                TablaSimbolos.insertar(SIM);

                vectorParametros[countP++] = tipoTS;
            }
            else{
                tablaError.insertarError(1, id);
            }

            if(ListPar != NULL) ListPar->validaTipo(tipoTS, ambito);
        }
};

//LISTA_PARAMETROS
class R13 : public Regla{
    protected:
        string tipo, id;
        Regla *ListPar;
    public:
        R13(Pila &p){
            p.pop();
            ListPar = ((NoTerminal*)+p.pop())->getNodo();
            p.pop();
            id = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            tipo = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            p.pop(); //coma
        }

        void muestra(){
            cout << tabs << "<LISTA_PARAM>\n";
            aumenta();
            cout << tabs << "< " << tipo << " >";
            cout << " < " << id << " >";
            if(ListPar != NULL) ListPar->muestra();
            reduce();
            cout << tabs << "</LISTA_PARAM>\n";
        }

        void validaTipo(char tipoTS, string ambito){
            if(!TablaSimbolos.buscarVar(id, ambito)){
                vectorParametros[countP++] = tipoTS;
                SIM.setALL(id, tipoTS, ambito);
                TablaSimbolos.insertar(SIM);
            }
            else{
                tablaError.insertarError(1, id);
            }

            if(ListPar != NULL) ListPar->validaTipo(tipoTS, ambito);
        }
};

//BLOQUE_FUNCION
class R14 : public Regla{
    protected:
        string la, lc;
        Regla *DefLocales;
    public:
        R14(Pila &p){
            p.pop();
            lc = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            DefLocales = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            la = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<BLOQ_FUNC>\n";
            aumenta();
            cout << tabs << "< " << la << " >" << endl;
            if(DefLocales != NULL) DefLocales->muestra();
            cout << tabs << "< " << lc << " >" << endl;
            reduce();
            cout << tabs << "</BLOQ_FUNC>\n";
        }

        char validaTipo(string ambito){
            if(DefLocales != NULL) DefLocales->validaTipo(ambito);
        }
};

//DEF_LOCALES
class R16 : public Regla{
    protected:
        Regla *DefLocal, *DefLocales;
    public:
        R16(Pila &p){
            p.pop();
            DefLocales = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            DefLocal = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<DEF_LOCALES>\n";
            aumenta();
            if(DefLocal != NULL) DefLocal->muestra();
            if(DefLocales != NULL) DefLocales->muestra();
            reduce();
            cout << tabs << "</DEF_LOCALES>\n";
        }

        char validaTipo(string ambito){
			if(DefLocal != NULL) DefLocal->validaTipo(ambito);
			if(DefLocales != NULL) DefLocales->validaTipo(ambito);
		}
};

//DEF_LOCAL
class R17 : public Regla{
    protected:
        Regla *DefVar;
    public:
        R17(Pila &p){
            p.pop();
            DefVar = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<DEF_LOCAL>\n";
            aumenta();
            if(DefVar != NULL) DefVar->muestra();
            reduce();
            cout << tabs << "</DEF_LOCAL>\n";
        }

        char validaTipo(string ambito){
			if(DefVar != NULL) DefVar->validaTipo(ambito);
		}
};

//DEF_LOCAL
class R18 : public Regla{
    protected:
        Regla *Sent;
    public:
        R18(Pila &p){
            p.pop();
            Sent = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<DEF_LOCAL>\n";
            aumenta();
            if(Sent != NULL) Sent->muestra();
            reduce();
            cout << tabs << "</DEF_LOCAL>\n";
        }

        char validaTipo(string ambito){
			if(Sent != NULL) Sent->validaTipo(ambito);
		}
};

//SENTENCIA
class R20 : public Regla{
    protected:
        Regla *Sent, *Sents;
    public:
        R20(Pila &p){
            p.pop();
            Sents = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            Sent = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<SENTENCIAS>\n";
            aumenta();
            if(Sents != NULL) Sents->muestra();
            if(Sent != NULL) Sent->muestra();
            reduce();
            cout << tabs << "</SENTENCIAS>\n";
        }

        char validaTipo(string){
			if(Sents != NULL) Sents->validaTipo(ambito);
			if(Sent != NULL) Sent->validaTipo(ambito);
		}
};

//SENTENCIA
class R21 : public Regla{
    protected:
        Regla *Exp;
        string id, asign;
    public:
        R21(Pila &p){
            p.pop();
            p.pop(); //punto y coma
            p.pop();
            Exp = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            asign = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            id = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<SENTENCIA>\n";
            aumenta();
            cout << tabs << "< " << id << " >";
            cout << " < " << asign << " >\n";
            if(Exp != NULL) Exp->muestra();
            reduce();
            cout << tabs << "</SENTENCIA>\n";
        }

        char validaTipo(string ambito){
			if(!TablaSimbolos.buscarVar(id, ambito) and !TablaSimbolos.buscarVar(id, "global")){
				tablaError.insertarError(2, id);
			}

			char tipoexp = Exp->validaTipo(ambito);
			if(tipoexp == TablaSimbolos.buscarTIP(id, ambito) or tipoexp == TablaSimbolos.buscarTIP(id, "global")){
				return tipoexp;
			}
			else{
				tablaError.insertarError(3, id);
				return 0;
			}
		}
};

//SENTENCIA
class R22 : public Regla{
    protected:
        Regla *Otro, *SentBloq, *Exp;
        string If, pa, pc;
    public:
        R22(Pila &p){
            p.pop();
            Otro = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            SentBloq = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            pc = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            Exp = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            pa = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            If = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<SENTENCIA>\n";
            aumenta();
            cout << tabs << "< " << If << " >";
            cout << " < " << pa << " >";
            if(Exp != NULL) Exp->muestra();
            cout << " < " << pc << " >";
            if(SentBloq != NULL) SentBloq->muestra();
            if(Otro != NULL) Otro->muestra();
            reduce();
            cout << tabs << "</SENTENCIA>\n";
        }

        char validaTipo(string ambito){
			if(Exp != NULL) Exp->validaTipo(ambito);
			if(SentBloq != NULL) SentBloq->validaTipo(ambito);
			if(Otro != NULL) Otro->validaTipo(ambito);
		}
};

//SENTENCIA
class R23 :public Regla{
    protected:
        Regla *Bloq, *Exp;
        string pa, pc, While;
    public:
        R23(Pila &p){
            p.pop();
            Bloq = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            pc = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            Exp = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            pa = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            While = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<SENTENCIA>\n";
            aumenta();
            cout << tabs << "< " << While << " >";
            cout << " < " << pa << " >";
            if(Exp != NULL) Exp->muestra();
            cout << " < " << pc << " >";
            if(Bloq != NULL) Bloq->muestra();
            reduce();
            cout << tabs << "</SENTENCIA>\n";
        }

        char validaTipo(string ambito){
			if(Exp != NULL) Exp->validaTipo(ambito);
			if(Bloq != NULL) Bloq->validaTipo(ambito);
		}
};

//SENTENCIA
class R24 : public Regla{
    protected:
        Regla *ValReg;
        string ret;
    public:
        R24(Pila &p){
            p.pop();
            p.pop(); //punto y coma
            p.pop();
            ValReg = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            ret = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<SENTENCIA>\n";
            aumenta();
            cout << tabs << "< " << ret << " > ";
            if(ValReg != NULL) ValReg->muestra();
            reduce();
            cout << tabs << "</SENTENCIA>\n";
        }

        char validaTipo(string ambito){
            char val = 0;
			if(ValReg != NULL) val = ValReg->validaTipo(ambito);
			if(val != TablaSimbolos.buscarTIP(ambito, "global")){
                tablaError.insertarError(6, "");
			}
		}
};

//SENTENCIA
class R25 : public Regla{
    protected:
        Regla *LlamFunc;
    public:
        R25(Pila &p){
            p.pop();
            p.pop();
            p.pop();
            LlamFunc = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<SENTENCIA>\n";
            aumenta();
            if(LlamFunc != NULL) LlamFunc->muestra();
            reduce();
            cout << tabs << "</SENTENCIA>\n";
        }

        char validaTipo(string ambito){
			if(LlamFunc != NULL) LlamFunc->validaTipo(ambito);
		}
};

//OTRO
class R27 : public Regla{
    protected:
        Regla *SentBloq;
        string Else;
    public:
        R27(Pila &p){
            p.pop();
            SentBloq = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            Else = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<OTRO>\n";
            aumenta();
            cout << tabs << "< " << Else << " >";
            if(SentBloq != NULL) SentBloq->muestra();
            reduce();
            cout << tabs << "</OTRO>\n";
        }

        char validaTipo(string ambito){
			if(SentBloq != NULL) SentBloq->validaTipo(ambito);
		}
};

//BLOQUE
class R28 : public Regla{
    protected:
        Regla *Sent;
        string pa, pc;
    public:
        R28(Pila &p){
            p.pop();
            pc = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            Sent = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            pa = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<BLOQUE>\n";
            aumenta();
            cout << tabs << "< " << pa << " >" << endl;
            if(Sent != NULL) Sent->muestra();
            cout << "< " << pc << " >" << endl;
            reduce();
            cout << tabs << "</BLOQUE>\n";
        }

        char validaTipo(string ambito){
			if(Sent != NULL) Sent->validaTipo(ambito);
		}
};

//VALOR_REGRESA
class R30 : public Regla{
    protected:
        Regla *Exp;
    public:
        R30(Pila &p){
            p.pop();
            Exp = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<VALOR_REGRESA>\n";
            aumenta();
            if(Exp != NULL) Exp->muestra();
            reduce();
            cout << tabs << "</VALOR_REGRESA>\n";
        }

        char validaTipo(string ambito){
			if(Exp != NULL) return Exp->validaTipo(ambito);
		}
};

//ARGUMENTOS
class R32 : public Regla{
    protected:
        Regla *Exp, *ListArg;
    public:
        R32(Pila &p){
            p.pop();
            Exp = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            ListArg = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<ARGUMENTOS>\n";
            aumenta();
            if(Exp != NULL) Exp->muestra();
            if(ListArg != NULL) ListArg->muestra();
            reduce();
            cout << tabs << "</ARGUMENTOS>\n";
        }

        char validaTipo(string ambito){
            char tipoEXP;
            countArgs ++;
			if(Exp != NULL) tipoEXP = Exp->validaTipo(ambito);
			vectorArgumentos[countArgs++] = tipoEXP;
			if(ListArg != NULL) ListArg->validaTipo(ambito);

			return tipoEXP;
		}
};

//LISTA_ARGUMENTOS
class R34 : public Regla{
    protected:
        Regla *ListArg, *Exp;
    public:
        R34(Pila &p){
            p.pop();
            ListArg = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            Exp = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            p.pop();
        }

        void muestra(){
            cout << tabs << "<LISTA_ARGUMENTOS>\n";
            aumenta();
            if(Exp != NULL) Exp->muestra();
            if(ListArg != NULL) ListArg->muestra();
            reduce();
            cout << tabs << "</LISTA_ARGUMENTOS>\n";
        }

        char validaTipo(string ambito){
            char tipoEXP;
            countArgs ++;
			if(Exp != NULL) tipoEXP = Exp->validaTipo(ambito);
			vectorArgumentos[countArgs++] = tipoEXP;
			if(ListArg != NULL) ListArg->validaTipo(ambito);

			return tipoEXP;
		}
};

//TERMINO
class R35 : public Regla{
    protected:
        Regla *LlamFunc;
    public:
        R35(Pila &p){
            p.pop();
            LlamFunc = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<TERMINO>\n";
            aumenta();
            if(LlamFunc != NULL) LlamFunc->muestra();
            reduce();
            cout << tabs << "</TERMINO>\n";
        }

        char validaTipo(string ambito){
			if(LlamFunc != NULL) return LlamFunc->validaTipo(ambito);
		}
};

//TERMINO
class R36 : public Regla{
    protected:
        string id;
    public:
        R36(Pila &p){
            p.pop();
            id = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<TERMINO>\n";
            aumenta();
            cout << tabs << "< " << id << " >" << endl;
            reduce();
            cout << tabs << "</TERMINO>\n";
        }

        char validaTipo(string ambito){
			if(!TablaSimbolos.buscarVar(id, ambito) and !TablaSimbolos.buscarVar(id, "global")){
				tablaError.insertarError(2, id);

			}
			return TablaSimbolos.buscarTIP(id, ambito);
		}
};

//TERMINO
class R37 : public Regla{
    protected:
        string entero;
    public:
        R37(Pila &p){
            p.pop();
            entero = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<TERMINO>\n";
            aumenta();
            cout << tabs << "< " << entero << " >\n";
            reduce();
            cout << tabs << "</TERMINO>\n";
        }

        char validaTipo(string ambito){
            return 'i';
		}
};

//TERMINO
class R38 : public Regla{
    protected:
        string real;
    public:
        R38(Pila &p){
            p.pop();
            real = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<TERMINO>\n";
            aumenta();
            cout << tabs << "< " << real << " >\n";
            reduce();
            cout << tabs << "</TERMINO>\n";
        }

        char validaTipo(string ambito){
            return 'f';
		}
};

//TERMINO
class R39 : public Regla{
    protected:
        string cadena;
    public:
        R39(Pila &p){
            p.pop();
            cadena = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<TERMINO>\n";
            aumenta();
            cout << tabs << "< " << cadena << " >\n";
            reduce();
            cout << tabs << "</TERMINO>\n";
        }

        char validaTipo(string ambito){
            return 's';
		}
};

//LLAMANDA_FUNC
class R40 : public Regla{
    protected:
        Regla *Arg;
        string pa, pc, id;
    public:
        R40(Pila &p){
            p.pop();
            pc = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            Arg = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            pa = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            id = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<LLAMADA_FUNC>\n";
            aumenta();
            cout << tabs << "< " << id << " >";
            cout << " < " << pa << " > ";
            if(Arg != NULL) Arg->muestra();
            cout << "< " << pc << " >\n";
            reduce();
            cout << tabs << "</LLAMADA_FUNC>\n";
        }

        char validaTipo(string ambito){
            inicializarVA();
            countArgs = 0;
            if(TablaSimbolos.buscarVar(id, ambito) and !TablaSimbolos.buscarVar(id, "global")){
                if(Arg != NULL) Arg->validaTipo(ambito);
                int cantidadFP = TablaSimbolos.buscarPAR(id, ambito).getNumPAram();
                if(cantidadFP != countArgs){
                    tablaError.insertarError(7, id);
                }
                else{
                    for(int i = 0; i < cantidadFP; i++){
                        if(TablaSimbolos.buscarPAR(id, ambito).getVectorPAram(i) != vectorArgumentos[i]){
                            tablaError.insertarError(8, id);
                        }
                    }
                }
                return TablaSimbolos.buscarTIP(id, ambito);
            }
        }
};

//SENTENCIA_BLOQUE
class R41 : public Regla{
    protected:
        Regla *Sent;
    public:
        R41(Pila &p){
            p.pop();
            Sent = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<SENTENCIA_BLOQUE>\n";
            aumenta();
            if(Sent != NULL) Sent->muestra();
            reduce();
            cout << tabs << "</SENTENCIA_BLOQUE>\n";
        }

        char validaTipo(string ambito){
            if(Sent != NULL) Sent->validaTipo(ambito);
        }
};

//SENTENCIA_BLOQUE
class R42 : public Regla{
    protected:
        Regla *Bloq;
    public:
        R42(Pila &p){
            p.pop();
            Bloq = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<SENTENCIA_BLOQUE>\n";
            aumenta();
            if(Bloq != NULL) Bloq->muestra();
            reduce();
            cout << tabs << "/<SENTENCIA_BLOQUE>\n";
        }

        char validaTipo(string ambito){
			return Bloq->validaTipo(ambito);
		}
};

//EXPRESION
class R43 : public Regla{
    protected:
        Regla *Exp;
        string pa, pc;
    public:
        R43(Pila &p){
            p.pop();
            pc = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            Exp = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            pa = ((Terminal*)p.pop())->getTerminal();
        }

        void muestra(){
            cout << tabs << "<EXPRESION>\n";
            aumenta();
            cout << tabs << "< " << pa << " >" << endl;
            if(Exp != NULL) Exp->muestra();
            cout << "< " << pc << " >" << endl;
            reduce();
            cout << tabs << "</EXPRESION>\n";
        }

        char validaTipo(string ambito){
			return Exp->validaTipo(ambito);
		}
};

//EXPRESION
class R44 : public Regla{
    protected:
        Regla *Exp;
        string OpSum;
    public:
        R44(Pila &p){
            p.pop();
            Exp = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            OpSum = ((Terminal*)p.pop())->getTerminal();

        }

        void muestra(){
            cout << tabs << "<EXPRESION>\n";
            aumenta();
            cout << tabs << " < " << OpSum << " > \n";
            if(Exp != NULL) Exp->muestra();
            reduce();
            cout << tabs << "</EXPRESION>\n";
        }

        char validaTipo(string ambito){
			return Exp->validaTipo(ambito);
		}
};

//EXPRESION
class R45 : public Regla{
    protected:
        Regla *Exp;
        string OpNot;
    public:
        R45(Pila &p){
            p.pop();
            Exp = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            OpNot = ((Terminal*)p.pop())->getTerminal();

        }

        void muestra(){
            cout << tabs << "<EXPRESION>\n";
            aumenta();
            cout << tabs << "< " << OpNot << " > \n";
            if(Exp != NULL) Exp->muestra();
            reduce();
            cout << tabs << "</EXPRESION>\n";
        }

        char validaTipo(string ambito){
			return Exp->validaTipo(ambito);
		}
};

//EXPRESION
class R46 : public Regla{
    protected:
        Regla *Exp1, *Exp2;
        string OpMul;
    public:
        R46(Pila &p){
            p.pop();
            Exp2 = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            OpMul = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            Exp1 = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<EXPRESION>\n";
            aumenta();
            if(Exp1 != NULL) Exp1->muestra();
            cout << tabs << "< " << OpMul << " > \n";
            if(Exp2 != NULL) Exp2->muestra();
            reduce();
            cout << tabs << "</EXPRESION>\n";
        }

        char validaTipo(string ambito){
			char tipoizq = Exp1->validaTipo(ambito);
			char tipoder = Exp2->validaTipo(ambito);

			if(tipoizq == tipoder){
				return tipoder;
			}
			else{
                string err = tipoizq + " >< " + tipoder;
				tablaError.insertarError(4, err);
				return 0;
			}
		}
};

//EXPRESION
class R47 : public Regla{
    protected:
        Regla *Exp1, *Exp2;
        string OpSum;
    public:
        R47(Pila &p){
            p.pop();
            Exp2 = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            OpSum = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            Exp1 = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<EXPRESION>\n";
            aumenta();
            if(Exp1 != NULL) Exp1->muestra();
            cout << tabs << "< " << OpSum << " > \n";
            if(Exp2 != NULL) Exp2->muestra();
            reduce();
            cout << tabs << "</EXPRESION>\n";
        }

        char validaTipo(string ambito){
			char tipoizq = Exp1->validaTipo(ambito);
			char tipoder = Exp2->validaTipo(ambito);

			if(tipoder == tipoizq){
				return tipoder;
			}
			else{
                string err = tipoizq + " >< " + tipoder;
				tablaError.insertarError(4, err);
				return 0;
			}
		}
};

//EXPRESION
class R48 : public Regla{
    protected:
        Regla *Exp1, *Exp2;
        string OpRelac;
    public:
        R48(Pila &p){
            p.pop();
            Exp2 = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            OpRelac = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            Exp1 = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<EXPRESION>\n";
            aumenta();
            if(Exp1 != NULL) Exp1->muestra();
            cout << tabs << "< " << OpRelac << " > \n";
            if(Exp2 != NULL) Exp2->muestra();
            reduce();
            cout << tabs << "</EXPRESION>\n";
        }

        char validaTipo(string ambito){
			char tipoizq = Exp1->validaTipo(ambito);
			char tipoder = Exp2->validaTipo(ambito);

			if(tipoder == tipoizq){
				return tipoder;
			}
			else{
                string err = tipoizq + " >< " + tipoder;
				tablaError.insertarError(4, err);
				return 0;
			}
		}
};

//EXPRESION
class R49 : public Regla{
    protected:
        Regla *Exp1, *Exp2;
        string OpIgual;
    public:
        R49(Pila &p){
            p.pop();
            Exp2 = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            OpIgual = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            Exp1 = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<EXPRESION>\n";
            aumenta();
            if(Exp1 != NULL) Exp1->muestra();
            cout << tabs << "< " << OpIgual << " > \n";
            if(Exp2 != NULL) Exp2->muestra();
            reduce();
            cout << tabs << "</EXPRESION>\n";
        }

        char validaTipo(string ambito){
			char tipoizq = Exp1->validaTipo(ambito);
			char tipoder = Exp2->validaTipo(ambito);

			if(tipoder == tipoizq){
				return tipoder;
			}
			else{
                string err = tipoizq + " >< " + tipoder;
				tablaError.insertarError(4, err);
				return 0;
			}
		}
};

//EXPRESION
class R50 : public Regla{
    protected:
        Regla *Exp1, *Exp2;
        string OpAnd;
    public:
        R50(Pila &p){
            p.pop();
            Exp2 = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            OpAnd = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            Exp1 = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<EXPRESION>\n";
            aumenta();
            if(Exp1 != NULL) Exp1->muestra();
            cout << tabs << "< " << OpAnd << " > \n";
            if(Exp2 != NULL) Exp2->muestra();
            reduce();
            cout << tabs << "</EXPRESION>\n";
        }

        char validaTipo(string ambito){
			char tipoizq = Exp1->validaTipo(ambito);
			char tipoder = Exp2->validaTipo(ambito);

			if(tipoder == tipoizq){
				return tipoder;
			}
			else{
                string err = tipoizq + " >< " + tipoder;
				tablaError.insertarError(4, err);
				return 0;
			}
		}
};

//EXPRESION
class R51 : public Regla{
    protected:
        Regla *Exp1, *Exp2;
        string OpOr;
    public:
        R51(Pila &p){
            p.pop();
            Exp2 = ((NoTerminal*)p.pop())->getNodo();
            p.pop();
            OpOr = ((Terminal*)p.pop())->getTerminal();
            p.pop();
            Exp1 = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<EXPRESION>\n";
            aumenta();
            if(Exp1 != NULL) Exp1->muestra();
            cout << tabs << "< " << OpOr << " > \n";
            if(Exp2 != NULL) Exp2->muestra();
            reduce();
            cout << tabs << "</EXPRESION>\n";
        }

        char validaTipo(string ambito){
			char tipoizq = Exp1->validaTipo(ambito);
			char tipoder = Exp2->validaTipo(ambito);

			if(tipoder == tipoizq){
				return tipoder;
			}
			else{
                string err = tipoizq + " >< " + tipoder;
				tablaError.insertarError(4, err);
				return 0;
			}
		}
};

//EXPRESION
class R52 : public Regla{
    protected:
        Regla *Term;
    public:
        R52(Pila &p){
            p.pop();
            Term = ((NoTerminal*)p.pop())->getNodo();
        }

        void muestra(){
            cout << tabs << "<EXPRESION>\n";
            aumenta();
            if(Term != NULL) Term->muestra();
            reduce();
            cout << tabs << "</EXPRESION>\n";
        }

        char validaTipo(string ambito){
            return Term->validaTipo(ambito);
        }
};



#endif // REGLAS_H_INCLUDED

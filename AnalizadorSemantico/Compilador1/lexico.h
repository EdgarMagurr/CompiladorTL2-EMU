#ifndef LEXICO_H_INCLUDED
#define LEXICO_H_INCLUDED

#include "lista_tokens.h"
#include "tokens.h"

using namespace std;

string reservadas[]{
    "void", "int", "while", "else", "if", "return", "float", "void"
};

enum{
    Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10, Q11, Q12, Q13, Q14, Q15, Q16, Q17, Q18, Q19, Q20, Q21, Q22, Q23, Q24, Q25, Q26, Q27, Q28, Q29, Q30, Q31, Q32, K, ESTADOS
};

enum{
    E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15, E16, E17, E18, E19, E20, E21, E22, E23, E24, ENTRADAS
};

enum{
    NADA, TOKEN_ID, TOKEN_NUM, TOKEN_SUMA, TOKEN_RES, TOKEN_MUL, TOKEN_DIV, TOKEN_MAY, TOKEN_MEN, TOKEN_MAYIG, TOKEN_MENIG,
    TOKEN_PA, TOKEN_PC, TOKEN_LA, TOKEN_LC, TOKEN_DIF, TOKEN_DELIM, TOKEN_MOD, TOKEN_INVA, TOKEN_COMAPE, TOKEN_COMPARE,
    TOKEN_COMCER, TOKEN_COMSIM, TOKEN_ASIG, TOKEN_COMA, TOKEN_RESERVADA, TOKEN_FLOAT, TOKEN_CADENA, TOKEN_OR, TOKEN_AND, OR, AND, IF,
    ELSE, WHILE, RETUNR, TOKEN_NEG, NUMERO
};

string nombres[NUMERO]{
    "NADA", "identificador", "entero", "opSuma", "opSuma", "opMul", "opMul", "opRelac", "opRelac", "opRelac", "opRelac",
    "(", ")", "{", "}", "opIgualdad", ";", "%", "TOKEN_INVA", "opIgualdad", "opIgualdad",
    "TOKEN_COMCER", "TOKEN_COMSIM", "=", ",", "tipo", "real", "cadena", "opOr", "opAnd", "OR", "AND", "if", "else", "while", "return", "opNeg"
};

int tranciciones[ESTADOS][ENTRADAS]{
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	K,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q1,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q1,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, K, Q1, Q28, Q29},
    {K,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	K,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q27, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	K,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	K,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q19,	Q7,	Q8,	Q9,	Q14,	K,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q17,	Q18,	Q7,	Q8,	Q9,	Q14,	K,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q15,	Q14,	K,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q1,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q16,	Q14,	K,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q21,	Q14,	K,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q20,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q1,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q25,	Q25,	Q25,	Q25,	Q25,	Q25,	Q25,	Q25,	Q25,	Q25,	Q25,	Q25,	Q25,	Q25,	Q25,	Q25,	Q25,	Q25, Q25, Q30, Q25, Q25, Q25},
    {K,	Q26,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, K, Q27, Q28, Q29},
    {K,	Q27,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, K, K, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q31, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q32},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, K, Q29},
    {Q1,	Q2,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, Q1, Q28, K},
    {K,	K,	Q3,	Q4,	Q5,	Q6,	Q7,	Q8,	Q9,	Q14,	Q0,	Q0,	Q10,	Q11,	Q12,	Q13,	Q22,	Q23, Q24, Q25, Q26, K, Q28, Q29},
};

int salidas[ESTADOS][ENTRADAS]{
    {NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA, NADA, NADA, NADA, NADA, NADA},
    {NADA,	NADA,	TOKEN_ID,	TOKEN_ID,	TOKEN_ID,	TOKEN_ID,	TOKEN_ID,	TOKEN_ID,	TOKEN_ID,	TOKEN_ID,	NADA,	TOKEN_ID,	TOKEN_ID,	TOKEN_ID,	TOKEN_ID,	TOKEN_ID,	TOKEN_ID,	TOKEN_ID,	TOKEN_ID, TOKEN_ID,	TOKEN_ID,	NADA, TOKEN_ID, TOKEN_ID},
    {NADA,	NADA,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM,	TOKEN_NUM, TOKEN_NUM, NADA, NADA, TOKEN_NUM, TOKEN_NUM},
    {TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA,	TOKEN_SUMA},
    {TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES,	TOKEN_RES},
    {TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	NADA,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL,	TOKEN_MUL},
    {TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	NADA,	NADA,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV,	TOKEN_DIV},
    {TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	NADA,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY,	TOKEN_MAY},
    {TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	NADA,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN,	TOKEN_MEN},
    {TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	NADA,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG,	TOKEN_ASIG},
    {TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA,	TOKEN_PA},
    {TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC,	TOKEN_PC},
    {TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA,	TOKEN_LA},
    {TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC, TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC,	TOKEN_LC},
    {TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	NADA,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG, TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG,	TOKEN_NEG},
    {TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG},
    {TOKEN_MENIG,	TOKEN_MENIG,	TOKEN_MENIG,	TOKEN_MENIG,	TOKEN_MENIG,	TOKEN_MENIG,	TOKEN_MENIG,	TOKEN_MENIG,	TOKEN_MENIG,	TOKEN_MENIG,	TOKEN_MENIG,	TOKEN_MENIG,	TOKEN_MENIG,	TOKEN_MENIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG,	TOKEN_MAYIG},
    {TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE,	TOKEN_COMAPE},
    {TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM,	TOKEN_COMSIM},
    {TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER,	TOKEN_COMCER},
    {TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF,	TOKEN_DIF},
    {TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE,	TOKEN_COMPARE},
    {TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM,	TOKEN_DELIM},
    {TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD,	TOKEN_MOD},
    {TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA,	TOKEN_COMA},
    {NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA,	NADA, NADA, NADA, NADA, NADA, NADA},
    {NADA,	NADA,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT, TOKEN_FLOAT, NADA, NADA, TOKEN_FLOAT, TOKEN_FLOAT},
    {NADA,	NADA,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT,	TOKEN_FLOAT, TOKEN_FLOAT, TOKEN_INVA, TOKEN_INVA, TOKEN_FLOAT, TOKEN_FLOAT},
    {OR,	OR,	OR,	OR,	OR,	OR,	OR,	OR,	OR,	OR,	OR,	OR,	OR,	OR,	OR,	OR,	OR,	NADA,	OR, OR, OR, OR, NADA, OR},
    {AND,	AND,	AND,	AND,	AND,	AND,	AND,	AND,	AND,	AND,	AND,	AND,	AND,	AND,	AND,	AND,	AND,	NADA,	AND, AND, AND, AND, AND, NADA},
    {TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA,	TOKEN_CADENA, TOKEN_CADENA, TOKEN_CADENA, TOKEN_CADENA, TOKEN_CADENA, TOKEN_CADENA},
    {TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	TOKEN_OR,	NADA,	TOKEN_OR, TOKEN_OR, TOKEN_OR, TOKEN_OR, NADA, TOKEN_OR},
    {TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	TOKEN_AND,	NADA,	TOKEN_AND, TOKEN_AND, TOKEN_AND, TOKEN_AND, TOKEN_AND, NADA},
    {NADA,	NADA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	NADA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA,	TOKEN_INVA},
};

int funcion_estado(char c){
    if((c >= 'a' and c <= 'z') or(c >= 'A' and c <= 'Z')){
            return E0;
    }
    else if(c >= '0' and c <= '9'){
        return E1;
    }
    else if(c == '+'){
        return E2;
    }
    else if(c == '-'){
        return E3;
    }
    else if(c == '*'){
        return E4;
    }
    else if(c == '/'){
        return E5;
    }
    else if(c == '>'){
        return E6;
    }
    else if(c == '<'){
        return E7;
    }
    else if(c == '='){
        return E8;
    }
    else if(c == '!'){
        return E9;
    }
    else if(c == '_'){
        return E10;
    }
    else if(c == ' ' or c == '\n' or c == '\t'){
        return E11;
    }
    else if(c == '('){
        return E12;
    }
    else if(c == ')'){
        return E13;
    }
    else if(c == '{'){
        return E14;
    }
    else if(c == '}'){
        return E15;
    }
    else if(c == ';'){
        return E16;
    }
    else if(c == '%'){
        return E17;
    }
    else if(c == ','){
        return E18;
    }
    else if(c == '"'){
        return E19;
    }
    else if(c == '.'){
        return E20;
    }
    else if(c == '|'){
        return E22;
    }
    else if(c == '&'){
        return E23;
    }
    else{
        return E11;
    }
}

int clase(int sal){
    int tipo;

    if(sal == TOKEN_ID){
        tipo = 0;
    }
    else if(sal == TOKEN_NUM){
        tipo = 1;
    }
    else if(sal == TOKEN_FLOAT){
        tipo = 2;
    }
    else if(sal == TOKEN_CADENA){
        tipo = 3;
    }
    else if(sal == TOKEN_RESERVADA){
        tipo = 4;
    }
    else if(sal == TOKEN_SUMA || sal == TOKEN_RES){
        tipo = 5;
    }
    else if(sal == TOKEN_MUL || sal == TOKEN_DIV){
        tipo = 6;
    }
    else if(sal == TOKEN_MAY || sal == TOKEN_MAYIG || sal == TOKEN_MEN || sal == TOKEN_MENIG){
        tipo = 7;
    }
    else if(sal == TOKEN_OR){
        tipo = 8;
    }
    else if(sal == TOKEN_AND){
        tipo = 9;
    }
    else if(sal == TOKEN_NEG){
        tipo = 10;
    }
    else if(sal == TOKEN_DIF || sal == TOKEN_COMAPE || sal == TOKEN_COMPARE){
        tipo = 11;
    }
    else if(sal == TOKEN_DELIM){
        tipo = 12;
    }
    else if(sal == TOKEN_COMA){
        tipo = 13;
    }
    else if(sal == TOKEN_PA){
        tipo = 14;
    }
    else if(sal == TOKEN_PC){
        tipo = 15;
    }
    else if(sal == TOKEN_LA){
        tipo = 16;
    }
    else if(sal == TOKEN_LC){
        tipo = 17;
    }
    else if(sal == TOKEN_ASIG){
        tipo = 18;
    }
    else if(sal == IF){
        tipo = 19;
    }
    else if(sal == WHILE){
        tipo = 20;
    }
    else if(sal == RETUNR){
        tipo = 21;
    }
    else if(sal == ELSE){
        tipo = 22;
    }

    return tipo;
}

 class lexico{
    public:
        tokens  TK;
        lista <tokens> listTK;

    public:
        lista<tokens> lex(char[]);
 };

lista<tokens> lexico::lex(char cadena[]){
    int estado, entrada_actual, tamanio, cont, salida, contact, tipo;
    string actual, hola, nombre;

    estado = Q0;
    salida = NADA;
    tamanio = strlen(cadena);
    cadena[tamanio] = ' ';

    for(cont = 0; cont < tamanio; cont ++){
        entrada_actual = funcion_estado(cadena[cont]);
        salida = salidas[estado][entrada_actual];
        estado = tranciciones[estado][entrada_actual];
        nombre = nombres[salida];

        if(salida == NADA and cadena[cont] != ' ' and cadena[cont] != '\n' and cadena[cont] != '\t'){
            hola = cadena[cont];
            actual.append(hola);
        }

        if(salida != NADA){
            for(contact = 0; contact < 7; contact++){
               if(actual == reservadas[contact]){
                    if(actual == "if"){
                        salida = IF;
                        nombre = "if";
                    }
                    else if(actual == "else"){
                        salida = ELSE;
                        nombre = "else";
                    }
                    else if(actual == "while"){
                        salida = WHILE;
                        nombre = "while";
                    }
                    else if(actual == "return"){
                        salida = RETUNR;
                        nombre = "return";
                    }
                    else{
                        salida = TOKEN_RESERVADA;
                        nombre = nombres[salida];
                    }
                }
            }

            tipo = clase(salida);

            TK.setALL(tipo, nombres[salida], actual);
            listTK.insertar(TK);


            actual.clear();

            if(cadena[cont] != ' ' and cadena[cont] != '\n' and cadena[cont] != '\t'){
                hola = cadena[cont];
                actual.append(hola);
            }
        }
    }

    entrada_actual = funcion_estado(cadena[cont]);
        salida = salidas[estado][entrada_actual];
        estado = tranciciones[estado][entrada_actual];
        nombre = nombres[salida];

    if(salida == NADA and cadena[cont] != ' ' and cadena[cont] != '\n' and cadena[cont] != '\t'){
        estado = 0;
        hola = cadena[cont];
        actual.append(hola);
    }

    if(salida != NADA){
        for(contact = 0; contact < 7; contact++){
            if(actual == reservadas[contact]){
                if(actual == "if"){
                    salida = IF;
                    nombre = "if";
                }
                else if(actual == "else"){
                    salida = ELSE;
                    nombre = "else";
                }
                else if(actual == "while"){
                    salida = WHILE;
                    nombre = "while";
                }
                else if(actual == "return"){
                    salida = RETUNR;
                    nombre = "return";
                }
                else{
                    salida = TOKEN_RESERVADA;
                    nombre = nombres[salida];
                }
            }
        }

        tipo = clase(salida);

        TK.setALL(tipo, nombres[salida], actual);
        listTK.insertar(TK);

        actual.clear();
    }

    TK.setALL(23, "$", "$");
    listTK.insertar(TK);

    return listTK;
}

#endif // LEXICO_H_INCLUDED

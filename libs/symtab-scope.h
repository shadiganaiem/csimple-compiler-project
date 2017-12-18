#ifndef SYMB_TAB_H_
#define SYMB_TAB_H_

typedef enum type {
    VOID,
    BOOLEAN,
    CHAR,
    STRING,
    INTEGER,
    INT_PTR,
    CHAR_PTR
} type;

typedef struct args
{
    type type;         // arg type
    struct args *next; // next arg in list
} args;

typedef struct function
{
    struct args *args; // function args
    type r_value;      // return type
} function;

typedef struct SymbEntry
{
    char *name;                  // symbol name
    type var_type;               // if it's a var
    struct function *data;       // if it's a func
    struct SymbEntry *nextEntry; // next Entry in "table"
} SymbEntry;

typedef struct ScopeStack
{
    char *name;
    struct SymbEntry *table_ptr;
    struct ScopeStack *next_scope;
} ScopeStack;

void pop(ScopeStack **);
void push(ScopeStack **, ScopeStack *);
void printStack(ScopeStack **);

SymbEntry *search(ScopeStack **, char *);
void insert(ScopeStack *, SymbEntry *);
void printTable(char *, SymbEntry *);
#endif
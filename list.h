typedef struct cell {
char* data;
struct cell* next;
}Cell;
typedef Cell*List;

List* initList();

Cell* buildCell(char* ch) ;

insertFirst(List *L, Cell* C);

char* ctos(Cell* c);

void ltos(List* L) ;

Cell* listGet(List* L, int i);

Cell* listGet(List* L, int i) ;

Cell* searchList(List* L, char* str) ;

List* stol(char* s);

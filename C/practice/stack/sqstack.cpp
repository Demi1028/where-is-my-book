#include <stdio.h>
#include <string.h>
#define Max 100

typedef char Elemtype;
typedef struct {
    Elemtype data[Max];
    Elemtype *top;
}Sqstack;

Initstack(Sqstack *&sqstack){
    sqstack = (Sqstack*)malloc(sizeof(Sqstack));

}

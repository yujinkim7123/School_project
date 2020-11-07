#include <stdio.h>
#include "mul.h"
#include "add.h"
#include "sub.h"


int main(){
int x = 10;
int y = 5;

printf("%d %d %d\n", sub(x, y), mul(x,y), add(x,y));

}

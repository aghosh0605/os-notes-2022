#include<stdio.h> #include<unistd.h>

void main() {
execl("./hello", "./hello", (char *)0); printf("This wouldn't print\n"); return;
}

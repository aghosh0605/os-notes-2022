#include<stdio.h> #include<unistd.h>

void main() { int pid;
pid = fork();

/* Child process */ if (pid == 0) {
printf("Child process: Running Hello World Program\n"); execl("./hello", "./hello", (char *)0);
printf("This wouldn't print\n");
} else { /* Parent process */
sleep(3);
printf("Parent process: Running While loop Program\n"); execl("./loop", "./loop", (char *)0);
printf("Won't reach here\n");
}
return;
}

#include <stdio.h> 
#include <string.h> 
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[0]) { int pid;
int err;
int num_times;
char num_times_str[5];

/* In no command line arguments are passed, then loop maximum count taken as 10 */
if (argc == 1) {
printf("Taken loop maximum as 10\n"); num_times = 10;
sprintf(num_times_str, "%d", num_times);
} else {
strcpy(num_times_str, argv[1]); printf("num_times_str is %s\n", num_times_str);

}
pid = fork();
/* Child process */ if (pid == 0) {
printf("Child process: Running Hello World Program\n"); err = execl("./hello", "./hello", (char *)0); printf("Error %d\n", err);
perror("Execl error: "); printf("This wouldn't print\n");
} else { /* Parent process */ sleep(3);
printf("Parent process: Running While loop Program\n"); execl("./loop", "./loop", (char *)num_times_str, (char *)0); printf("Won't reach here\n");
}
return 0;
}

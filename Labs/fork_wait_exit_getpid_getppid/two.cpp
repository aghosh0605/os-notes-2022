// Program to demonstrate bottom to up execution
// of processes using fork() and wait()
#include <iostream>
#include <sys/wait.h> // for wait()
#include <unistd.h> // for fork()
using namespace std;
int main()
{
 // creating 4 process using 2 fork calls
 // 1 parent : 2 child : 1 grand-child
 pid_t id1 = fork();
 pid_t id2 = fork();


 if (id1 >0 && id2 > 0)
 {
  cout << "\nChild Process id : "
   << getpid() << endl;
  wait (NULL);
  cout << "\nChild Process with parent id : "
   << getppid() << endl;
 }
 // parent process
 if (id1 > 0 && id2 > 0) {
  wait(NULL);
  wait(NULL);
  cout << "Parent Terminated" << endl;
 }

 // 1st child
 else if (id1 == 0 && id2 > 0) {

  // sleep the process for 2 seconds
  // to ensure 2nd child executes first
  sleep(2);
  wait(NULL);
  cout << "1st child Terminated" << endl;
  
 }

 // second child
 else if (id1 > 0 && id2 == 0) {
  // sleep the process for 1 second
  sleep(1);
  cout << "2nd Child Terminated" << endl;
 }

 // grand child
 else {
  cout << "Grand Child Terminated" << endl;
  exit(0);
 }
 return 0;
}

#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
 int pid;
 pid = fork();
 if (pid == 0)
 {
  cout << "\n child  Process id : "
   << getpid() << endl;
  cout << "\nChild Process with parent id : "
   << getppid() << endl;
  
 }
 return 0;
}

#include<bits/stdc++.h>
using namespace std;
// Function to allocate memory to  
// blocks as per First fit algorithm
void First_Fit(int block_size[], int total_blocks, int process_size[], int total_process) {
   int allocation[total_process];
   memset(allocation, -1, sizeof(allocation));
   //this for loop wll pick eact process and allocate a first fit block to it
   for (int i = 0; i < total_process; i++) {
      for (int j = 0; j < total_blocks; j++) {
         if (block_size[j] >= process_size[i]) {
            allocation[i] = j;
            block_size[j] -= process_size[i];
            break;
         }
      }
   }
   cout << "\nProcess No.\tProcess Size\tBlock no.\n";
   for (int i = 0; i < total_process; i++) {
      cout << " " << i+1 << "\t\t" << process_size[i] << "\t\t";
      if (allocation[i] != -1)
         cout << allocation[i] + 1;
      else
         cout << "Not Allocated";
         cout << endl;
   }
}
int main() {
   //create array to store block sizes
   int block_size[] = {300, 50, 200, 350, 70};  
    //create array to store process sizes
   int process_size[] = {200, 47, 212, 426, 10};
    //variable total_blocks that contain total number of blocks
   int total_blocks = sizeof(block_size) / sizeof(block_size[0]);
    //variable total_process that contain total number of blocks
   int total_process = sizeof(process_size) / sizeof(process_size[0]);
    //calling the function First_fit
   First_Fit(block_size, total_blocks, process_size, total_process);
   return 0 ;
}

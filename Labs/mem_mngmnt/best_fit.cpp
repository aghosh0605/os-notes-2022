#include <iostream>
#include <memory>
#include <cstring>
#include <string.h>
using namespace std;
// To allocate the memory to blocks as per Best fit
// algorithm
void bestfit(int bsize[], int m, int psize[], int n) {
   // To store block id of the block allocated to a
   // process
   int alloc[n];
   // Initially no block is assigned to any process
    memset(alloc, -1, sizeof(alloc));
   // pick each process and find suitable blocks
   // according to its size ad assign to it
   for (int i=0; i<n; i++) {
      // Find the best fit block for current process
      int bestIdx = -1;
      for (int j=0; j<m; j++) {
         if (bsize[j] >= psize[i]) {
            if (bestIdx == -1)
               bestIdx = j;
            else if (bsize[bestIdx] > bsize[j])
               bestIdx = j;
         }
      }
      // If we could find a block for current process
      if (bestIdx != -1) {
         // allocate block j to p[i] process
         alloc[i] = bestIdx;
         // Reduce available memory in this block.
         bsize[bestIdx] -= psize[i];
      }
   }
   cout << "\nProcess No.\tProcess Size\tBlock no.\n";
   for (int i = 0; i < n; i++) {
      cout << " " << i+1 << "\t\t\t\t" << psize[i] << "\t\t\t\t";
      if (alloc[i] != -1)
         cout << alloc[i] + 1;
      else
         cout << "Not Allocated";
         cout << endl;
   }
}
// Driver code
int main() {
   int bsize[] = {100, 500, 200, 300, 400};
   int psize[] = {112, 518, 110, 526};
   int m = sizeof(bsize)/sizeof(bsize[0]);
   int n = sizeof(psize)/sizeof(psize[0]);
   bestfit(bsize, m, psize, n);
   return 0 ;
}

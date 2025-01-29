#include <stdio.h>

int main(){
    int val;
    scanf("%d",&val); /* If you are defining something other than a string, you must use &. otherwise scanf will interpret it as an address and try to write to that memory location, causing a segmentation error. */

    if ((val>2) & (val<7))   /* the & and | operators will always evaluate both conditions, but && and || can often skip the second condition.*/
        puts("Count has gone up.");
    else if (val == 10)
        puts("Count has gone down.");
    return 0;
}

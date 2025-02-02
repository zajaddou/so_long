
#include <stdio.h>

// Player : y:1 x:1
// Monster : y:1 x:1

void my_algo(int *py, int *px, int my, int mx) 
{
    if (py > my)
        my++;
    else if (py < my)
        my--;

    if (py > mx)
        mx++;
    else if (py < mx)
        mx--;
}



int main(void)
{
    



    return (0);
}

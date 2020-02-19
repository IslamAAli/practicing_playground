#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function 
    int a_1, b_1;
    a_1 = *a+(*b);
    
    if (*a > *b )
        b_1 = *a-(*b);
    else
        b_1 = *b-(*a);
    
    *a = a_1;
    *b = b_1;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}


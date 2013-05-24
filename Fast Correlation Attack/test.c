#include <stdio.h>

int LFSR[31] = {0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1};

int x[100] = {1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0,
0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1,
0, 1, 0, 0, 0, 1, 0, 1, 0, 1};

int gen_seq[100];

int main()
{
    int i,k,tmp,gen,test;

    for(k=0;k<100;k++) {
        gen_seq[k] = (LFSR[0]*LFSR[1]+LFSR[5]+LFSR[6]+LFSR[30])%2;
        gen = (LFSR[27]+LFSR[30])%2;
        for(i=30;i>0;i--)
            LFSR[i] = LFSR[i-1];
        LFSR[0] = gen;
        //printf("%d",gen_seq[k]);
    }
    printf("\n");

    int compteur = 0;
    test = 1;
    for(k=0;k<100;k++) {
        printf("%d %d\n",gen_seq[k],x[k]);
        if(gen_seq[k]!=x[k]) {
            test = 0;
            compteur++;
        }
    }

    //printf("compteur = %d\n",compteur);

    if(test==1)
        printf("SOLUTION TROUVEE !!\n");
    return 0;
}

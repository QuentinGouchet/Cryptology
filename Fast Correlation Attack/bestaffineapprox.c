#include<stdio.h>
#include<math.h>

int main () {
    int Wa[32];
    int F[32] = {0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};

    int i,j;
    for(i=0;i<32;i++) {
        if(F[i]==0)
            Wa[i] = 1;
        else
            Wa[i] = -1;
        printf("%2d",Wa[i]);
    }
    printf("\n");

    int tmp1,tmp2,tmp3,tmp4;
    for(i=0;i<16;i++) {
        tmp1 = Wa[2*i];
        tmp2 = Wa[2*i+1];
        Wa[2*i] = tmp1+tmp2;
        Wa[2*i+1] = tmp1-tmp2;
        printf("%2d%2d",Wa[2*i],Wa[2*i+1]);
    }
    printf("\n");

    for(i=0;i<8;i++) {
        tmp1 = Wa[4*i];
        tmp2 = Wa[4*i+1];
        tmp3 = Wa[4*i+2];
        tmp4 = Wa[4*i+3];
        Wa[4*i] = tmp1+tmp3;
        Wa[4*i+1] = tmp2+tmp4;
        Wa[4*i+2] = tmp1-tmp3;
        Wa[4*i+3] = tmp2-tmp4;
        printf("%2d%2d%2d%2d",Wa[4*i],Wa[4*i+1],Wa[4*i+2],Wa[4*i+3]);
    }
    printf("\n");

    for(i=0;i<4;i++) {
        tmp1 = Wa[8*i];
        tmp2 = Wa[8*i+4];
        Wa[8*i] = tmp1+tmp2;
        Wa[8*i+4] = tmp1-tmp2;
        tmp1 = Wa[8*i+1];
        tmp2 = Wa[8*i+5];
        Wa[8*i+1] = tmp1+tmp2;
        Wa[8*i+5] = tmp1-tmp2;
        tmp1 = Wa[8*i+2];
        tmp2 = Wa[8*i+6];
        Wa[8*i+2] = tmp1+tmp2;
        Wa[8*i+6] = tmp1-tmp2;
        tmp1 = Wa[8*i+3];
        tmp2 = Wa[8*i+7];
        Wa[8*i+3] = tmp1+tmp2;
        Wa[8*i+7] = tmp1-tmp2;
        printf("%2d%2d%2d%2d%2d%2d%2d%2d",Wa[8*i],Wa[8*i+1],Wa[8*i+2],Wa[8*i+3],Wa[8*i+4],Wa[8*i+5],Wa[8*i+6],Wa[8*i+7]);
    }
    printf("\n");

    for(i=0;i<2;i++) {
        tmp1 = Wa[16*i];
        tmp2 = Wa[16*i+8];
        Wa[16*i] = tmp1+tmp2;
        Wa[16*i+8] = tmp1-tmp2;
        tmp1 = Wa[16*i+1];
        tmp2 = Wa[16*i+9];
        Wa[16*i+1] = tmp1+tmp2;
        Wa[16*i+9] = tmp1-tmp2;
        tmp1 = Wa[16*i+2];
        tmp2 = Wa[16*i+10];
        Wa[16*i+2] = tmp1+tmp2;
        Wa[16*i+10] = tmp1-tmp2;
        tmp1 = Wa[16*i+3];
        tmp2 = Wa[16*i+11];
        Wa[16*i+3] = tmp1+tmp2;
        Wa[16*i+11] = tmp1-tmp2;
        tmp1 = Wa[16*i+4];
        tmp2 = Wa[16*i+12];
        Wa[16*i+4] = tmp1+tmp2;
        Wa[16*i+12] = tmp1-tmp2;
        tmp1 = Wa[16*i+5];
        tmp2 = Wa[16*i+13];
        Wa[16*i+5] = tmp1+tmp2;
        Wa[16*i+13] = tmp1-tmp2;
        tmp1 = Wa[16*i+6];
        tmp2 = Wa[16*i+14];
        Wa[16*i+6] = tmp1+tmp2;
        Wa[16*i+14] = tmp1-tmp2;
        tmp1 = Wa[16*i+7];
        tmp2 = Wa[16*i+15];
        Wa[16*i+7] = tmp1+tmp2;
        Wa[16*i+15] = tmp1-tmp2;
        for(j=0;j<16;j++)
            printf("%2d",Wa[16*i+j]);
    }
    printf("\n");

    for(i=0;i<16;i++) {
        tmp1 = Wa[i];
        tmp2 = Wa[i+16];
        Wa[i] = tmp1+tmp2;
        Wa[i+16] = tmp1-tmp2;
    }
    for(i=0;i<32;i++)
        printf("%2d",Wa[i]);
    printf("\n");

    float WA[32];
    float max = 0;
    int position;

    for(i=0;i<32;i++)
        WA[i] = (float)Wa[i]/(float)32;
    for(i=0;i<32;i++) {
        WA[i] = (WA[i]+1)/2;
        if(WA[i]>max) {
            max = WA[i];
            position = i;
        }
        printf("%2d",(int)(100*WA[i]));
    }
    printf("\n");

    printf("\nmax probability = %.2f with number",max,position);

    int variables[5] = {0,0,0,0,0};

    j = 4;
    while(position>0) {
        if(position%2==1) {
            variables[j] = 1;
            position /=2;
        }
        else {
            variables[j] = 0;
            position /=2;
        }
        j--;
    }

    for(i=0;i<5;i++) {
        printf("%2d",variables[i]);
    }
    printf("\n");

    printf("The best affine approximation is: ");

    i = 0;
    while(variables[i]==0 && i<5)
        i++;
    printf("X%d",i+1);

    for(j=i+1;j<5;j++)
        printf(" + X%d",j+1);
    printf("\n");

    return 0;
}

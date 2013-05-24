/*****************************
    Quentin GOUCHET's CODE
*****************************/

#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define BIG 16777216
#define SMALL 1048576
#define N 0

FILE * output;
FILE * match;
FILE * keys;

using namespace std;

int Kr_begin[24];
int Kr_end[20];

int KR[5][32];

int S[] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};
int S_1[] = {14, 3, 4, 8, 1, 12 , 10, 15, 7, 13, 9, 6, 11, 2, 0, 5};

int P[] = {1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16};

int plain_text[4][16] = {{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0},
                        {1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0},
                        {0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
                        {0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0}};

int cipher_text[4][16] = {{0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1},
                        {1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
                        {0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0}};

int X[4][16];
int Y[4][16];

int storage() {
    output = fopen("output.txt","w");

    int tmp;
    int place;
    for(int i=SMALL;i>=0;i--) {
        tmp = i;
        place = 19;
        while(tmp>0) {
            Kr_end[place] = tmp%2;
            tmp /= 2;
            place--;
        }

        /*for(int f=0;f<20;f++)
            printf("%d",Kr_end[f]);
        printf("\n");*/

        for(int j=0;j<16;j++)
            KR[3][j] = Kr_end[0*4+j];
        for(int j=0;j<16;j++)
            KR[4][j] = Kr_end[1*4+j];

        int u[16];
        int v[16];
        int w[16];
        int a,b;

        for(int j=0;j<16;j++)
            w[j] = cipher_text[N][j];

        for(int j=0;j<16;j++)
            u[j] = (w[j] + KR[4][j])%2;

        for(int k=0;k<4;k++) {
            a = 0;
            for(int j=0;j<4;j++)
                a = a + (int)pow(2,4-(j+1))*u[j+4*(k+1)-4];

            b = S_1[a];

            for(int j=0;j<4;j++) {
                v[1-(j+1)+4*k+4-1] = b%2;
                b = (b-(b%2))/2;
            }
        }

        for(int j=0;j<16;j++)
            w[j] = (v[j] + KR[3][j])%2;

        for(int j=0;j<16;j++)
            X[N][j] = w[j];

        for(int j=0;j<16;j++)
            fprintf(output,"%d ",X[N][j]);
        fprintf(output,"\n");
    }
    fclose(output);
    return 0;
}

int main () {
    storage();

    printf("\n\nEND OF STORAGE\n\n");

    match = fopen("match.txt","w");
    output = fopen("output.txt","r");

    int text[16];
    int key[20];

    int size = 0;

    int test,tmp,place;

    for(int j=SMALL-1;j>=0;j--) { //966824
        for(int k=0;k<16;k++)
            fscanf(output,"%d",&text[k]);

        tmp = j;
        place = 19;
        while(tmp>0) {
            Kr_end[place] = tmp%2;
            tmp /= 2;
            place--;
        }

        for(int i=BIG-1;i>=0;i--) { //7892672
            tmp = i;
            place = 23;
            while(tmp>0 && place>=0) {
                Kr_begin[place] = tmp%2;
                tmp /= 2;
                place--;
            }

            /*for(int k=0;k<24;k++)
                printf("%d",Kr_begin[k]);*/

            for(int k=0;k<16;k++)
                KR[0][k] = Kr_begin[0*4+k];
            for(int k=0;k<16;k++)
                KR[1][k] = Kr_begin[1*4+k];
            for(int k=0;k<16;k++)
                KR[2][k] = Kr_begin[2*4+k];

            int w[16];
            int u[16];
            int v[16];
            int a,b;

            for(int i=0;i<16;i++)
                w[i] = plain_text[N][i];

            for(int r=0;r<3;r++) {
                for(int j=0;j<16;j++)
                    u[j] = (w[j] + KR[r][j])%2;

                for(int i=0;i<4;i++) {
                    a = 0;
                    for(int j=0;j<4;j++)
                        a = a + (int)pow(2,4-(j+1))*u[j+4*(i+1)-4];

                    b = S[a];

                    for(int j=0;j<4;j++) {
                        v[1-(j+1)+4*i+4-1] = b%2;
                        b = (b-(b%2))/2;
                    }
                }

                for(int j=0;j<16;j++)
                    w[j] = v[P[j]-1];
            }

            for(int j=0;j<16;j++)
                Y[N][j] = w[j];

            /*for(int k=0;k<16;k++)
                printf("%d",Y[N][k]);
            printf("\n");*/

            test = 1;
            for(int k=0;k<16;k++) {
                if(text[k]!=Y[N][k])
                    test = 0;
            }

            if(test) {
                test = 1;
                for(int k=0;k<12;k++) {
                    if(Kr_end[k]!=Kr_begin[k+12])
                        test = 0;
                }
                if(test) {
                    printf("\nMATCH FOUND!!!\n");
                    printf("%d %d\n",i,j);
                    for(int k=0;k<24;k++)
                        fprintf(match,"%d",Kr_begin[k]);
                    for(int k=12;k<20;k++)
                        fprintf(match,"%d",Kr_end[k]);
                    fprintf(match,"\n\n");
                }
            }
        }
    }

    fclose(match);
    fclose(output);

    printf("\n\nEND OF COMPUTATION\n\n");
    return 0;
}

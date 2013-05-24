/*****************************
    Quentin GOUCHET's CODE
*****************************/

#include <stdio.h>
#include <math.h>

using namespace std;

int KR[5][16];

int KEY[] = {0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0};

int S[] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};
int S_1[] = {14, 3, 4, 8, 1, 12 , 10, 15, 7, 13, 9, 6, 11, 2, 0, 5};

int P[] = {1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16};

int X[4][16] = {{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0},
                {1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0},
                {0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
                {0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0}};

int Y[4][16];

int round_keys () {
    for(int r=0;r<5;r++) {
        for(int j=0;j<16;j++)
            KR[r][j] = KEY[4*r+j];
    }
    return 0;
}

int encryption () {
    for(int n=0;n<4;n++) {
        int w[16];
        int u[16];
        int v[16];
        int a,b;

        for(int i=0;i<16;i++) {
            Y[n][i] = X[n][i];
            w[i] = X[n][i];
        }

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

        /*for(int o=0;o<16;o++)
            printf("%d",w[o]);
        printf("\n");*/

        for(int j=0;j<16;j++)
            u[j] = (w[j] + KR[3][j])%2;

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
            Y[n][j] = (v[j] + KR[4][j])%2;
    }
    return 0;
}

int main()
{
    round_keys();
    encryption();

    for(int i=0;i<4;i++) {
        printf("%d\n",i+1);
        for(int j=0;j<16;j++)
            printf("%d ",X[i][j]);
        printf("\n");
        for(int j=0;j<16;j++)
            printf("%d ",Y[i][j]);
        printf("\n\n");
    }
    return 0;
}

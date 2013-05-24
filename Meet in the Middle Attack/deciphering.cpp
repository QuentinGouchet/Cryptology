/*****************************
    Quentin GOUCHET's CODE
*****************************/

//THIS CODE IS USED TO CHECK HOW TO DECIPHER

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

using namespace std;

int S[] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};
int S_1[] = {14, 3, 4, 8, 1, 12 , 10, 15, 7, 13, 9, 6, 11, 2, 0, 5};

int test[16] = {0,1,1,0,0,1,0,0,0,0,0,0,0,0,1};
int v[16];

int main () {
    int a,b;

    printf("\n");

    printf("TEST VECTOR:\n\n");
    for(int j=0;j<16;j++)
        printf("%d ",test[j]);
    printf("\n\n");

    for(int i=0;i<4;i++) {
            a = 0;
            for(int j=0;j<4;j++)
                a = a + (int)pow(2,4-(j+1))*test[j+4*(i+1)-4];

            b = S[a];

            for(int j=0;j<4;j++) {
                v[1-(j+1)+4*i+4-1] = b%2;
                b = (b-(b%2))/2;
            }
        }

    printf("TEST VECTOR PERMUTED WITH S:\n\n");
    for(int j=0;j<16;j++)
        printf("%d ",v[j]);
    printf("\n\n");

    for(int i=0;i<4;i++) {
            a = 0;
            for(int j=0;j<4;j++)
                a = a + (int)pow(2,4-(j+1))*v[j+4*(i+1)-4];

            b = S_1[a];

            for(int j=0;j<4;j++) {
                v[1-(j+1)+4*i+4-1] = b%2;
                b = (b-(b%2))/2;
            }
        }

    printf("TEST VECTOR PERMUTED WITH S-1:\n\n");
    for(int j=0;j<16;j++)
        printf("%d ",v[j]);

    printf("\n");

    return 0;
}

/*****************************
    Quentin GOUCHET's CODE
*****************************/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define BIG 16777216
#define SMALL 1048576

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

vector< pair<string,string> > store[4];
vector<string> key_candidates[4];

int storage(int n) {
    int tmp;
    int place;
    for(int i=SMALL-1;i>=0;i--) {
        tmp = i;
        place = 19;
        while(place>=0) {
            Kr_end[place] = tmp%2;
            tmp /= 2;
            place--;
        }

        for(int j=0;j<16;j++)
            KR[3][j] = Kr_end[0*4+j];
        for(int j=0;j<16;j++)
            KR[4][j] = Kr_end[1*4+j];

        int u[16];
        int v[16];
        int w[16];
        int a,b;

        for(int j=0;j<16;j++)
            w[j] = cipher_text[n][j];

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

        string str = "0000000000000000";

        for(int j=0;j<16;j++) {
            X[n][j] = w[j];
            str[j] = X[n][j]+48;
        }

        string K = "00000000000000000000";

        for(int j=0;j<20;j++)
            K[j] = Kr_end[j]+48;

       store[n].PB(MP(str,K));
    }
    sort(store[n].begin(),store[n].end());
    return 0;
}

bool myCompare (pair<string,string> a,pair<string,string> b) {
    return a.first<b.first;
}

bool myCompare2 (string a,string b) {
    return a<b;
}

int main () {
    int test;
    for(int n=0;n<4;n++) {
        storage(n);

        int tmp,place;

        for(int i=BIG-1;i>=0;i--) { //7892672
            tmp = i;
            place = 23;
            while(place>=0) {
                Kr_begin[place] = tmp%2;
                tmp /= 2;
                place--;
            }

            /*if(i==7892672) {
                for(int k=0;k<24;k++)
                    printf("%d",Kr_begin[k]);
                printf("\n");
            }*/

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

            for(int k=0;k<16;k++)
                w[k] = plain_text[n][k];

            for(int r=0;r<3;r++) {
                for(int j=0;j<16;j++)
                    u[j] = (w[j] + KR[r][j])%2;

                for(int k=0;k<4;k++) {
                    a = 0;
                    for(int j=0;j<4;j++)
                        a = a + (int)pow(2,4-(j+1))*u[j+4*(k+1)-4];

                    b = S[a];

                    for(int j=0;j<4;j++) {
                        v[1-(j+1)+4*k+4-1] = b%2;
                        b = (b-(b%2))/2;
                    }
                }

                for(int j=0;j<16;j++)
                    w[j] = v[P[j]-1];
            }

            for(int j=0;j<16;j++)
                Y[n][j] = w[j];

            string str = "0000000000000000";

            for(int j=0;j<16;j++)
                str[j] = Y[n][j]+48;

             /*if(i==7892672)
                    cout << str << endl;*/

            pair<vector< pair<string,string> >::iterator, vector< pair<string,string> >::iterator> range = equal_range(store[n].begin(),store[n].end(),MP(str,""),myCompare);
            vector< pair<string,string> >::iterator current = range.first;

            while (current != range.second) {
                string K = (*current).second;

                test = 1;
                for(int j=0;j<12;j++) {
                    if(Kr_begin[j+12]!=K[j]-48)
                        test = 0;
                }

                if(test){
                    //printf("\n\nMATCH !!!");

                    string KEY = "00000000000000000000000000000000";

                    for(int j=0;j<24;j++)
                        KEY[j] = Kr_begin[j]+48;

                    for(int j=24;j<32;j++)
                        KEY[j] = K[j-12];

                    key_candidates[n].PB(KEY);
                }
                current++;
            }
        }
        sort(key_candidates[n].begin(),key_candidates[n].end());
        printf("\n\nEND OF STORAGE FOR PAIR %d\n\n",n);
    }

    string K = "01111000011011101100000010101000";

    for(int n=0;n<4;n++) {
        bool it = binary_search(key_candidates[n].begin(),key_candidates[n].end(),K,myCompare2);
        cout << it << endl;
    }

    //printf("%d\n",key_candidates[0].size());

    printf("KEY CANDIDATES:\n");

    for(int i=0;i<key_candidates[0].size();i++) {
        string st = key_candidates[0][i];
        test = 1;

        for(int n=1;n<4;n++) {
            bool it = binary_search(key_candidates[n].begin(),key_candidates[n].end(),st,myCompare2);

            if(it==false)
                test = 0;
        }
        if(test)
            cout << st << endl;
    }

    printf("\n\nEND OF COMPUTATION\n\n");
    return 0;
}

#include<stdio.h>
#include<string.h>

char * alphabet[26] = {"11000","10011","01110","10010","10000","10110","01011","00101","01100","11010","11110","01001",
"00111","00110","00011","01101","11101","01010","10100","00001","11100","01111","11001","10111","10101","10001"};

char * extendedalphabet[32] = {"11000","10011","01110","10010","10000","10110","01011","00101","01100","11010","11110",
"01001","00111","00110","00011","01101","11101","01010","10100","00001","11100","01111","11001","10111","10101","10001",
"00010","01000","11111","11011","00100","00000"};

char * controlbits (int input[5],char * output) {
    if((input[0]==0 && input[1]==0 && input[2]==0 && input[3]==0 && input[4]==1) ||  (input[0]==1 && input[1]==1 && input[2]==1 && input[3]==1 && input[4]==0)) {
        if(strcmp(output,"00001")==0 || strcmp(output,"11110")==0)
            return "11***";
        else if(strcmp(output,"00010")==0 || strcmp(output,"11101")==0)
            return "101**";
        else if(strcmp(output,"00100")==0 || strcmp(output,"11011")==0)
            return "1001*";
        else
            return "NOMATCH";
    }
    else if((input[0]==0 && input[1]==0 && input[2]==0 && input[3]==1 && input[4]==0) || (input[0]==1 && input[1]==1 && input[2]==1 && input[3]==0 && input[4]==1)) {
        if(strcmp(output,"00001")==0 || strcmp(output,"11110")==0)
            return "*0***";
        else if(strcmp(output,"00010")==0 || strcmp(output,"11101")==0)
            return "*11**";
        else if(strcmp(output,"00100")==0 || strcmp(output,"11011")==0)
            return "*101*";
        else if(strcmp(output,"01000")==0 || strcmp(output,"10111")==0)
            return "*1001";
        else if(strcmp(output,"10000")==0 || strcmp(output,"01111")==0)
            return "*1000";
        else
            return "NOMATCH";
    }
    else if((input[0]==0 && input[1]==0 && input[2]==1 && input[3]==0 && input[4]==0) ||  (input[0]==1 && input[1]==1 && input[2]==0 && input[3]==1 && input[4]==1)) {
        if(strcmp(output,"00010")==0 || strcmp(output,"11101")==0)
            return "**0**";
        else if(strcmp(output,"00100")==0 || strcmp(output,"11011")==0)
            return "**11*";
        else if(strcmp(output,"01000")==0 || strcmp(output,"10111")==0)
            return "**101";
        else if(strcmp(output,"10000")==0 || strcmp(output,"01111")==0)
            return "**100";
        else
            return "NOMATCH";
    }
    else if((input[0]==0 && input[1]==1 && input[2]==0 && input[3]==0 && input[4]==0) ||  (input[0]==1 && input[1]==0 && input[2]==1 && input[3]==1 && input[4]==1)) {
        if(strcmp(output,"00100")==0 || strcmp(output,"11011")==0)
            return "***0*";
        else if(strcmp(output,"01000")==0 || strcmp(output,"10111")==0)
            return "***11";
        else if(strcmp(output,"10000")==0 || strcmp(output,"01111")==0)
            return "***10";
        else
            return "NOMATCH";
    }
    else if((input[0]==1 && input[1]==0 && input[2]==0 && input[3]==0 && input[4]==0) ||  (input[0]==0 && input[1]==1 && input[2]==1 && input[3]==1 && input[4]==1)) {
        if(strcmp(output,"00001")==0 || strcmp(output,"11110")==0)
            return "01***";
        else if(strcmp(output,"00010")==0 || strcmp(output,"11101")==0)
            return "001**";
        else if(strcmp(output,"00100")==0 || strcmp(output,"11011")==0)
            return "0001*";
        else
            return "NOMATCH";
    }
    else
        return "NOMATCH";
}

int ciphertext[1300-26] = {4, 3, 1, 2, 27, 5, 30, 14, 4, 18, 32, 31, 31, 6, 20, 7, 7, 11, 17, 16, 13, 21, 18, 7, 21, 25, 19,
18, 21, 24, 17, 32, 3, 18, 21, 6, 18, 31, 31, 18, 24, 11, 22, 22, 3, 7, 28, 19, 7, 19, 7, 1, 24, 6, 3,
20, 14, 32, 32, 32, 5, 30, 32, 23, 18, 20, 9, 30, 32, 5, 15, 22, 29, 11, 11, 13, 3, 3, 10, 22, 27, 5,
18, 20, 9, 31, 24, 17, 8, 8, 21, 31, 15, 25, 5, 10, 27, 22, 20, 3, 27, 3, 14, 13, 19, 11, 28, 19, 2,
19, 20, 1, 6, 21, 10, 1, 7, 10, 4, 20, 19, 27, 14, 19, 12, 24, 22, 4, 17, 3, 31, 20, 20, 10, 6, 20,
22, 25, 27, 6, 4, 28, 6, 25, 27, 11, 15, 29, 3, 5, 19, 31, 6, 23, 15, 29, 9, 5, 26, 21, 16, 31, 9, 26,
32, 17, 23, 13, 28, 15, 3, 18, 24, 16, 2, 25, 14, 8, 13, 18, 25, 22, 5, 17, 12, 17, 27, 14, 19, 19,
2, 4, 28, 25, 5, 5, 8, 17, 31, 27, 8, 23, 26, 23, 17, 20, 28, 3, 30, 27, 25, 12, 11, 11, 3, 14, 10,
29, 22, 5, 3, 25, 19, 23, 28, 25, 10, 14, 21, 23, 13, 31, 11, 31, 7, 2, 31, 31, 12, 27, 11, 22, 3, 1,
28, 15, 23, 15, 1, 12, 32, 27, 9, 31, 31, 11, 31, 15, 24, 16, 5, 32, 27, 9, 8, 32, 11, 32, 15, 31,
31, 17, 23, 25, 9, 13, 16, 26, 31, 18, 26, 27, 7, 25, 14, 22, 20, 14, 7, 2, 7, 14, 23, 16, 6, 16, 3,
10, 20, 14, 26, 24, 4, 16, 26, 9, 15, 20, 8, 26, 20, 17, 26, 22, 1, 16, 18, 27, 26, 4, 18, 7, 9, 30,
19, 16, 27, 21, 3, 32, 27, 19, 17, 17, 12, 17, 2, 26, 4, 31, 5, 19, 16, 17, 6, 31, 17, 1, 13, 26, 23,
1, 14, 15, 20, 11, 12, 24, 27, 29, 9, 10, 4, 19, 12, 8, 12, 19, 24, 26, 22, 28, 30, 18, 5, 6, 11, 1,
23, 3, 5, 27, 19, 14, 9, 10, 12, 4, 7, 15, 2, 32, 9, 5, 15, 12, 22, 15, 19, 13, 19, 31, 29, 19, 9, 8,
4, 21, 29, 32, 13, 19, 14, 32, 21, 25, 10, 31, 31, 24, 26, 32, 6, 4, 27, 24, 1, 13, 9, 6, 2, 21, 21,
22, 3, 13, 9, 14, 14, 28, 27, 23, 15, 6, 21, 1, 16, 3, 25, 9, 12, 18, 6, 29, 4, 20, 14, 22, 6, 22, 9,
15, 17, 12, 12, 21, 4, 25, 11, 11, 9, 13, 4, 30, 9, 22, 2, 30, 14, 21, 29, 28, 32, 29, 25, 30, 28,
21, 10, 9, 27, 20, 28, 15, 12, 22, 7, 9, 22, 5, 29, 12, 18, 24, 26, 19, 16, 11, 16, 8, 22, 23, 13,
27, 29, 16, 30, 25, 11, 32, 13, 14, 24, 15, 16, 19, 24, 22, 28, 6, 14, 14, 21, 20, 16, 16, 12, 2,
20, 19, 11, 20, 22, 20, 28, 23, 7, 32, 2, 11, 30, 19, 23, 30, 11, 12, 22, 28, 26, 31, 26, 21, 9, 21,
23, 21, 16, 20, 15, 18, 20, 3, 6, 24, 17, 24, 9, 32, 32, 26, 3, 9, 26, 17, 7, 9, 1, 7, 12, 4, 32, 9,
24, 12, 24, 16, 8, 16, 12, 27, 6, 18, 29, 6, 28, 5, 6, 31, 17, 14, 6, 18, 9, 29, 8, 29, 18, 29, 1, 22,
20, 28, 27, 12, 3, 10, 4, 26, 1, 17, 10, 23, 21, 16, 10, 6, 8, 26, 2, 13, 12, 21, 28, 19, 25, 17, 27,
21, 21, 11, 4, 20, 5, 7, 9, 26, 12, 14, 20, 27, 3, 18, 25, 21, 12, 11, 25, 11, 3, 14, 24, 4, 15, 9, 1,
3, 19, 28, 20, 24, 5, 1, 30, 1, 25, 30, 2, 4, 5, 1, 24, 26, 16, 24, 18, 29, 11, 31, 1, 15, 13, 23, 17,
10, 15, 23, 18, 6, 27, 1, 9, 14, 6, 7, 26, 11, 4, 28, 31, 5, 8, 4, 23, 4, 20, 5, 27, 26, 29, 8, 18, 6,
25, 22, 31, 31, 17, 25, 6, 18, 21, 18, 25, 3, 22, 3, 18, 21, 20, 21, 32, 25, 13, 20, 4, 25, 10, 4,
15, 4, 11, 21, 25, 30, 17, 10, 4, 25, 21, 26, 27, 26, 6, 12, 15, 24, 2, 1, 8, 12, 32, 3, 19, 8, 18,
22, 29, 28, 7, 3, 20, 6, 25, 16, 14, 26, 24, 24, 7, 8, 30, 20, 19, 25, 32, 12, 19, 27, 27, 6, 26, 3,
2, 25, 21, 30, 21, 20, 26, 9, 3, 23, 23, 20, 28, 2, 10, 25, 10, 9, 8, 24, 18, 16, 23, 17, 15, 12, 14,
13, 10, 22, 4, 22, 18, 12, 19, 24, 3, 6, 5, 17, 22, 4, 10, 21, 31, 3, 21, 15, 27, 28, 29, 12, 27, 15,
21, 21, 25, 14, 21, 32, 18, 4, 32, 13, 15, 23, 23, 6, 3, 27, 31, 14, 1, 22, 31, 5, 30, 15, 28, 17,
15, 24, 19, 19, 22, 18, 29, 21, 26, 7, 13, 3, 29, 13, 19, 16, 1, 10, 3, 10, 2, 8, 6, 9, 2, 14, 13, 31,
24, 12, 16, 23, 4, 13, 11, 29, 5, 14, 20, 12, 11, 8, 9, 29, 3, 7, 1, 29, 24, 20, 17, 13, 5, 26, 11,
16, 22, 12, 6, 10, 7, 10, 25, 29, 3, 9, 24, 31, 28, 22, 13, 30, 26, 26, 27, 8, 5, 27, 8, 3, 6, 10, 12,
6, 6, 10, 3, 9, 12, 30, 26, 23, 10, 4, 24, 7, 10, 28, 9, 19, 21, 3, 32, 7, 25, 24, 29, 5, 30, 28, 2,
10, 13, 10, 8, 25, 31, 4, 2, 20, 25, 16, 7, 24, 15, 15, 25, 3, 18, 30, 30, 11, 1, 27, 20, 4, 2, 14,
13, 6, 31, 20, 4, 22, 20, 22, 3, 16, 4, 9, 6, 6, 7, 24, 10, 16, 4, 9, 3, 21, 26, 30, 10, 1, 8, 1, 7, 32,
25, 27, 9, 4, 28, 26, 26, 8, 25, 13, 16, 15, 23, 1, 20, 18, 23, 15, 32, 16, 5, 31, 17, 2, 8, 29, 32,
13, 21, 5, 31, 15, 17, 6, 29, 21, 18, 3, 15, 12, 1, 3, 7, 22, 31, 9, 12, 22, 4, 21, 1, 26, 19, 5, 23,
18, 28, 11, 15, 10, 31, 28, 30, 23, 25, 32, 23, 10, 12, 14, 23, 9, 5, 10, 8, 2, 25, 30, 15, 22, 28,
27, 8, 27, 28, 20, 32, 3, 2, 32, 17, 13, 1, 3, 4, 6, 21, 12, 29, 28, 26, 15, 8, 7, 22, 30, 13, 11, 30,
18, 21, 32, 31, 7, 24, 10, 25, 8, 31, 31, 14, 16, 10, 17, 5, 22, 17, 7, 24, 13, 18, 18, 8, 28, 15,
21, 32, 8, 32, 11, 16, 14, 6, 30, 14, 28, 13, 20, 28, 15, 23, 11, 4, 13, 5, 19, 8, 28, 31, 1, 8, 11,
22, 23, 21, 7, 8, 31, 6, 32, 28, 21, 26, 22, 32, 16, 3, 29, 10, 4, 10, 7, 25, 11, 20, 4, 15, 2, 19,
14, 1, 2, 12, 23, 8, 4, 7, 28, 8, 10, 10, 14, 19, 17, 13, 17, 19, 12, 20, 1, 16, 20, 31, 3};

int R47[47];
int R53[53];
int R59[59];
int R61[61];
int R64[64];
int R65[65];
int R67[67];
int R69[69];
int R71[71];
int R73[73];

#define N 53

int hamingsweight (int input[5]) {
    int poids = 0;
    int i;
    for(i=0;i<5;i++) {
        if(input[i]==1)
            poids++;
    }
    return poids;
}

int weightoutput (char * output) {
    int poids = 0;
    int i;
    for(i=0;i<5;i++) {
        if(output[i]==49)
            poids++;
    }
    return poids;
}

int unknown (int input[5]) {
    int compte = 0;
    int i;
    for(i=0;i<5;i++) {
        if(input[i]!=0 && input[i]!=1)
            compte++;
    }
    return compte;
}

int inconnues (int input[5]) {
    int compte = 0;
    int i;
    for(i=0;i<5;i++) {
        if(input[i] != 1 && input[i] != 0)
            compte++;
    }
    return compte;
}

int main () {
    /************************
        FILL 5 FIRST WHEELS
    ************************/
    char * tmp;
    int i,j,position;
    int input[5];

    for(i=0;i<73;i++) {
        R47[i%47] = 2;
        R61[i%61] = 2;
        R73[i%73] = 2;
        R71[i%71] = 2;
        R65[i%65] = 2;
    }

    for(i=0;i<1300-26;i++) {
        if(ciphertext[i]==29) {
            tmp = alphabet[i%26];
            R47[i%47] = (tmp[0]-48)^1;
            R61[i%61] = (tmp[1]-48)^1;
            R73[i%73] = (tmp[2]-48)^1;
            R71[i%71] = (tmp[3]-48)^1;
            R65[i%65] = (tmp[4]-48)^1;
        }
        else if (ciphertext[i]==32) {
            tmp = alphabet[i%26];
            R47[i%47] = (tmp[0]-48)^0;
            R61[i%61] = (tmp[1]-48)^0;
            R73[i%73] = (tmp[2]-48)^0;
            R71[i%71] = (tmp[3]-48)^0;
            R65[i%65] = (tmp[4]-48)^0;
        }
    }

    for(i=0;i<1300-26;i++) {
        tmp = alphabet[i%26];
        if(R47[i%47]==0 || R47[i%47]==1) input[0] = R47[i%47]^(tmp[0]-48); else input[0] = 2;
        if(R61[i%61]==0 || R61[i%61]==1) input[1] = R61[i%61]^(tmp[1]-48); else input[1] = 2;
        if(R73[i%73]==0 || R73[i%73]==1) input[2] = R73[i%73]^(tmp[2]-48); else input[2] = 2;
        if(R71[i%71]==0 || R71[i%71]==1) input[3] = R71[i%71]^(tmp[3]-48); else input[3] = 2;
        if(R65[i%65]==0 || R65[i%65]==1) input[4] = R65[i%65]^(tmp[4]-48); else input[4] = 2;

        if(hamingsweight(input)==weightoutput(extendedalphabet[ciphertext[i]-1])) {
            if(input[0]==2) R47[i%47] = 0^(tmp[0]-48);
            if(input[1]==2) R61[i%61] = 0^(tmp[1]-48);
            if(input[2]==2) R73[i%73] = 0^(tmp[2]-48);
            if(input[3]==2) R71[i%71] = 0^(tmp[3]-48);
            if(input[4]==2) R65[i%65] = 0^(tmp[4]-48);
        }
        else if(unknown(input)==weightoutput(extendedalphabet[ciphertext[i]-1]) && hamingsweight(input)==0) {
            if(input[0]==2) R47[i%47] = 1^(tmp[0]-48);
            if(input[1]==2) R61[i%61] = 1^(tmp[1]-48);
            if(input[2]==2) R73[i%73] = 1^(tmp[2]-48);
            if(input[3]==2) R71[i%71] = 1^(tmp[3]-48);
            if(input[4]==2) R65[i%65] = 1^(tmp[4]-48);

        }
    }

    /*for(i=0;i<1300-26;i++) {
        tmp = alphabet[i%26];
        printf("%d%d%d%d%d\n",(tmp[0]-48)^R47[i%47],(tmp[1]-48)^R61[i%61],(tmp[2]-48)^R73[i%73],(tmp[3]-48)^R71[i%71],(tmp[4]-48)^R65[i%65]);
        printf("%s\n\n",extendedalphabet[ciphertext[i]-1]);
    }*/

    /***************************
        PRINT 5 FIRST WHEELS
    ***************************/

    printf("\nWHEEL 47\n");
    for(i=0;i<47;i++)
        printf("%d ",R47[i]);

    printf("\nWHEEL 61\n");
    for(i=0;i<61;i++)
        printf("%d ",R61[i]);

    printf("\nWHEEL 73\n");
    for(i=0;i<73;i++)
        printf("%d ",R73[i]);

    printf("\nWHEEL 71\n");
    for(i=0;i<71;i++)
        printf("%d ",R71[i]);

    printf("\nWHEEL 65\n");
    for(i=0;i<65;i++)
        printf("%d ",R65[i]);

    /**************************
        FIND LAST CABLINGS
    **************************/

    /*for(i=0;i<73;i++) {
        input[0] = (alphabet[i%26][0]-48)^R47[i%47];
        input[1] = (alphabet[i%26][1]-48)^R61[i%61];
        input[2] = (alphabet[i%26][2]-48)^R73[i%73];
        input[3] = (alphabet[i%26][3]-48)^R71[i%71];
        input[4] = (alphabet[i%26][4]-48)^R65[i%65];

        if((hamingsweight(input)==1 && weightoutput(extendedalphabet[ciphertext[i]-1])==1) || (hamingsweight(input)==4 && weightoutput(extendedalphabet[ciphertext[i]-1])==4)) {
            for(j=0;j<5;j++)
                    printf("%d",input[j]);
            printf(" / %s\n",extendedalphabet[ciphertext[i]-1]);

            position = i + N;
            while(position<(1300-26)) {
                input[0] = (alphabet[position%26][0]-48)^R47[position%47];
                input[1] = (alphabet[position%26][1]-48)^R61[position%61];
                input[2] = (alphabet[position%26][2]-48)^R73[position%73];
                input[3] = (alphabet[position%26][3]-48)^R71[position%71];
                input[4] = (alphabet[position%26][4]-48)^R65[position%65];

                if((hamingsweight(input)==1 && weightoutput(extendedalphabet[ciphertext[position]-1])==1) || (hamingsweight(input)==4 && weightoutput(extendedalphabet[ciphertext[position]-1])==4)) {
                    for(j=0;j<5;j++)
                            printf("%d",input[j]);
                    printf(" / %s\n",extendedalphabet[ciphertext[position]-1]);
                }
                position += N;
            }
            printf("\n");
        }
    }*/

    /***********************
        FILL LAST WHEELS
    ***********************/

    for(i=0;i<73;i++) {
        R69[i%69] = 2;
        R59[i%59] = 2;
        R64[i%64] = 2;
        R53[i%53] = 2;
        R67[i%67] = 2;
    }

    char * control;
    for(i=0;i<1300-26;i++) {
        input[0] = (alphabet[i%26][0]-48)^R47[i%47];
        input[1] = (alphabet[i%26][1]-48)^R61[i%61];
        input[2] = (alphabet[i%26][2]-48)^R73[i%73];
        input[3] = (alphabet[i%26][3]-48)^R71[i%71];
        input[4] = (alphabet[i%26][4]-48)^R65[i%65];

        if((hamingsweight(input)==1 && weightoutput(extendedalphabet[ciphertext[i]-1])==1) || (hamingsweight(input)==4 && weightoutput(extendedalphabet[ciphertext[i]-1])==4)) {
            char * output = extendedalphabet[ciphertext[i]-1];
            control = controlbits(input,output);
            /*for(j=0;j<5;j++)
                printf("%d",input[j]);
            printf(" %s\n%s\n",output,control);*/
            if(strcmp(control,"NOMATCH")!=0) {
                if(control[0]=='0' || control[0]=='1') R69[i%69] = control[0]-48;
                if(control[1]=='0' || control[1]=='1') R59[i%59] = control[1]-48;
                if(control[2]=='0' || control[2]=='1') R64[i%64] = control[2]-48;
                if(control[3]=='0' || control[3]=='1') R53[i%53] = control[3]-48;
                if(control[4]=='0' || control[4]=='1') R67[i%67] = control[4]-48;
            }
        }
    }

    for(i=0;i<1300-26;i++) {
        input[0] = (alphabet[i%26][0]-48)^R47[i%47];
        input[1] = (alphabet[i%26][1]-48)^R61[i%61];
        input[2] = (alphabet[i%26][2]-48)^R73[i%73];
        input[3] = (alphabet[i%26][3]-48)^R71[i%71];
        input[4] = (alphabet[i%26][4]-48)^R65[i%65];

        char * output = extendedalphabet[ciphertext[i]-1];

        if((input[0]==1 && input[1]==0 && input[2]==1 && input[3]==0 && input[4]==0) && strcmp(output,"10100")==0) {
            R69[i%69] = 1;
            R64[i%64] = 1;
            R53[i%53] = 1;
            R67[i%67] = 1;
        }
        else if((input[0]==1 && input[1]==1 && input[2]==0 && input[3]==0 && input[4]==0) && strcmp(output,"11000")==0) {
            R69[i%69] = 1;
            R53[i%53] = 1;
        }
        else if((input[0]==1 && input[1]==0 && input[2]==1 && input[3]==0 && input[4]==1) && strcmp(output,"10101")==0) {
            R59[i%59] = 1;
            R64[i%64] = 1;
            R53[i%53] = 1;
            R67[i%67] = 1;
        }
        else if((input[0]==0 && input[1]==0 && input[2]==0 && input[3]==1 && input[4]==1) && strcmp(output,"00011")==0) {
            R69[i%69] = 1;
            R64[i%64] = 1;
        }
        else if((input[0]==0 && input[1]==0 && input[2]==1 && input[3]==1 && input[4]==1) && strcmp(output,"00111")==0) {
            R69[i%69] = 1;
            R53[i%53] = 1;
        }
        else if((input[0]==0 && input[1]==1 && input[2]==0 && input[3]==1 && input[4]==1) && strcmp(output,"01011")==0) {
            R69[i%69] = 1;
            R64[i%64] = 1;
            R53[i%53] = 1;
            R67[i%67] = 1;
        }
        else if((input[0]==0 && input[1]==1 && input[2]==0 && input[3]==0 && input[4]==1) && strcmp(output,"01001")==0) {
            R69[i%69] = 1;
            R59[i%59] = 1;
            R53[i%53] = 1;
            R67[i%67] = 1;
        }
        else if((input[0]==1 && input[1]==0 && input[2]==0 && input[3]==0 && input[4]==1) && strcmp(output,"10001")==0) {
            R59[i%59] = 1;
            R67[i%67] = 1;
        }
        else if((input[0]==1 && input[1]==0 && input[2]==0 && input[3]==1 && input[4]==1) && strcmp(output,"10011")==0) {
            R64[i%64] = 1;
            R67[i%67] = 1;
        }
        else if((input[0]==1 && input[1]==0 && input[2]==0 && input[3]==1 && input[4]==0) && strcmp(output,"10010")==0) {
            R69[i%69] = 1;
            R59[i%59] = 1;
            R64[i%64] = 1;
            R67[i%67] = 1;
        }
        else if((input[0]==0 && input[1]==1 && input[2]==0 && input[3]==1 && input[4]==0) && strcmp(output,"01010")==0) {
            R59[i%59] = 1;
            R64[i%64] = 1;
            R53[i%53] = 1;
            R67[i%67] = 1;
         }
         else if((input[0]==0 && input[1]==0 && input[2]==1 && input[3]==1 && input[4]==0) && strcmp(output,"00110")==0) {
            R59[i%59] = 1;
            R53[i%53] = 1;
         }
         else if((input[0]==0 && input[1]==0 && input[2]==1 && input[3]==0 && input[4]==1) && strcmp(output,"00101")==0) {
            R69[i%69] = 1;
            R59[i%59] = 1;
            R64[i%64] = 1;
            R53[i%53] = 1;
         }
         else if((input[0]==0 && input[1]==1 && input[2]==1 && input[3]==1 && input[4]==0) && strcmp(output,"00111")==0) {
            R59[i%59] = 0;
            R64[i%64] = 0;
            R53[i%53] = 0;
         }
         else if((input[0]==1 && input[1]==1 && input[2]==1 && input[3]==0 && input[4]==0) && strcmp(output,"00111")==0) {
            R69[i%69] = 0;
            R59[i%59] = 1;
            R64[i%64] = 0;
            R53[i%53] = 0;
         }
         else if((input[0]==1 && input[1]==1 && input[2]==1 && input[3]==0 && input[4]==0) && strcmp(output,"10011")==0) {
            R69[i%69] = 0;
            R59[i%59] = 1;
            R64[i%64] = 0;
            R53[i%53] = 1;
            R67[i%67] = 0;
         }
         else if((input[0]==1 && input[1]==1 && input[2]==0 && input[3]==1 && input[4]==0) && strcmp(output,"10011")==0) {
            R69[i%69] = 0;
            R64[i%64] = 1;
            R53[i%53] = 1;
            R67[i%67] = 0;
         }
    }

    R69[3] = 1;
    R69[4] = 0;
    R69[5] = 1;
    R69[15] = 1;
    R69[16] = 1;
    R69[17] = 1;
    R69[21] = 1;
    R69[22] = 0;
    R69[23] = 0;
    R69[27] = 0;
    R69[32] = 0;
    R69[39] = 0;
    R69[40] = 1;
    R69[48] = 0;
    R69[51] = 0;
    R69[52] = 0;
    R69[53] = 1;
    R69[58] = 0;
    R69[62] = 0;
    R69[66] = 1;

    R59[53] = 0;
    R59[54] = 1;

    R64[11] = 0;
    R64[20] = 0;
    R64[21] = 0;
    R64[24] = 0;
    R64[52] = 0;

    R53[10] = 0;
    R53[16] = 0;
    R53[31] = 0;
    R53[48] = 0;

    R67[4] = 1;
    R67[10] = 1;
    R67[15] = 0;
    R67[16] = 0;
    R67[19] = 0;
    R67[28] = 0;
    R67[36] = 0;
    R67[38] = 0;
    R67[40] = 0;
    R67[41] = 1;
    R67[50] = 0;
    R67[52] = 1;
    R67[53] = 0;
    R67[54] = 0;
    R67[56] = 0;
    R67[62] = 1;
    R67[64] = 0;
    R67[65] = 1;
    R67[66] = 0;

    /*********************
        PRINT LAST WHEELS
    *********************/

    printf("\nWHEEL 69\n");
    for(i=0;i<69;i++)
        printf("%d ",R69[i]);

    printf("\nWHEEL 59\n");
    for(i=0;i<59;i++)
        printf("%d ",R59[i]);

    printf("\nWHEEL 64\n");
    for(i=0;i<64;i++)
        printf("%d ",R64[i]);

    printf("\nWHEEL 53\n");
    for(i=0;i<53;i++)
        printf("%d ",R53[i]);

    printf("\nWHEEL 67\n");
    for(i=0;i<67;i++)
        printf("%d ",R67[i]);

    /***********************************
        PRINT BOTH OUTPUTS TO COMPARE
    ***********************************/

    int s;
    int test = 1;
    for(i=0;i<1300-26;i++) {
        input[0] = (alphabet[i%26][0]-48)^R47[i%47];
        input[1] = (alphabet[i%26][1]-48)^R61[i%61];
        input[2] = (alphabet[i%26][2]-48)^R73[i%73];
        input[3] = (alphabet[i%26][3]-48)^R71[i%71];
        input[4] = (alphabet[i%26][4]-48)^R65[i%65];

        int control[5] = {R69[i%69],R59[i%59],R64[i%64],R53[i%53],R67[i%67]};

        //if(inconnues(control)==0) {
            if(R69[i%69]==0) {s = input[4]; input[4] = input[0]; input[0] = s;}
            if(R59[i%59]==0) {s = input[3]; input[3] = input[4]; input[4] = s;}
            if(R64[i%64]==0) {s = input[2]; input[2] = input[3]; input[3] = s;}
            if(R53[i%53]==0) {s = input[1]; input[1] = input[2]; input[2] = s;}
            if(R67[i%67]==0) {s = input[0]; input[0] = input[1]; input[1] = s;}

            char * output = extendedalphabet[ciphertext[i]-1];
            //printf("%d  ",i);
            for(j=0;j<5;j++) {
                //printf("%d",input[j]);
                if(input[j]!=output[j]-48)
                    test = 0;
            }
            //printf("    %s  %d\n\n",output,test);
        //}
    }

    printf("\n\n\nIS EVERYTHING CORRECT ?\n\n");
    if(test)
        printf("YES, END OF WORK !! (ALMOST)\n\n");
    else
        printf("NO...");

    printf("LET'S CIPHER THE ALPHABET !!\n\n");

    /*****************************
        PRINT LAST ALPHABET
    *****************************/

    int depart = 1300-26+1;
    for(i=depart;i<=1300;i++) {
        input[0] = (alphabet[i%26][0]-48)^R47[i%47];
        input[1] = (alphabet[i%26][1]-48)^R61[i%61];
        input[2] = (alphabet[i%26][2]-48)^R73[i%73];
        input[3] = (alphabet[i%26][3]-48)^R71[i%71];
        input[4] = (alphabet[i%26][4]-48)^R65[i%65];

        int control[5] = {R69[i%69],R59[i%59],R64[i%64],R53[i%53],R67[i%67]};

        if(R69[i%69]==0) {s = input[4]; input[4] = input[0]; input[0] = s;}
        if(R59[i%59]==0) {s = input[3]; input[3] = input[4]; input[4] = s;}
        if(R64[i%64]==0) {s = input[2]; input[2] = input[3]; input[3] = s;}
        if(R53[i%53]==0) {s = input[1]; input[1] = input[2]; input[2] = s;}
        if(R67[i%67]==0) {s = input[0]; input[0] = input[1]; input[1] = s;}

        for(j=0;j<5;j++)
            printf("%d",input[j]);
        printf("\n");
    }
    return 0;
}

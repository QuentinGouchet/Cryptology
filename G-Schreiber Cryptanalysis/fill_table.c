#include<stdio.h>
#include<string.h>

char * ordre[32] = {"00000","00001","00010","00011","00100","00101","00110","00111","01000","01001","01010","01011","01100","01101","01110",
"01111","10000","10001","10010","10011","10100","10101","10110","10111","11000","11001","11010","11011","11100","11101","11110","11111"};

int filltable (char input[5],char output[5]) {
    char tmp[5];
    char swap;
    int j;
    for(j=0;j<5;j++) {
        printf("%c",input[j]);
    }
    printf("  ");
    for(j=0;j<5;j++) {
        printf("%c",output[j]);
    }
    printf(" ////\n");
    int i,test;
    for(i=0;i<32;i++) {
        for(j=0;j<5;j++)
            tmp[j] = input[j];
        if(ordre[i][0] == '0') {swap = tmp[0]; tmp[0] = tmp[4]; tmp[4] = swap;}
        if(ordre[i][1] == '0') {swap = tmp[4]; tmp[4] = tmp[3]; tmp[3] = swap;}
        if(ordre[i][2] == '0') {swap = tmp[3]; tmp[3] = tmp[2]; tmp[2] = swap;}
        if(ordre[i][3] == '0') {swap = tmp[2]; tmp[2] = tmp[1]; tmp[1] = swap;}
        if(ordre[i][4] == '0') {swap = tmp[1]; tmp[1] = tmp[0]; tmp[0] = swap;}

        test = 1;
        for(j=0;j<5;j++) {
           if(tmp[j]!=output[j])
               test = 0;
        }
        if(test)
        printf("%s\n\n",ordre[i]);
    }
    return 0;
}

int main () {
    char input[5] = {'1','0','0','0','0'};
    char output[5] = {'0','1','0','0','0'};
    filltable(input,output);
    return 0;
}

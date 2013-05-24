#include<stdio.h>
#include<stdlib.h>
#include<math.h>

FILE * output;

int x[100] = {1,0,1,1,1,0,1,0,0,1,1,0,1,1,0,0,1,0,0,1,0,1,1,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,
1,0,0,0,1,1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,1};

float p = 0.75;

int tab[3][100];

float puissance(float f,int n) {
    float rep = 1.0;
    while(n--)
        rep *= f;
    return rep;
}

int main () {
    output = fopen("output.txt","w");

    float s = p*p + (1-p)*(1-p);

    int i;
    for(i=0;i<100;i++) {
        tab[0][i] = i;
        tab[1][i] = 0;
        tab[2][i] = 0;
    }

    for(i=31;i<100;i++) {
        tab[1][i]++;
        tab[1][i-28]++;
        tab[1][i-31]++;
        if(x[i]^x[i-28]^x[i-31]==0) {
            tab[2][i]++;
            tab[2][i-28]++;
            tab[2][i-31]++;
        }
    }

    for(i=62;i<100;i++) {
        tab[1][i]++;
        tab[1][i-56]++;
        tab[1][i-62]++;
        if(x[i]^x[i-56]^x[i-62]==0) {
            tab[2][i]++;
            tab[2][i-56]++;
            tab[2][i-62]++;
        }
    }

    if(output!=NULL) {
        fprintf(output,"k   ");
        for(i=0;i<100;i++)
            fprintf(output,"%6d",tab[0][i]);
        fprintf(output,"\n");
        fprintf(output,"m(k)");
        for(i=0;i<100;i++)
            fprintf(output,"%6d",tab[1][i]);
        fprintf(output,"\n");
        fprintf(output,"h(k)");
        for(i=0;i<100;i++)
            fprintf(output,"%6d",tab[2][i]);
        fprintf(output,"\n");
    }
    else {
        printf("Erreur d'ouverture du fichier.\n");
    }

    fprintf(output,"p(k)  ");
    float min = 1,max = 0;
    float p_star = 1;
    int position_min,position_max,L1 = 0;
    for(i=0;i<100;i++) {
        float num = p * puissance(s,tab[2][i]) * puissance(1-s,tab[1][i]-tab[2][i]);
        float denum = p * puissance(s,tab[2][i]) * puissance(1-s,tab[1][i]-tab[2][i]) + (1-p) * puissance(1-s,tab[2][i]) * puissance(s,tab[1][i]-tab[2][i]);
        if(num/denum<min) {min = num/denum;position_min = i;}
        if(num/denum>max) {max = num/denum;position_max = i;}
        if(num/denum>=0.94) {
            if(p_star>num/denum) p_star = num/denum;
            L1++;
        }
        fprintf(output,"%.2f  ",num/denum);
    }

    printf("min = %f pos min = %d\n",min,position_min);
    printf("max = %f pos max = %d\n",max,position_max);
    printf("\n%d valeurs > %f\n",L1,p_star);
    float q_star = 1-p_star;
    printf("Average weight ~ %f\n",q_star*L1);

    fclose(output);

    return 0;
}

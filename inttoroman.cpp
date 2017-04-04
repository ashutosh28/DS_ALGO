#include "array.h"
#include<stdio.h>
#include<stdlib.h>
void appendstring(char *TH,char *HU,char *TE,char *ON, char *ROM);
int main(){
    int X;
    cin>>X;
    int N=X;
    int th,hu,te,on;
    th=hu=te=on=0;
    char** thousands;
    char** hundreds;
    char** tens;
    char** ones;
    thousands = (char**) malloc(5*sizeof(char*));
    hundreds = (char**) malloc(10*sizeof(char*));
    tens = (char**) malloc(10*sizeof(char*));
    ones = (char**) malloc(10*sizeof(char*));
    for(int i=0;i<5;++i) thousands[i] = (char*) malloc(4*sizeof(char));
    for(int j=0;j<10;++j) {
        hundreds[j] = (char*) malloc(4*sizeof(char));
        tens[j] = (char*) malloc(4*sizeof(char));
        ones[j] = (char*) malloc(4*sizeof(char));
    }
    thousands[0] = "";thousands[1]="M";thousands[2]="MM";thousands[3]="MMM";thousands[4]="MMMM";
    hundreds[0] = "";hundreds[1]="C";hundreds[2]="CC";hundreds[3]="CCC";hundreds[4]="CD";hundreds[5]="D";hundreds[6]="DC";hundreds[7]="DCC";hundreds[8]="DCCC";hundreds[9]="CM";
                        
    tens[0]="";tens[1]="X";tens[2]="XX";tens[3]="XXX";tens[4]="XL";tens[5]="L";tens[6]="LX";tens[7]="LXX";tens[8]="LXXX";tens[9]="XC";
    ones[0] = "";ones[1]="I";ones[2]="II";ones[3]="III";ones[4]="IV";ones[5]="V";ones[6]="VI";ones[7]="VII";ones[8]="VIII";ones[9]="IX";
    /*char thousands[] = {"","M","MM","MMM","MMMM"};
    char hundreds[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    char tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    char ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};*/
    if(N<=4000) {
        th = N/1000;
        N = N%1000;
        hu = N/100;
        N = N%100;
        te = N/10;
        N = N%10;
        on = N;
    }else{
        cout<<"INVALID INPUT";
    }
    //int rom = thousands[th] + hundreds[hu] + tens[t] + ones[on];
    char *ROMAN = (char*) malloc(16*sizeof(char));
    appendstring(thousands[th],hundreds[hu],tens[te],ones[on],ROMAN);
    cout<<"INTERGER "<<X<<" in ROMAN NUMBER form : "<<ROMAN<<endl;
    return 0;
}
void appendstring(char *TH,char *HU,char *TE,char *ON,char *ROM) {
    int i=0;
    while(*TH) {
        ROM[i++] = *TH;
        TH++;
    }
    while(*HU) {
        ROM[i++] = *HU;
        HU++;
    }
    while(*TE) {
        ROM[i++] = *TE;
        TE++;
    }
    while(*ON) {
        ROM[i++] = *ON;
        ON++;
    }
}




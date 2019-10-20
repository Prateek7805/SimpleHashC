#include<stdio.h>
#include<string.h>
void toBin(int c,int *bin);
int main(){
    int *toBinPoint;
    int i,j,noOfChars, binVal[50][8],hash[8];
    char plainText[50], hashPrint[9];
    //open an dread from file
    FILE *fpoint;
    fpoint=fopen("plainText.txt","r");
    fgets(plainText,50,fpoint);
    fclose(fpoint);
    //close file
    noOfChars=strlen(plainText);//number of characters

    for(i=0; i<noOfChars; i++){
        toBinPoint=binVal[i];
        toBin(plainText[i],toBinPoint);
    }

    for(j=0; j<8; j++){
            hash[j]=0;//initialize the hash
        for(i=0; i<noOfChars; i++)
            hash[j]=hash[j]^binVal[i][j];
       hashPrint[j]=(char)(hash[j]+48);
    }
    hashPrint[j]='\0';
    for(i=0; i<8; i++)
        printf("%c ",hashPrint[i]);

    fpoint=fopen("hash.txt","w+");
    fputs(hashPrint,fpoint);
    fclose(fpoint);
}
void toBin(int c, int *bin){
    int i,arr[8];

    for(int i=0; i<8; i++){
        arr[i]=c%2;
        c/=2;
    }
    for(int i=0; i<8; i++){
        *bin=arr[7-i];
        //printf("%d\n",arr[7-i]);
        bin++;
    }
}

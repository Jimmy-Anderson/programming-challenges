
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

// Function to convert Decimal Number(int dec) to binary string (char bin[]) of given size
void decimalToBinary(int dec,char bin[],int size)
{
    int i=1;
    while(dec>0 && i<=size)
    {
        bin[i]=(dec%2)+'0';//Converting decimal 0 or 1 to char '0'/char '1'
        dec=dec/2;
        i++;
    }
}
//Function to take given binary string and return integer
int binaryToDecimal(char bin[])
{
    int num=0,i=0;
    int size=strlen(bin);
    while(i<size)
    {
        num+=pow(2,i)*(bin[i]-'0');
        i++;
    }
    return num;
}
// Function to print binary string
void printBinary(char bin[],int size)
{
    int i=size;
    //printf("\n");
    for(;i>0;i--)
    {
        if(i%4==0)
            printf(" ");
        printf("%c",bin[i]);
    }
}
int main(int argc,char* argv[])
{
    char operation[4];//variable to store the type of operation d2b or b2d
    strcpy(operation,argv[1]);
    if(strcmp(operation,"-d2b")==0){

        char decimalSize[4];
        strcpy(decimalSize,argv[2]);

        char decimalNumber[6];
        strcpy(decimalNumber,argv[3]);

        int num;
        sscanf(decimalNumber, "%d", &num);
        

        if(strcmp(decimalSize,"-8")==0)
        {
            num=num%((int)pow(2,8));
            char bin[9];
            memset(bin,'0',sizeof(bin));
            bin[0]='\0';
            decimalToBinary(num,bin,8);
            printBinary(bin,8);
        }
        else if(strcmp(decimalSize,"-16")==0)
        {

            num=num%((int)pow(2,16));
            char bin[17];
            memset(bin,'0',sizeof(bin));
            bin[0]='\0';
            decimalToBinary(num,bin,16);
            printBinary(bin,16);
        }
        else
        {
            printf("\nInvalid size of decimal passed as argument\n");
        }
    }
    else if(strcmp(operation,"-b2d")==0){

        char decimalSize[4];
        strcpy(decimalSize,argv[2]);

        if(strcmp(decimalSize,"-8")==0)
        {
            char binaryNumber[8];
            strcpy(binaryNumber,argv[3]);
            if(strlen(binaryNumber)<=8){
                int dec=binaryToDecimal(binaryNumber);
                printf("%3d\n", dec);
            }
            else{
                printf("\nThe length of binary string is greater than 8 bits");
            }
        }
        else if(strcmp(decimalSize,"-16")==0)
        {
            char binaryNumber[16];
            strcpy(binaryNumber,argv[3]);

            if(strlen(binaryNumber)<=16){
                int dec=binaryToDecimal(binaryNumber);
                //printf("%d\n", dec);
                if(dec<1000)
                    printf("%3d\n", dec);
                else
                    printf("%2d,%03d\n",dec/1000,dec%1000);
            }
            else{
                printf("\nThe length of binary string is greater than 16 bits");
            }
        }
        else
        {
            printf("\nInvalid size of binary number passed as argument\n");
        }
    }
    else{
        printf("\nInvalid operation passed as argument\n");
    }
    //getchar();
    return 0;
}

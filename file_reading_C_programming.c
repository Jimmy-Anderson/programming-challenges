#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[100],size;

void getArray()
{
	FILE *myFile;
	printf("Enter the name of the file containing marks\n");
	char filename[100];
	scanf("%s",filename);
    myFile = fopen(filename, "r");
    printf("Enter the number of marks in the file\n");
    scanf("%d",&size);
	

    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }

    for (int i = 0; i < size; i++){
        fscanf(myFile, "%d \n", &arr[i] );
    }
    fclose(myFile) ;
}
double calculateMean(){
	int sum=0;
	double avg;
	for(int i=0;i<size;i++)
		sum+=arr[i];
	avg=sum/size;
	return avg;
}
double calculateSigma(double mean){
	double sigma=0.0;
	for(int i=0;i<size;i++){
		sigma+=((arr[i]-mean)*(arr[i]-mean));
	}
	sigma/=size;
	return sigma;
}
void printArray(){
	for(int i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
char assignGrade(int id,double mu,double sigma){
	double mark=(double)arr[id];
	if(mark<(mu-3.0/2*sigma))
		return 'F';
	else if( (mark>=(mu-3.0/2*sigma)) && (mark<(mu-1.0/2*sigma)))
		return 'D';
	else if( (mark>=(mu-1.0/2*sigma)) && (mark<(mu+1.0/2*sigma)))
		return 'C';
	else if( (mark>=(mu+1.0/2*sigma)) && (mark<(mu+3.0/2*sigma)))
		return 'B';
	if(mark>=(mu+3.0/2*sigma))
		return 'A';

}
int main(){
	getArray();
	printArray();
	double mu=calculateMean();
	double sigma = calculateSigma(mu);
	printf("Mean of %d marks = %.2f \nStandard deviation = %.2f\n",size,mu,sigma);
	printf("The grade corresponding to each mark is\n");
	printf("Marks\tGrade\n");
	for(int i=0;i<size;i++){
		printf("%4d\t%4c\n",arr[i],assignGrade(i,mu,sigma));
	}
}
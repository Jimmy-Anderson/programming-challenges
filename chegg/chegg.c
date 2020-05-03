#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define infile "lab4.dat"
#define numberOfRecords 2
#define outfile "lab4out.dat"

void getRecords()
{
	FILE *myFile;
    myFile = fopen(infile, "r");

    if (myFile == NULL){
        printf("Error Reading File %s\n",infile);
        exit (0);
    }

    FILE *myFile2;
    myFile2 = fopen(outfile, "w");
    if (myFile2 == NULL){
        printf("Error Reading File out.txt\n");
        exit (0);
    }

    fprintf(myFile2, "Name:XXXXXXX\n");
    fprintf(myFile2, "Lab4\n\n");
    int count=1;
    while(count<=numberOfRecords){
    	double radius,height;
        fscanf(myFile, "%lf %lf \n", &radius,&height);
        double area=M_PI*radius*radius;
        double volume=area *height;
        fprintf(myFile2,"Cylinder count = %d\n",count);
        fprintf(myFile2,"Radius = %.2lf\n",radius);
        fprintf(myFile2,"Height = %.2f\n",height);
		fprintf(myFile2,"The area of the top of the cylinder = %.2f\n",area);
		fprintf(myFile2,"The volume of the cylinder = %.2f\n\n",volume);
		count++;
    }
    fclose(myFile2);
    fclose(myFile) ;
}
int main(){
	getRecords();
}
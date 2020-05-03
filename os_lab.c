#include<stdio.h>


int main()
{
    int n,d;
    printf("Enter the number of children : ");
    scanf("%d",&n);
    printf("Enter the depth of the tree : ");
    scanf("%d",&d);
    d--;
    label:
	for(int i=0;i<n;i++)
	{
		if(fork()==0)
    {
        d--;
        printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
        if(d==0)
			   exit(0);
		    else
			     goto label;
    }
	}
	for(int i=0;i<n;i++)
		wait();

}

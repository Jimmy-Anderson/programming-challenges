struct qnode
{
	node* rear;
	node* front;
}
node* newnode(int data,int index)
{
	node* x=(node*)malloc(sizeof(node));
	x->data=data;
	x->index=index;
	x->next=NULL;
}
int empty(qnode* Q)
{
	if(Q->front==NULL)
		return 1;
	else
		return 0;
}
void enqueue(qnode* Q,int data,int index)
{
	node* x=newnode(data,index);
	if(Q->rear==NULL)
	{
		Q->front=x;
		Q->rear=x;
	}
	else
	{
		Q->rear->next=x;
		Q->rear=x;
		Q->rear->next=Q->front;
	}
}
void dequeue(qnode *Q)
{
	if(!empty(Q))
	{
		node* ptr=Q->front;
		if(!ptr->next)
		{
			Q->rear=ptr->next;
			Q->front=ptr->next;
		}
		free(ptr);
	}
}

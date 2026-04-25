#include<stdio.h>

struct list
{
    struct graph *add;      /// store the address of graaph node
    struct list *link;
}typedef list;


struct graph
{
    char info;
    int status;
    list *head;
    struct graph *next;
}typedef graph;


graph *stk[10],*que[10];
int top=-1,f=-1,r=-1;

push(graph *x)
{
    top++;
    stk[top]=x;
}

graph * pop()
{
    graph *t;
    t=stk[top];
    top--;
    return(t);
}

ins(graph *x)
{
    r++;
    que[r]=x;
    if(f==-1)
    {
        f=0;
    }
}

graph * del()
{
    graph *t;
    t=que[f];
    if(f==r)
    {
        f=r=-1;
    }
    else
    {
        f++;
    }
    return(t);
}

insert1(graph **h,char d)
{
    graph *t,*tr;
    t=malloc(sizeof(graph));
    t->info=d;
    t->status=0;
    t->head=NULL;
    t->next=NULL;

    if(*h==NULL)
    {
        *h=t;
        return;
    }
    tr=*h;
    while(tr->next!=NULL)
    {
        tr=tr->next;
    }
    tr->next=t;
}

disp(graph *h)
{

    graph *t;
    t=h;
    printf("\n\n\t");
    while(t!=NULL)
    {
        printf("%c  ",t->info);
        t=t->next;
    }
}


dispall(graph *h)
{
    int i;
    graph *t;
    list *z;

    t=h;
    while(t!=NULL)
    {
        printf("\n\n\t");
        printf("\n\t%c [%d]   ",t->info,t->status);
        z=t->head;
        while(z!=NULL)
        {
            printf("%c [%d]   ",z->add->info,z->add->status);
            z=z->link;
        }
        t=t->next;
    }
}



create(graph **h,char x,char y)
{
    graph *so,*ta;
    int i,f;
    f=0;

    so=*h;
    ta=*h;
    while(so!=NULL)
    {

        if(so->info==x)
        {
            f=1;
            break;
        }
        so=so->next;
    }
    if(f==0)
    {
        printf("\n\source node not found");
        getch();
        return;
    }

    f=0;
    ta=*h;
    while(ta!=NULL)
    {
        if(ta->info==y)
        {
            f=1;
            break;
        }
        ta=ta->next;
    }
    if(f==0)
    {
        printf("\n\ttarget node not found");
        getch();
        return;
    }

    list *in,*z;
    in=malloc(sizeof(list));
    in->add=ta;
    in->link=NULL;

    if(so->head==NULL)
    {
        so->head=in;
        return;
    }
        z=so->head;

    while(z->link!=NULL)
    {
        z=z->link;

    }
    z->link=in;
}

dfs(graph **h)
{
    graph *z;
    list *t;
    z=*h;
    push(z);
    z->status=1;

    printf("\n\t");
    while(top>=0)
    {
        z=pop();
        printf("%c ",z->info);
        z->status=2;
        t=z->head;
        while(t!=NULL)
        {
            if(t->add->status==0)
            {
                push(t->add);
                t->add->status=1;
            }
            t=t->link;
        }
    }

}

bfs(graph **h)
{
    graph *z;
    list *t;
    z=*h;
    ins(z);
    z->status=1;

    printf("\n\t");
    while(f!=-1)
    {
        z=del();
        printf("%c ",z->info);
        z->status=2;
        t=z->head;
        while(t!=NULL)
        {
            if(t->add->status==0)
            {
                ins(t->add);
                t->add->status=1;
            }
            t=t->link;
        }
    }
}

delnode(graph **h,char x)
{
    graph *p,*q,*r;
    list *a,*b;
    int f;
    p=*h;
    while(p!=NULL)
    {
        if(p->info==x)
        {
            f=1;
            break;
        }
        p=p->next;
    }

    if(f==0)
    {
        printf("\n\tnode to be deleted not exist");
        getch();
        return;
    }
    printf("\n\tnode found");

    q=*h;
    while(q!=NULL)
    {
        a=b=q->head;

        if(a->add==p)         // if node is head node
        {
            q->head=q->head->link;
            a->link=NULL;
            printf("\n\tnode found as head : %c",a->add->info);
            free(a);
        }
        else
        {
            while(b!=NULL)
            {
                a=b;
                //printf("%c ",b->add->info);
                b=b->link;
                if(b==NULL)
                {
                    break;
                }
                if(b->add==p)
                {
                    a->link=b->link;
                    b->link=NULL;
                    printf("\n\tnode found in link also : %c",b->add->info);
                    free(b);
                    break;
                }
            }
        }
        q=q->next;
    }
    printf("\n\tokay");
    p=q=r=*h;
    if((*h)->info==x)
    {
        (*h)=(*h)->next;
        q->next=NULL;
        free(q);
        return;
    }
    while(q!=NULL)
    {
        p=q;
        q=q->next;
        if(q==NULL)
        {
            break;
        }
        if(q->info==x)
        {
            p->next=q->next;
            q->next=NULL;
            free(q);
            break;
        }
    }



}








main()
{
	int ch,a,i,n=0;
	char x,y;
	graph *head=NULL,*z;
	head=NULL;
	while(1)
	{
		system("cls");
		printf("\n\t1. Inset Vertex\n\t2. Create Link\n\t3. Display Vertecies\n\t4. Display Graph\n\t5. DFS Traversal\n\t6. BFS Traversal\n\t7. Delete\n\t8. Exit\n\n\tEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
                printf("\n\tenter vertex name : ");
                x=getche();
                insert1(&head,x);
                break;

			case 2:
                printf("\n\tenter source node name : ");
                x=getche();
                printf("\n\tenter target node name : ");
                y=getche();
                create(&head,x,y);
                break;

			case 3:
			    disp(head);         /// Display all the vertices presented in graph
			    getch();
                break;

            case 4:
                dispall(head);      /// display all the vwrtices with their current status
                getch();
                break;

			case 5:
                z=head;
			    while(z!=NULL)
                {
                    z->status=0;
                    z=z->next;
                }
			    dfs(&head);
			    getch();
			    break;

            case 6:
                z=head;
			    while(z!=NULL)
                {
                    z->status=0;
                    z=z->next;
                }
                bfs(&head);
                getch();
                break;

            case 7:
                printf("\n\tenter node name to be deleted : ");
                x=getche();
                delnode(&head,x);
                break;

            case 8:
                exit(0);

			default:
			printf("\n\n\tInvalid Choice");
			getch();
			break;

        }
	}
}






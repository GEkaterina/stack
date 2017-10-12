#include <stdio.h>
#include <stdlib.h>
/* Stack structure */
    struct stack
    {
        int  s_size;
        int s_elem [1000];
    };

/* Initializing the stack */
void init(struct stack * stk)
{
    stk ->s_size=0;
}

/* Adding to the stack */
void push(struct stack * stk, int elem)
{
    if (stk->s_size < 1000)
    {

       stk->s_elem[stk->s_size]=elem;
        stk->s_size++;
    }
}

/* Remove an item from the stack and return its value */
int pop(struct stack * stk)
{
    int elem;
    if (stk->s_size>0)
    {
        elem=stk->s_elem[stk->s_size-1];
        stk->s_size--;
        return elem;
    }
    else
    {
        printf("Stack is empty!\n");
        return 0;
    }
}

/* Checking the stack for empty */
int isempty(struct stack * stk)
{
    if (stk->s_size==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int main (int argc, char *argv[])
{
   struct stack *stk;
    int n ,s, i;

    stk = (struct stack*)malloc(sizeof(struct stack));
      init(stk);

    printf("Enter the number of items in the stack <=1000: ");
    scanf("%d", &n);

            for (i=0;i<n;i++)
                {
                    printf("\nEnter item %d:  ", i+1);
                    scanf ("%d", &s);
                    push(stk,s);
                }
    printf("\nIn stack %d items. \n", stk->s_size);


    for (i=n;i>0;i--)
        {
            printf("\n%d\n", stk->s_elem[i-1]);



        }
    printf("\nTop item: %d\n", stk->s_elem[n-1]);


    do
        {
            printf("\nExtract item: %d, there are %d items left on the stack\n",pop(stk), stk->s_size-1);

        }
    while (isempty(stk)==0);

    free (stk);

    return 0;

}

typedef struct _STACK_NODE_T
{
    int data;
    struct _STACK_NODE_T *pNext;
} STACK_NODE, *PSTACK_NODE;

typedef struct _STACK_T
{
    PSTACK_NODE pHead;
    int size;
} STACK, *PSTACK;



PSTACK createStack()
{
    PSTACK pSt = (PSTACK)malloc(sizeof(STACK));
    if(pSt == NULL)
    {
        return NULL;
    }
    
    pSt->pHead = NULL;
    pSt->size = 0;

    return pSt;
}

void push(PSTACK pSt, int p)
{
    PSTACK_NODE pNode = (PSTACK_NODE)malloc(sizeof(STACK_NODE));
    if(pNode == NULL)
    {
        return ;
    }

    pNode->data = p;
    pNode->pNext = pSt->pHead;

    pSt->pHead = pNode;
    pSt->size++;
}

int size(PSTACK pSt)
{
    return pSt->size;
}

int top(PSTACK pSt)
{
    if(size(pSt) > 0)
    {
        return pSt->pHead->data;
    }

    return -1;
}

int pop(PSTACK pSt)
{
    if(size(pSt) > 0)
    {
        int ans = pSt->pHead->data;
        PSTACK_NODE pToFree = pSt->pHead;

        pSt->pHead = pSt->pHead->pNext;
        pSt->size--;

        free(pToFree);

        return ans;
    }

    return -1;
}

void destroyStack(PSTACK pSt)
{
    if(pSt != NULL)
    {
        while(size(pSt) > 0)
        {
            pop(pSt);
        }

        free(pSt);
    }
}

void prvCalc(PSTACK pSt, char *opStr)
{
    // pop 2 numbers
    int secondOp = pop(pSt); 
    int firstOp = pop(pSt);

    printf("pop %d %s %d\n", firstOp, opStr, secondOp); 
    if(strcmp(opStr, "+") == 0)
    {
        push(pSt, (firstOp + secondOp));
    }
    else if(strcmp(opStr, "-") == 0)
    {
        push(pSt, (firstOp - secondOp));
    }
    else if(strcmp(opStr, "*") == 0)
    {
        push(pSt, (firstOp * secondOp));
    }
    else if(strcmp(opStr, "/") == 0)
    {
        push(pSt, (firstOp / secondOp));
    }
}

int evalRPN(char** tokens, int tokensSize) 
{
    
    PSTACK pSt = createStack();

    for(int i = 0 ; i < tokensSize ; i++)
    {
        char *pCurrStr = tokens[i];

        // handle operation first
        if(strcmp(pCurrStr, "+") == 0)
        {
            prvCalc(pSt, "+");
        }
        else if(strcmp(pCurrStr, "-") == 0)
        {
            prvCalc(pSt, "-");
        }
        else if(strcmp(pCurrStr, "*") == 0)
        {
            prvCalc(pSt, "*");
        }
        else if(strcmp(pCurrStr, "/") == 0)
        {
            prvCalc(pSt, "/");
        }
        else
        {
            int reader = 0;
            int currNum = 0;
            bool bNeg = false;

            // handle number
            if(pCurrStr[reader] == '-')
            {
                // negative number
                reader++;
                bNeg = true;
            }

            while(pCurrStr[reader] != '\0')
            {
                currNum *= 10;
                currNum += (pCurrStr[reader] - '0');
                reader++;
            }

            if(bNeg == true)
            {
                currNum *= -1;
            }

            printf("push %d \n", currNum);
            push(pSt, currNum);
        }
    }

                printf("size %d \n", size(pSt));

    int ans = pop(pSt);
    destroyStack(pSt);
    return ans;
}

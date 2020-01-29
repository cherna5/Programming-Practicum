//cherna83
//Program 2
//SEP 25
//Success! Your submission appears on this page. The submission confirmation number is 2d77a221-4a5f-441d-9b2b-3fbd0bb92f0e. Copy and save this number as proof of your submission.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//-----------------------------------------------------------------------------------------------------------------------------------------
//declaring our struct
typedef struct Node{
    char *darr;     //pointer to the dynamic array
    int  size;		//amount of space allocated
    int  inUse;		//top of stack indicator
    
}Node; //struct called Node

//-----------------------------------------------------------------------------------------------------------------------------------------
//store information from our struct onto the stack
void intialStack(Node *s){
    
    s->size = 2;	//set size
    char *darr = (char *) malloc(sizeof(char) * (s->size)); //malloc to properly create memory for dynamic array
    s->darr = darr;	//pntr to dynamic array
    s->inUse = 0;	//top of stack
    
}//end of initialStack()


//-----------------------------------------------------------------------------------------------------------------------------------------
//checking if the stack is empty,
int isEmpty(Node *s){
    if(s->inUse == 0)//empty
    {
        return 1;
    }
    else
    {
        return 0;//not empty
    }
}//end of isEmpty()

//-----------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------
//pushing an element onto the stack,
//also debugmode action
void push(Node *s, int val, int debugMode){
    if(s->inUse == s->size)
    {
        int i;
        char *temp = (char *) malloc((sizeof(char) * (s->size)) + 2);  //temp = holding space, this will make our arr grow b/c of push
        for(i = 0; i < s->size; i++)//transfering values to darr
        {
            temp[i] = s->darr[i];
        }
        
        free(s->darr);	//free stack being used
        s->darr = temp; //initializing temp to darr
        if (debugMode == 1)
        {
            printf("\n\nsize of OLD darr: %d \n",s->size);
        }
        
        s->size += 2; //new size for array
        if (debugMode == 1)
        {
            printf("size of NEW darr: %d \n", s->size);
      
            printf(" %d Values copied from current to new dynamic array\n",i);
        }
    }
    s->darr[(s->inUse)++] = val; //increment value to stack and top

}


//-----------------------------------------------------------------------------------------------------------------------------------------
//popping an element off of the stack,
void pop(Node *s, int debugMode){
    s->darr[(s->inUse)--] = 0; // decrements top of the stack
    
    if(debugMode == 1)
    {
        printf("\n' %c '---Pushed to the stack",   s->darr[s->inUse]);
        printf("\n' %c '---Popped from the stack", s->darr[s->inUse]);
    }

}//end of pop()

//-----------------------------------------------------------------------------------------------------------------------------------------
//accessing the top element on the stack
char top(Node *s){
    return s->darr[s->inUse - 1];
}//end of top()

//-----------------------------------------------------------------------------------------------------------------------------------------
//resetting the stack so that it is empty and ready to be used again.
void reset(Node *s){
    s->size = 2;	// making sure it's a size of 2
    s->inUse = 0;	// making sure our top stack is empty
    char *darr2 = (char *) malloc(sizeof(char) * (s->size)); //properly allocating new memory space into a new dynamic array for bew stack
    free(s->darr); //cleaning old info from old arr
    s->darr = darr2; //ptr to new darr2
}//end of top()


//-----------------------------------------------------------------------------------------------------------------------------------------
//to check wether input expression is missing symbols or is balance
void balance(int bal, Node s, int x)
{
    char op = '\0'; //operator symbo;
    int  y;

    if(bal == 1)
    {
        printf("\n");
    
        switch(isEmpty(&s))//if stack is empty then there is nothing to correct
        {
            
            case 1: printf("\nExpression is balanced\n");
        }
    
        if(isEmpty(&s) == 0) //check for oppisite symbol (closing)
        {
            switch(top(&s))//checking for symbol
            {
                case '(': op = ')'; break; case '{': op = '}'; break;
                case '[': op = ']'; break; case '<': op = '>'; break;
            }
            for(y =0; y < x; y++)
            {
                printf(" ");
            }
        
            printf("^ missing %c\n\n", op);
        }// end of if
    }// end of if balancing
}// end of balance()


//-----------------------------------------------------------------------------------------------------------------------------------------
//=========================================================================================================================================
int main(int argc, char** argv){
    
    char inputExp[300];	//whatever char the user inputs(given limit space)
    int debugMode = 0;
    int x;
    Node s;
    intialStack(&s);
    
    //for debugMode
    for(x = 0; x < argc; x++)
    {
        if(strcmp(argv[x], "-d") == 0)
        {
            printf(">>nDebugMode Information Is On<<\n\n");
            debugMode = 1;
        }
        else if (strcmp(argv[x], "-D") == 0)
        {
            printf(">>nDebugMode Information Is On<<\n\n");
            debugMode = 1;
        }
    
    }//end of for loop
//-----------------------------------------------------------------------------------------------------------------------------------------
    while(1) //while true
    {
        char op = '\0'; char exp = '\0'; int y; int bal = 1;
        
        printf("Please enter symbols/expression (q or Q to quit)\n\n");
      
        fgets(inputExp, 300, stdin); //reading in input
        
        if(inputExp[0] == 'Q' || inputExp[0] == 'q')// for quitting input purposes
        {
            printf("\nProgram Is Exiting...GOODBYE\n\n");
            break;
        }
        
        //for loop to read in input expression
        for(x = 0; x < strlen(inputExp) -1; x++)
        {
            switch (inputExp[x]) //When an opening symbol is encountered
            {
                case '(':   push(&s, inputExp[x], debugMode); break; case '{':   push(&s, inputExp[x], debugMode); break;
                case '[':   push(&s, inputExp[x], debugMode); break; case '<':   push(&s, inputExp[x], debugMode); break;
            }
            
            if(inputExp[x] == ')' || inputExp[x] == '}' || inputExp[x] == ']' || inputExp[x] == '>')
            {//checking for closing symbols if encounter to properly correspond with counter symbol
                switch(inputExp[x])
                {
                    case ')': op = '('; break; case '}': op = '{'; break;
                    case ']': op = '['; break; case '>': op = '<'; break;
                }
                
                //popping top of stack of encounter symbol
                if(top(&s) == op)
                {
                    pop(&s, debugMode);
                    
                    continue;
                }
                //if not encountered this method will represent closing symbol as missing
                if(top(&s) != op)
                {
                    if (isEmpty(&s) == 0) //not empty, something must go here
                    {
                        switch(top(&s))//checking respectively to symbol at current
                        {
                            case '(': exp = ')'; break; case '{': exp = '}'; break;
                            case '[': exp = ']'; break; case '<': exp = '>'; break;
                        }
                        
                        for(y = 0; y < x; y++)
                        {
                            printf(" ");
                        }
                        printf("^ expecting %c\n\n", exp);
                        bal = 0;
                        break;
                    }
                    else if(isEmpty(&s) == 1)//empty
                    {
                        for(y = 0; y < x; y++)
                        {
                            printf(" ");
                        }
                        printf("^ missing %c\n\n", op);
                        bal = 0;
                        break;
                    }
                }//end of if(top(&s))
              
            }// end of if(inputExp[])
        
        }//end of for loop
        if (debugMode == 1)//print out string/expression for debug purposes
        {
            printf("\nYour Expresion:\n");
            printf("%s",inputExp);
        }
        balance(bal, s, x);//will only read balance if expression is trully balance if not it will display what is needed
        
        reset(&s);//ready to start again
    }// end of while

    return 0;
}


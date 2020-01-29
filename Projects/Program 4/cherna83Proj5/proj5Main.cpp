/*
 * Author: cherna83
 *
 */

#include "proj5Tokens.h"

void printCommands()
{
    printf ("The commands for this program are:\n\n");
    printf ("q - to quit the program\n");
    printf ("? - to list the accepted commands\n");
    printf ("or any infix mathematical expression using operators of (), *, /, +, -\n");
}

//bool debugMode = false;

//void processExpression (Token inputToken, TokenReader *tr);

int popAndEval(int v1, int v2, int x){
    
    switch(x)
    {
        case '+': return v1 + v2; break;
        case '-': return v1 - v2; break;
        case '*': return v1 * v2; break;
        case '/': if (v2 == 0)//for runtime error check
        {
            printf("\n ERROR cannont divide by 0...\n");
            return 0;
        }
        else
        {
            return (v1 / v2);
            
        } break;
            
        default: printf("\n Invalid operation, exiting program.. \n");
            return 0;
    }
    
    
}//end of popAndEval
//------------------------------------------------

int main(int argc, char *argv[])
{

    
    
    bool debugMode = false;
    void processExpression (Token inputToken, TokenReader *tr);
    
    /***************************************************************/
    /* Add code for checking command line arguments for debug mode */
    if(!strcmp(argv[argc-1], "-d"))
    {
        debugMode = true;
    }
    
    Token inputToken;
    TokenReader tr;
    
    printf ("Starting Expression Evaluation Program\n\n");
    printf ("Enter Expression: ");
    
    
    inputToken = tr.getNextToken ();
    
    while (inputToken.equalsType(QUIT) == false)
    {
        /* check first Token on Line of input */
        if(inputToken.equalsType(HELP))
        {
            printCommands();
            tr.clearToEoln();
        }
        else if(inputToken.equalsType(ERROR))
        {
            printf ("Invalid Input - For a list of valid commands, type ?\n");
            tr.clearToEoln();
        }
        else if(inputToken.equalsType(EOLN))
        {
            printf ("Blank Line - Do Nothing\n");
            /* blank line - do nothing */
        }
        else
        {
            processExpression(inputToken, &tr);
        }
        
        printf ("\nEnter Expression: ");
        inputToken = tr.getNextToken ();
    }
    
    printf ("Quitting Program\n");
    return 1;
}

void processExpression (Token inputToken, TokenReader *tr)
{
    bool debugMode = false;
    /**********************************************/
    /* Declare both stack head pointers here      */
    //First Step: Empty both opStack and valStack
    MyStack* operatorStack = new MyStack();
    MyStack* valueStack = new MyStack();
    
    //Second Step:
    /* Loop until the expression reaches its End */
    while (inputToken.equalsType(EOLN) == false)
    {
        /* The expression contain a VALUE */
        if (inputToken.equalsType(VALUE))
        {
            /* make this a debugMode statement */
            if(debugMode == true){
                printf ("Val: %d, ", inputToken.getValue() );
            }
            
            // add code to perform this operation here
            valueStack->push(inputToken.getValue());//pushing to stack
        }
        
        /* The expression contains an OPERATOR */
        if (inputToken.equalsType(OPERATOR))
        {
            /* make this a debugMode statement */
            if(debugMode == true)
            {
                printf ("OP: %c, ", inputToken.getOperator() );
            }
            
            // add code to perform this operation here
            char ch = inputToken.getOperator();
            if(ch == '('){
                operatorStack->push(ch);
            }
            if(ch == '+' || ch == '-' ) {
                while(operatorStack->isEmpty() != 1 && (operatorStack->top()== '+' || operatorStack->top()== '-' || operatorStack->top()== '*' || operatorStack->top()=='/'))
                {
                    int op = operatorStack->top();
                    operatorStack->pop();
                    int v2 = valueStack->top();
                    valueStack->pop();
                    int v1 = valueStack->top();
                    valueStack->pop();
                    int v3 = popAndEval(v1, v2, op);
                    valueStack->push(v3);
                }
                operatorStack->push(ch);
            }
            if(ch == '*' || ch == '/')
            {
                while(operatorStack->isEmpty() != 1 && (operatorStack->top()== '*' || operatorStack->top()== '/'))
                {
                    int op = operatorStack->top();
                    operatorStack->pop();
                    int v2 = valueStack->top();
                    valueStack->pop();
                    int v1 = valueStack->top();
                    valueStack->pop();
                    int v3 = popAndEval(v1, v2, op);
                    valueStack->push(v3);
                }//end of while
                operatorStack->push(ch);
            }//end of if
            if(ch == ')')
            {
                while(operatorStack->isEmpty() != 1&& (operatorStack->top()!= '('))
                {
                    int op = operatorStack->top();
                    operatorStack->pop();
                    int v2 = valueStack->top();
                    valueStack->pop();
                    int v1 = valueStack->top();
                    valueStack->pop();
                    int v3 = popAndEval(v1, v2, op);
                    valueStack->push(v3);
                }//end of while
                if(operatorStack->isEmpty() == 1)
                {
                    printf("Operator Stack is EMPTY! \n");
                }//end of if
                else
                {
                    operatorStack->pop();
                }//end of else
            }//end of if (ch == ')')
        }
        
        /* get next token from input */
        inputToken = tr->getNextToken ();
    }
    
    /* The expression has reached its end */
    //THIRD STEP:
    // add code to perform this operation here
    while(operatorStack->isEmpty() != 1) // while not empty
    {
        if(operatorStack->isEmpty() == 1)
        {
            break;
        }//if //stack is empty
        
        int op = operatorStack->top();
        operatorStack->pop();
        int v2 = valueStack->top();
        valueStack->pop();
        int v1 = valueStack->top();
        valueStack->pop();
        int v3 = popAndEval(v1, v2, op);
        valueStack->push(v3);
    }
    
    printf("\nExpression evaluates to = %d\n",valueStack->top());
    valueStack->pop();
    if(valueStack->isEmpty() == 0)
    {
        printf("\nValue Stack is not EMPTY! \n");
    }
    printf ("\n");
}


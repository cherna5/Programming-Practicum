/* cherna83
 *
 */

/**************************************************************/
/*                                                            */
/*  The Code below this point should NOT need to be modified  */
/*  for this program.   If you feel you must modify the code  */
/*  below this point, you are probably trying to solve a      */
/*  more difficult problem that you are being asked to solve  */
/*                                                            */
/**************************************************************/


#include "proj5Tokens.h"


  Token::Token()
  {
    type = ERROR;
    op = '$';
    val = -999;
  }

  // Initialize to a specific TokenType
  Token::Token (TokenType t)
  {
    type = t;
    op = '$';
    val = -999;
  }

  // Set to a specific TokenType
  void Token::setToType(TokenType t)
  {
    type = t;
    op = '$';
    val = -999;
  }

  // Set to a OPERATOR TokenType with specific operator value
  void Token::setToOperator(char c)
  {
    type = OPERATOR;
    op = c;
    val = -999;
  }

  // Set to a VALUE TokenType with a specific numeric value
  void Token::setToValue(int v)
  {
    type = VALUE;
    op = '$';
    val = v;
  }

  // return true if the Current Token is of the given TokenType
  bool Token::equalsType(TokenType t)
  {
    if (type == t)
      return true;
    else
      return false;
  }

  // return true if the Current Token is of the OPERATOR TokenType
  //     and contains the given operator character
  bool Token::equalsOperator(char c)
  {
    if (type == OPERATOR && op == c)
      return true;
    else
      return false;
  }

  // Return the Operator for the current Token
  //   verify the current Token is of the OPERATOR TokenType
  char Token::getOperator ()
  {
    if (type == OPERATOR)
      return op;
    else
      return '$';   // using $ to indicate an error value
  }

  // Return the Value for the current Token
  //   verify the current token is of the value TokenType
  int Token::getValue()
  {
    if (type == VALUE)
      return val;
    else
      return -999;  // using -999 to indicate an error value
  }


  // initialize the TokenReader class to read from Standard Input
  TokenReader::TokenReader()
  {
    // set to read from Standard Input
    inputline[0] = '\0';
    pos = 0;
    needline = true;
  }

  // Force the next getNextToken to read in a line of input
  void TokenReader::clearToEoln()
  {
    needline = true;
  }

  // Return the next Token from the input line
  Token TokenReader::getNextToken()
  {
    char* endCheck;

    //printf ("getToken %d, %d, %s\n", pos, needline, inputline);

    // get a new line of input from user
    if (needline)
    {
      endCheck = fgets ( inputline, 300, stdin);

      if (endCheck == NULL )
      {
        printf ("Error in reading");
        Token t(EOFILE);
        return t;
      }

      for (int i = 0 ; i < strlen(inputline) ; i++)
          if ('\n' == inputline[i])
              inputline[i] = ' ';
      strcat (inputline , " ");    // add a space at end to help deal with digit calculation
      needline = false;
      pos = 0;
    }

    // skip over any white space characters in the beginning of the input
    while ( pos < strlen(inputline) && isspace(inputline[pos]) )
    {
      pos++;
    }

    // check for the end of the current line of input
    if (pos >= strlen(inputline))
    { // at end of line
      needline = true;
      Token t(EOLN);
      return t;
    }

    // Get the next character from the input line
    char ch = inputline[pos]; pos++;

    // check if 'q' or 'Q' was entered ==> QUIT Token
    if ( 'q' == ch || 'Q' == ch )
    {
      return Token (QUIT);
    }

    // check if "?" was entered ==> HELP Token
    if ( '?' == ch )
    {
      return Token (HELP);
    }

    // check for Operator values of: + - * / ( )  ==> OPERATOR Token
    if ( ('+' == ch) || ('-' == ch) || ('*' == ch) ||
      ('/' == ch) || ('(' == ch) || (')' == ch) )
    {
      Token t;
      t.setToOperator( ch );
      return t;
    }

    // check for a number  ==> VALUE Token
    if (isdigit(ch))
    {
      int number = int (ch) - int('0');  // subtract ascii value of ch from ascii value of '0'
      ch = inputline[pos]; pos++;
      while (isdigit(ch))
      {
        number = number * 10 + int (ch) - int('0');
        ch = inputline[pos]; pos++;
      }
      pos--; // since number calcuation check one character after the last digit
      Token t;
      t.setToValue( number );
      return t;
    }

    // Input in not valid if code get to this part ==> ERROR Token
    return Token (ERROR);
  }
///////////////

    
void MyStack::init()
    {
        this->arrSize = 2;
        size = 0;
        arr = new int[2];
    }
    
bool MyStack::isEmpty()
    {
        if(size == 0)
        {
            return true;
        }
        return false;
    }
    
void MyStack::push(int data)
    {
        if(size < arrSize)
        {
            arr[size] = data;
        }
        else{
            int *temp = new int[arrSize+2];
            temp[arrSize+1] = -999;
            for(int i=0; i<arrSize; i++)
            {
                temp[i] = arr[i];
            }
            temp[size] = data;
            arrSize += 2;
            
            int *x = arr;
            arr = temp;
            delete[] x;
        }
        size++;
    }
    
int MyStack::top()
    {
        return arr[size-1];
    }
    
void MyStack::pop()
    {
        size--;
    }
    
void MyStack::reset()
    {
        int *temp = arr;
        delete[] temp;
        arr = NULL;
    }


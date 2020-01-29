//cherna83
//proj4
//cs211
//10/23
#include "code.h"


//---------------------------------------------------------------------------------------------------
//new node for list
void addToList(Node **HD, char *name, int size, boolean boolean){
    Node *newHD = (Node*) malloc(sizeof(Node));
    newHD->name = name;
    newHD->size = size;
    
    if (boolean == FALSE)
    {
        newHD->boolean = 0;
    }
    else
    {
        newHD->boolean = 1;
    }
    
    newHD->next = NULL;
    
    if (*HD == NULL)
    {
        *HD = newHD;
        return;
    }
    
    else //if list is not empty
    {
        
        Node *temp = *HD;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }//end of while
        
        temp->next = newHD;//place in newHD
        
    }//end of else
    return;
}// end of addToList()


//---------------------------------------------------------------------------------------------------
//return boolean value indicating wether a name already exist
int doesNameExist(Node **HD, char *name){
    Node *temp = *HD;
    if (temp == NULL)
    {
        //printf("\nCan't update an empty List\n");
        return 0;
    }
    else
    {
        while(temp != NULL)
        {
            if (strcmp(temp->name, name) == 0)
            {
                return 1;
            }
            temp = temp->next;
        }//end of while
        return 0;
    }//end of else
    
}//end of doesNameExist()


//---------------------------------------------------------------------------------------------------
//for status inquiry
boolean updateStatus(Node **HD, char *name, int debugMode ){
    Node *temp = *HD;
    int counter = 1;//keep count
    if (debugMode == TRUE)
    {
        printf("\nDebugMode ON\n");
    }
    
    if (temp == NULL)
    {
        //printf("\nCan't update an empty List\n");
        return 0;
    }
    
    else
    {
        while(temp != NULL)
        {
        if(debugMode == TRUE)
        {
            printf("\n--%d -- %s -- %d -- %d\n", counter, temp->name, temp->size, (int)temp->boolean);
            counter++;
        }
        if(strcmp(temp->name, name) == 0)
         {
             if (temp->boolean == FALSE)
             {
                 return FALSE;
             }
             else
             {
                 temp->boolean = FALSE;
                 return TRUE;
             }
         }//end of if
        temp = temp->next;

         
         
        }//end of while
        return FALSE;
    }//end of else
    
}//end of updateStatus()


//---------------------------------------------------------------------------------------------------
//to remove group
void retrieveAndRemove(Node **HD, int val, int debugMode){
    Node *temp = *HD;
    Node *tmp;
    int counter = 1;
    if (temp == NULL)
    {
        //printf("\nCan't update an empty List\n");
        printf("\nERROR not a valid group size\n");
        exit(0);
    }
    
    if (debugMode == TRUE)
    {
        printf("\n DebugMode is ON\n");
    }
    
    if((temp->size <= val) && (temp->boolean == 0))
    {//HD of th list
        *HD = (*HD)->next;
        free (temp);
        if (debugMode == TRUE)
        {
            displayListInformation(HD);
        }
        
        return;
    }
    
    
    while(temp->next != NULL)
    {
        if(debugMode == TRUE)
        {
            printf("\n--  %d -- %s -- %d -- %d\n", counter, temp->name, temp->size, (int)temp->boolean);
            counter++;
        }
        if (temp->next->size <= val)
        {//check other list(S)
            if (temp->next->boolean == 0)
            {
            tmp = temp->next;
            temp->next = tmp->next;
            
            free(tmp);
            return;
            }
        }
        temp = temp->next;

        
    }//end of while
    printf("\n NOT A VALID GROUP SIZE \n");
    return;
    
}


//---------------------------------------------------------------------------------------------------
//counts the number of groups ahead
int countGroupAhead(Node **HD, char *name, int debugMode){
    Node *temp = *HD;
    int count = 0; //keep count to return number of ahead groups
    int counter = 1;//keep count for debug status
    
    if (debugMode == TRUE)
    {
        printf("\n DebugMode is ON\n");
    }
    
    if (temp == NULL)
    {
       // printf("\nCan't update an empty List\n");
        return 0;
    }
    
    while(temp != NULL)
    {
        if(debugMode == TRUE)
        {
            printf("\n--  %d -- %s -- %d -- %d\n", counter, temp->name, temp->size, (int)temp->boolean);
            counter++;
        }
        
        if(strcmp(temp->name, name) == 0)
        {
            return count;
        }
        temp = temp->next;
        count++;

        
        
    }//end of while
    return 0;
}


//---------------------------------------------------------------------------------------------------
//with the countGroupAhead we can determine and display the list ahead
void displayGroupSizeAhead(Node **HD, int val){
    Node *temp = *HD;
    int counter = 1;
    int count = 0;
    
    if (temp == NULL)
    {
      //  printf("\nCan't update an empty List\n");
        return;
    }
    if (temp == NULL)
    {
        printf("\n Group Size Ahead clear/reached \n");
        return;
    }
    
    printf("\n--Order--Name--Size--Status--\n");
    while(count != val)
    {
    if (temp != NULL)
    
    {

            if (temp->boolean == FALSE)
            {
                temp->boolean = TRUE;
            }
            else
            {
                temp->boolean = FALSE;
            }
        
        printf("\n--  %d -- %s -- %d -- %d\n", counter, temp->name, temp->size, (int)temp->boolean);
        counter++;
        temp = temp->next;
        count++;//given value++
    }
    }//end of if
    return;
}


//---------------------------------------------------------------------------------------------------
void displayListInformation(Node **HD){
    int counter = 1;
    Node *temp = *HD;
    
    if (temp == NULL)
    {
       printf("\nCan't update an empty List\n");
        return;
    }
    printf("\n--Order--Name--Size--Status--\n");
    while(temp != NULL)
    {
        if (temp->boolean == FALSE)
        {
            temp->boolean = TRUE;
        }
        else
        {
            temp->boolean = FALSE;
        }
        
        printf("\n--  %d -- %s -- %d -- %d\n", counter, temp->name, temp->size, (int)temp->boolean);
        counter++;
        temp = temp->next;
    }
    return;
}


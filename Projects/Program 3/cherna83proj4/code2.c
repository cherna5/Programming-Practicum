//cherna83
//proj4
//cs211
//10/23

#include "code.h"

void doAdd (Node **HD, int debugMode)
{
    /* get group size from input */
    int size = getPosInt();
    if (size < 1)
    {
        printf ("Error: Add command requires an integer value of at least 1\n");
        printf ("Add command is of form: a <size> <name>\n");
        printf ("  where: <size> is the size of the group making the reservation\n");
        printf ("         <name> is the name of the group making the reservation\n");
        return;
    }
    
    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Add command requires a name to be given\n");
        printf ("Add command is of form: a <size> <name>\n");
        printf ("  where: <size> is the size of the group making the reservation\n");
        printf ("         <name> is the name of the group making the reservation\n");
        return;
    }
    
   
    
    // add code to perform this operation here
    if(doesNameExist(HD, name))
    {
        printf("No name to add b/c it's in the list");
        return;
    }
    else
    {
        if(debugMode == TRUE)
        {
            displayListInformation(HD);
        }
        printf ("Added \"%s\" for a table of %d\n", name, size);
        addToList(HD, name, size, FALSE);
        return;
    }
}


void doCallAhead (Node **HD, int debugMode)
{
    /* get group size from input */
    int size = getPosInt();
    if (size < 1)
    {
        printf ("Error: Call-ahead command requires an integer value of at least 1\n");
        printf ("Call-ahead command is of form: c <size> <name>\n");
        printf ("  where: <size> is the size of the group making the reservation\n");
        printf ("         <name> is the name of the group making the reservation\n");
        return;
    }
    
    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Call-ahead command requires a name to be given\n");
        printf ("Call-ahead command is of form: c <size> <name>\n");
        printf ("  where: <size> is the size of the group making the reservation\n");
        printf ("         <name> is the name of the group making the reservation\n");
        return;
    }
        // add code to perform this operation here
    if(doesNameExist(HD, name))
    {
        printf("No name to add b/c it's in the list");
        return;
    }
    else
    {
        if(debugMode == TRUE)
        {
            displayListInformation(HD);
        }
        printf ("GroupAhead added \"%s\" for a table of %d\n", name, size);
        addToList(HD, name, size, TRUE);
        return;
    }

}

void doWaiting (Node **HD, int debugMode)
{
    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: Waiting command requires a name to be given\n");
        printf ("Waiting command is of form: w <name>\n");
        printf ("  where: <name> is the name of the group that is now waiting\n");
        return;
    }
    
      // add code to perform this operation here
    
    printf ("Waiting group \"%s\" is now in the restaurant\n", name);
    
    if(!doesNameExist(HD, name))
    {
        if (debugMode == TRUE)
        {
         displayListInformation(HD);
        }
        printf("\nThe name you gave does not exist in the list\n");
        return;
    }
    if(updateStatus(HD, name, debugMode) == FALSE){
        return;
    }
    else{
        updateStatus(HD, name, debugMode);
        return;
    }
  
}

void doRetrieve (Node **HD, int debugMode)
{
    /* get table size from input */
    int size = getPosInt();
    if (size < 1)
    {
        printf ("Error: Retrieve command requires an integer value of at least 1\n");
        printf ("Retrieve command is of form: r <size>\n");
        printf ("  where: <size> is the size of the group making the reservation\n");
        return;
    }
    clearToEoln();
    printf ("Retrieve (and remove) the first group that can fit at a tabel of size %d\n", size);
    
    // add code to perform this operation here
    retrieveAndRemove(HD, size, debugMode);
    return;
}

void doList (Node **HD, int debugMode)
{
    /* get group name from input */
    char *name = getName();
    if (NULL == name)
    {
        printf ("Error: List command requires a name to be given\n");
        printf ("List command is of form: l <name>\n");
        printf ("  where: <name> is the name of the group to inquire about\n");
        return;
    }
        // add code to perform this operation here
    if(doesNameExist(HD, name))
    {//if matched
        int count =0;
        count = countGroupAhead(HD, name, debugMode);
        printf("\n Total number of groups in the front wait list after \"%s\": %d\n", name, count);
        
        printf ("\n The group \"%s\" is before the following groups\n", name);
        
        displayGroupSizeAhead(HD, count);//list per group
        return;
    }
    else
    {    //adds to the end if no match
        printf("\n No given name exists in the list\n");
        return;
    }
    

}

void doDisplay (Node **HD)
{
    clearToEoln();
    printf ("Display information about all groups\n");
    
    // add code to perform this operation here
    displayListInformation(HD);
}

//cherna83
//cs211
//9/11/2017
//program1

#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------------------------------------------
// Functino to copy one array to another
void arrayCopy(int fromArr[], int toArr[], int size){
    int i;
    for (i=0; i < size; i++)
    {
        toArr[i] = fromArr[i];
    }
}// end of arrayCopy


//---------------------------------------------------------------------------------------------------------------
//function to display any array list
void displayArr(int arr[], int size){
    int i;
    for (i=0; i <size; i++)
    {
        printf("%d) %d\n----------", i , arr[i]); //at position, element value
        printf("\n");
    }
}// end of displayArr


//---------------------------------------------------------------------------------------------------------------
// Function to sort out a list of an array into ascending order
// Bubble sort method used

void bubbleSort(int darr[], int size){
    int temp;
    int i; int j;
    for(i=0; i < size; i++)
    {
        for(j=0; j < size-i-1; j++)
        {
            if(darr[j] > darr[j+1])
            {
                temp = darr[j];
                darr[j] = darr[j+1];
                darr[j+1] = temp;
            }
        }
    }
}//end of bubble sort


//---------------------------------------------------------------------------------------------------------------
//function to perform linear search on unsorted array
//returning 2 vals, 1st position and second num of camparisons
int linSearch(int arr[], int size, int target, int *numCamparisons){
    int i;
    for (i=0; i<size; i++)
    {
        *numCamparisons +=1;
        if (target == arr[i])
        {
            break;
        }
    }// end of for loop
    
    if (i == size)
    {
        return -1;//not found
    }
    else
    {
        return i;//position found
    }
    
}// end of linSearch


//---------------------------------------------------------------------------------------------------------------
// function to perform binary search on the sorted array
// two values; val position and num of comparisons
int binSearch(int arr[], int size, int target, int *numComparisons){
    int first = 0;  //small element in array
    int last = size - 1;   //bigger element in array
    int middle = (first + last)/2;  //middle element in array
    
    while(first <= last){
        
        *numComparisons+=1;
        if(arr[middle] < target)
        {
            first = middle + 1;
        }
        else if(arr[middle] == target)
        {
            return middle;
            break;
        }
        else
        
            last = middle - 1;
            middle = (first + last)/2;
        
    }//end of while loop
    
    if (first>last)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}//end of binSearch


//===============================================================================================================
int main() {
    int val=0;
    int counter = 0; //keeps track
    
    //Allocating dynamic array (for current size)
    int *darr;
    int size = 100;
    darr = (int*) malloc(size * sizeof(int)); //array to be sorted
    
    printf("Please enter values into an array followed by -999 to indicate end of list.\n");
    while (val != -999){
        scanf("%d", &val);
        
        if (counter >= size)
        {
            int *temp; //hold save our array for a temporary moment
            int i;
            temp = (int*) malloc (size* 2* sizeof(int)); //growing the array to make it truly dynamic
            
            for (i=0; i < size; i++) //storing current data to the new growing array
            {
                temp[i] = darr[i];
            }
            
            free (darr); // will now have old information with more space for new memory
            darr = temp; //pointing to dynamic array
            size = size*2; //array grown double in size
        }//enf of if
        
        darr[counter] = val;
        counter++; //increment counter completion
    }// end of while loop
    
    int *darr2;
    darr2 = (int*) malloc (size * 2 * sizeof(int) ); //second dynamic array, original unsorted array
    
    arrayCopy(darr, darr2, counter - 1);
    bubbleSort(darr, counter-1);
    
    printf("\nDisplay Sorted array\n");
    displayArr(darr, counter-1);
    printf("\nDisplay Unsorted Array\n");
    displayArr(darr2, counter-1);
    
//-------------------------------------------------Second Part for Linear and Binary---------------------------------
    int userVal=0;
    while (userVal != -999){
        
        int valLinPosition = 0;
        int valBinPosition = 0;
        int numLinComparisons = 0;
        int numBinComparisons = 0;
        
        printf("\nPlease enter a value to serch via Linear and Binary searches (end with -999 to end Search): \n");
        printf("---------------------------------------------------------------------------------------------\n");
        scanf("%d", &userVal);
        if (userVal == -999) // important to break away from while loop
        {
            printf("\nList approached -999 (Terminal Value) Program executed correctly. \n");
            break; //end execution and break from loop
        }
        //valLinPosition = our value position for linear search
        valLinPosition = linSearch(darr2, counter-1, userVal, &numLinComparisons);//setting linear value we're looking for = to function to perform search and numComparisons
        valBinPosition = binSearch(darr,  counter-1, userVal, &numBinComparisons);//setting binary value we're looking for = to function to perform search and numComparisons
        
        if ((valLinPosition == -1) && (valBinPosition == -1)) //-1 = Not Found
        {
            printf("\nValue %d Not Found! Completed in %d comparisons. Via Linear Search. \n", userVal, numLinComparisons);
            printf("\nValue %d Not Found! Completed in %d comparisons. Via Binary Search. \n", userVal, numBinComparisons);
            valLinPosition = 0; valBinPosition = 0; numLinComparisons = 0 ; numBinComparisons = 0; //settting values and num of compariosons back to zero
        }
        else
        {
            printf("For Unosrted Array:");
            printf("\nSearch Found! For value %d via Linear Search: position location at %d. Completed in %d comparisons. \n", userVal,  valLinPosition, numLinComparisons);
            printf("\nFor Sorted Array:");
            printf("\nSearch Found! For value %d via Binary Search: position location at %d. Completed in %d Comparisons. \n", userVal,  valBinPosition, numBinComparisons);
            valLinPosition = 0; valBinPosition = 0; numLinComparisons = 0 ; numBinComparisons = 0; //settting values and num of compariosons back to zero
        }
        
    }//end of while loop
    printf("\n");
    return 0;
}

/* //cherna83 //proj4 //cs211 //10/23 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {FALSE = 0, TRUE = 1} boolean;

typedef struct linkList{
    char *name;
    int size;
    boolean boolean;
    struct linkList *next;
}Node;


/* code1.c */
int main();
void clearToEoln();
int getNextNWSChar ();
int getPosInt ();
char *getName();
void printCommands();



/* code2.c  */
void doAdd (Node **HD, int debugMode);
void doCallAhead (Node **HD, int debugMode);
void doWaiting (Node **HD, int debugMode);
void doRetrieve (Node **HD, int debugMode);
void doList (Node **HD, int debugMode);
void doDisplay (Node **HD);


/* code3.c*/
void addToList(Node **HD, char *name, int size, boolean boolean);
int doesNameExist(Node **HD, char *name);
boolean updateStatus(Node **HD, char *name, int debugMode );
void retrieveAndRemove(Node **HD, int val, int debugMode);
int countGroupAhead(Node **HD, char *name, int debugMode);
void displayGroupSizeAhead(Node **HD, int val);
void displayListInformation(Node **HD);


/* THIS COMMENT NEEDS TO DESCRIBE THE HIGH-LEVEL OPERATION OF THE PROGRAM + 
cINCLUDE USER-INTERFACE NOTES IE HOW USER PICKS BETWEEN ACTIONS. 
INCLUDE NEED TO USE TERMINAL. IE TYPE CD /PROJECTS/PROJECT1/ ENTER
LS ENTER ./A.OUT ENTER THEN FOLLOW COMMANDS PRINTED TO TERMINAL */

#include <stdio.h>

/* Below are 4 functions prototypes that were made to executed the programs function to 
decrypt and encrypt messages. The function syntax is:
        [return data type] function_name(function arguments) 
    Each function will be explained in further detail when it 
    appears as a function definition later in the code. */
char encrypt_rotation(char *message, int i, int encryptRotKey);
char decryptRotation(char *message, int index, int decryptRotKey);
char encryptSubstitution(char *message, int index, char *key);
char decryptSubstitution(char *message, int index, char *key);


int main()
{
    /*char is short for character. It is the data type that holds
    one character (letter, number etc) of data. Here the variable 
    'choice' is initialised to be of data type 'char'*/
    char choice; 
    
    /*the do while loop  executes the following code at least once 
    with the condition being tested at the end. The loop only repeats
    if the condition is TRUE, otherwise the loop quits executing.*/
    do  
    {
        
    /* The following 7 printf statements are used to create a menu that the 
    user users to select what function they would like to be executed. The
    user is instructed to type a b c d OR e into the terminal. From here, the
    scanf function reads the users input and stores it in the 'choice' variable
    as a char data type. This user input is then used in the switch case. */ 
    
        printf("Please select an option: \n");  // \n prints the text on a new line
        printf("'a' encryption of code using rotation cipher \n");
        printf("'b' decryption of code using rotation cipher \n");
        printf("'c' encryption of code using substitution cipher \n");
        printf("'d' decryption of code using substitution cipher \n");
        printf("Enter a b c OR d for selection: \n");
    
        
        scanf("%c", &choice); 
     
       /* the syntax for a switch case is as follows:
            switch(expression)
            {
                case constant:
                    break;
                case constant:
                    break;
                default:
                    break;
            }
        where 'expression' is anything that evaluates to a number. For this code, the
        expression is the variable 'choice' which is the user's input. For the switch case
        to execute, the user must enter either a, b, c, OR d (this input is known as a constant).
        Once this input is read, only the specific case that corresponds to the user's input will
        be executed. If the user enters a constant that is not a, b, c OR d, then the default case
        will be executed and the menu will be printed again since the conditions of the while loop
        will be satisfied. */
        switch(choice)
        {
            case 'a': 
                {
                    /*
                     An array is...
                     i represents an array index. This must be an integer. An array index 
                     accesses a unique variable that is stored in the array. When i = 0, it 
                     accesses the first element of the array. 
                     INT DATA TYPE QUICK EXPLANATION 
                     */
                    int i; 
                    /* */
                    int encryptRotKey;
                    /* */
                    char message[1000]; // array WHAT IS IT??
                    
                    
                    /* */
                    printf("create a key between 1 and 26: ");
                    /* */
                    scanf("%d", &encryptRotKey); 
                    /* */
                    printf("create a message to encrypt: ");
                    /* */
                    scanf(" %[^\n]s", message);        // the name of an array is a pointer to the first element of an array therefore no &
                   
                    
                    encrypt_rotation(message, index, encryptRotKey); // DIRECT READER HERE AFTER READING COMMENT BEFORE FUNC DEF
                    printf("encrypted message is: %s \n", message);
                    
                    break;
                }
            case 'b':
                {
                    int index = 0;
                    int decryptRotKey;
                    char message[500];
                    
                    printf("create a key between 1 and 26: ");
                    scanf("%d", &decryptRotKey);
                    printf("create a message to decrypt: ");
                    scanf(" %[^\n]s", message);
                    
                    decryptRotation(message, index, decryptRotKey);
                    printf("decrypted message using rotation is: %s\n", message);
                    
                    break;
                }
            case 'c':
                {
                    int index = 0;
                    char key[26];
                    char message[500];
                    
                    printf("Enter a key for substitution encryption: ");
                    scanf("%s", key);
                    printf("Enter a message to encrypt using substitution: "); //PLEASE GET MILK AT THE SHOPS
                    scanf(" %[^\n]s", message);
                    
                    encryptSubstitution(message, index, key);
                    printf("encrypted message is: %s\n", message);
                    
                    break;                
                }
            case 'd':
                {
                    int index = 0;
                    char key[26]; //KXVMCNOPHQRSZYIJADLEGWBUFT for "QWERTY" key
                    char message[500]; //HSTQLT UTZ DOSA QZ ZIT LIGHL
                    
                    printf("Enter a key for substitution decryption: ");
                    scanf("%s", key);
                    printf("Enter a message to decrypt using substitution: ");
                    scanf(" %[^\n]s", message);
                    
                                  
                    decryptSubstitution(message, index, key);
                    printf("decrypted message is: %s\n", message);
                    
                    break;                
                }
            default:
                {
                    printf("An error has occured, please enter a b c OR d \n");
                    break;
                }
    
        }
    }
        while(choice < 97 || choice > 100);
        return 0;
           
}
/* This is the function defintion for the function (when called using the switch
case) that will take the user's message and selected key (a number between 0 and 26) to 
encrypt the message using the rotation cipher. The "key" is the number of letters by which 
the alphabet is shifted when calculating what letter will be changed to what letter. 

The return data type for this function is char and its name is 'encrypt_rotation'. 
The first argument for this function is 'message' and it has the data type char. However,
since 'message' is an array, it is not efficient to pass a whole array in a function and therefore, 
a pointer is used. A pointer is the memory address of the array's first element and has the syntax '*'. 
The remaining arguments of this function are not arrays and therefore do not require pointers in 
order to pass variables the function.  */
char encrypt_rotation(char *message, int i, int encryptRotKey)
{
    /* FUNCTION IMPLEMENTED USING FOR AND IF LOOP. EXPLAIN DETAILS AND SPECIFICS ESPECIALLY
    ENCRYPT ROT ASSIGNMENT*/
    for(i = 0; message[i] !=0; i ++)
       {
           if (message[i] > 64 && message[i] < 91)
           {
               message[i] = ((message[i] - 65) + encryptRotKey) %26 + 65;
           }
           
           else 
           {
               
           }
    
         
    }
    return message[i]; // EXPLAIN WHAT THIS DOES
  } 
  
  //REPEAT FIRST FUNCTION EXPLAINATION
  char decryptRotation(char *message, int index, int decryptRotKey)
  {
      for(index = 0; message[index] != 0; index ++)
      {
          if (message[index] > 64 && message[index] < 91)
          {
              message[index] = ((message[index] - 65) - decryptRotKey + 26) %26 + 65;
          }
          else 
          {
              
          }
      }
      return message[index];  
  }

  char encryptSubstitution(char *message, int index, char *key)
  {
      for (index = 0; message[index] != 0; index ++)
      {
          switch(message[index])
          {
            case 'A':
                message[index] = key[0];
                break;
            case 'B':
                message[index] = key[1];
                break;
            case 'C':
                message[index] = key[2];
                break;
            case 'D':
                message[index] = key[3];
                break;
            case 'E':
                message[index] = key[4];
                break;
            case 'F':
                message[index] = key[5];
                break;
            case 'G':
                message[index] = key[6];
                break;
            case 'H':
                message[index] = key[7];
                break;
            case 'I':
                message[index] = key[8];
                break;
            case 'J':
                message[index] = key[9];
                break;
            case 'K':
                message[index] = key[10];
                break;
            case 'L':
                message[index] = key[11];
                break;
            case 'M':
                message[index] = key[12];
                break;
            case 'N':
                message[index] = key[13];
                break;
            case 'O':
                message[index] = key[14];
                break;
            case 'P':
                message[index] = key[15];
                break;
            case 'Q':
                message[index] = key[16];
                break;
            case 'R':
                message[index] = key[17];
                break;
            case 'S':
                message[index] = key[18];
                break;
            case 'T':
                message[index] = key[19];
                break;
            case 'U':
                message[index] = key[20];
                break;
            case 'V':
                message[index] = key[21];
                break;
            case 'W':
                message[index] = key[22];
                break;
            case 'X':
                message[index] = key[23];
                break;
            case 'Y':
                message[index] = key[24];
                break;
            case 'Z':
                message[index] = key[25];
            default:
                break;
          }
      }
      return message[index];
  }
  
  char decryptSubstitution(char *message, int index, char *key)
  {
      for(index = 0; message[index] != 0; index ++)
      {
          switch(message[index])
          {
            case 'A':
                message[index] = key[0];
                break;
            case 'B':
                message[index] = key[1];
                break;
            case 'C':
                message[index] = key[2];
                break;
            case 'D':
                message[index] = key[3];
                break;
            case 'E':
                message[index] = key[4];
                break;
            case 'F':
                message[index] = key[5];
                break;
            case 'G':
                message[index] = key[6];
                break;
            case 'H':
                message[index] = key[7];
                break;
            case 'I':
                message[index] = key[8];
                break;
            case 'J':
                message[index] = key[9];
                break;
            case 'K': 
                message[index] = key[10];
                break;
            case 'L':
                message[index] = key[11];
                break;
            case 'M':
                message[index] = key[12];
                break;
            case 'N':
                message[index] = key[13];
                break;
            case 'O':
                message[index] = key[14];
                break;
            case 'P':
                message[index] = key[15];
                break;
            case 'Q':
                message[index] = key[16];
                break;
            case 'R':
                message[index] = key[17];
                break;
            case 'S':
                message[index] = key[18];
                break;
            case 'T':
                message[index] = key[19];
                break;
            case 'U':
                message[index] = key[20];
                break;
            case 'V':
                message[index] = key[21];
                break;
            case 'W':
                message[index] = key[22];
                break;
            case 'X':
                message[index] = key[23];
                break;
            case 'Y':
                message[index] = key[24];
                break;
            case 'Z':
                message[index] = key[25];
                break;
            default:
                break;
          }
      }
      return message[index];
  }
  
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
char decryptRotation(char *cipher_text, int i, int decryptRotKey);
char encryptSubstitution(char *message, int i, char *encryptSubKey);
char decryptSubstitution(char *cipher_text, int i, char *decryptSubKey);


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
                   
                    
                    encrypt_rotation(message, i, encryptRotKey); // DIRECT READER HERE AFTER READING COMMENT BEFORE FUNC DEF
                    printf("encrypted message is: %s \n", message);
                    
                    break;
                }
            case 'b':
                {
                    int i = 0;
                    int decryptRotKey;
                    char cipher_text[500];
                    
                    printf("create a key between 1 and 26: ");
                    scanf("%d", &decryptRotKey);
                    printf("Enter text to decrypt: ");
                    scanf(" %[^\n]s", cipher_text);
                    
                    decryptRotation(cipher_text, i, decryptRotKey);
                    printf("decrypted message using rotation is: %s\n", cipher_text);
                    
                    break;
                }
            case 'c':
                {
                    int i = 0;
                    char encryptSubKey[26];
                    char message[500];
                    
                    printf("Enter a key for substitution encryption: ");
                    scanf("%s", encryptSubKey);
                    printf("Enter a message to encrypt using substitution: "); //PLEASE GET MILK AT THE SHOPS
                    scanf(" %[^\n]s", message);
                    
                    encryptSubstitution(message, i, encryptSubKey);
                    printf("encrypted message is: %s\n", message);
                    
                    break;                
                }
            case 'd':
                {
                    int i = 0;
                    char decryptSubKey[26]; //KXVMCNOPHQRSZYIJADLEGWBUFT for "QWERTY" key
                    char cipher_text[500]; //HSTQLT UTZ DOSA QZ ZIT LIGHL
                    
                    printf("Enter the key for substitution decryption: ");
                    scanf("%s", decryptSubKey);
                    printf("Enter text to decrypt using substitution: ");
                    scanf(" %[^\n]s", cipher_text);
                            
                    decryptSubstitution(cipher_text, i, decryptSubKey);
                    printf("decrypted message is: %s\n", cipher_text);
                                                                        
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
  char decryptRotation(char *cipher_text, int i, int decryptRotKey)
  {
      for(i = 0; cipher_text[i] != 0; i ++)
      {
          if (cipher_text[i] > 64 && cipher_text[i] < 91)
          {
              cipher_text[i] = ((cipher_text[i] - 65) - decryptRotKey + 26) %26 + 65;
          }
          else 
          {
              
          }
      }
      return cipher_text[i];  
  }

  char encryptSubstitution(char *message, int i, char *encryptSubKey)
  {
      for (i = 0; message[i] != 0; i ++)
      {
          switch(message[i])
          {
            case 'A':
                message[i] = encryptSubKey[0];
                break;
            case 'B':
                message[i] = encryptSubKey[1];
                break;
            case 'C':
                message[i] = encryptSubKey[2];
                break;
            case 'D':
                message[i] = encryptSubKey[3];
                break;
            case 'E':
                message[i] = encryptSubKey[4];
                break;
            case 'F':
                message[i] = encryptSubKey[5];
                break;
            case 'G':
                message[i] = encryptSubKey[6];
                break;
            case 'H':
                message[i] = encryptSubKey[7];
                break;
            case 'I':
                message[i] = encryptSubKey[8];
                break;
            case 'J':
                message[i] = encryptSubKey[9];
                break;
            case 'K':
                message[i] = encryptSubKey[10];
                break;
            case 'L':
                message[i] = encryptSubKey[11];
                break;
            case 'M':
                message[i] = encryptSubKey[12];
                break;
            case 'N':
                message[i] = encryptSubKey[13];
                break;
            case 'O':
                message[i] = encryptSubKey[14];
                break;
            case 'P':
                message[i] = encryptSubKey[15];
                break;
            case 'Q':
                message[i] = encryptSubKey[16];
                break;
            case 'R':
                message[i] = encryptSubKey[17];
                break;
            case 'S':
                message[i] = encryptSubKey[18];
                break;
            case 'T':
                message[i] = encryptSubKey[19];
                break;
            case 'U':
                message[i] = encryptSubKey[20];
                break;
            case 'V':
                message[i] = encryptSubKey[21];
                break;
            case 'W':
                message[i] = encryptSubKey[22];
                break;
            case 'X':
                message[i] = encryptSubKey[23];
                break;
            case 'Y':
                message[i] = encryptSubKey[24];
                break;
            case 'Z':
                message[i] = encryptSubKey[25];
            default:
                break;
          }
      }
      return message[i];
  }
  
  char decryptSubstitution(char *cipher_text, int i, char *decryptSubKey)
  {
      for(i = 0; cipher_text[i] != 0; i ++)
      {
          switch(cipher_text[i])
          {
            case 'A':
                cipher_text[i] = decryptSubKey[0];
                break;
            case 'B':
                cipher_text[i] = decryptSubKey[1];
                break;
            case 'C':
                cipher_text[i] = decryptSubKey[2];
                break;
            case 'D':
                cipher_text[i] = decryptSubKey[3];
                break;
            case 'E':
                cipher_text[i] = decryptSubKey[4];
                break;
            case 'F':
                cipher_text[i] = decryptSubKey[5];
                break;
            case 'G':
                cipher_text[i] = decryptSubKey[6];
                break;
            case 'H':
                cipher_text[i] = decryptSubKey[7];
                break;
            case 'I':
                cipher_text[i] = decryptSubKey[8];
                break;
            case 'J':
                cipher_text[i] = decryptSubKey[9];
                break;
            case 'K': 
                cipher_text[i] = decryptSubKey[10];
                break;
            case 'L':
                cipher_text[i] = decryptSubKey[11];
                break;
            case 'M':
                cipher_text[i] = decryptSubKey[12];
                break;
            case 'N':
                cipher_text[i] = decryptSubKey[13];
                break;
            case 'O':
                cipher_text[i] = decryptSubKey[14];
                break;
            case 'P':
                cipher_text[i] = decryptSubKey[15];
                break;
            case 'Q':
                cipher_text[i] = decryptSubKey[16];
                break;
            case 'R':
                cipher_text[i] = decryptSubKey[17];
                break;
            case 'S':
                cipher_text[i] = decryptSubKey[18];
                break;
            case 'T':
                cipher_text[i] = decryptSubKey[19];
                break;
            case 'U':
                cipher_text[i] = decryptSubKey[20];
                break;
            case 'V':
                cipher_text[i] = decryptSubKey[21];
                break;
            case 'W':
                cipher_text[i] = decryptSubKey[22];
                break;
            case 'X':
                cipher_text[i] = decryptSubKey[23];
                break;
            case 'Y':
                cipher_text[i] = decryptSubKey[24];
                break;
            case 'Z':
                cipher_text[i] = decryptSubKey[25];
                break;
            default:
                break;
          }
      }
      return cipher_text[i];
  }
  
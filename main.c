/*The following code allows the user encrypt and decrypt selected messages using
both rotation (also known as Ceaser Cipher) and substitution cipher algorithms. 
Specifically, each message will be stored as a string of ASCII characters. 
ASCII assigns a number to letters, numbers and other characters so that a 
computer is able to read the user's input. 

The high-level operation of this program is Cryptography. This is the practice of 
techniques for secure communication in order to prevent anyone reading secret 
messages who do not otherwise have permission to. Applications of cytrography 
includes;
    - chip based payment cards
    - digital currencies
    - computer passwords
    - military communications
    
For the user to use this program, they must use the 'terminal' not 'run' as 
simply pressing run on this program in eclipse che does not allow the user to 
input any data. To work the program in the terminal the user must;
    1. Go into the terminal tab at the bottom of the screen
    2. Type into the user interface 'cd /projects/project1/' then press enter
    3. Type in 'ls' then press enter.
    4. Type in './a.out' then press enter.
    5. Follow the prompts that will be printed to the screen. To implement what
    the user has typed into the user face, they must press enter each time. 
For this program to work, the messages inputted MUST use capital letters ONLY!  

#include <stdio.h>

/* Below are 4 functions prototypes that were made to executed the programs function to 
   decrypt and encrypt messages. The function syntax is:
        [return data type] function_name(function arguments) 
    Each function will be explained in further detail when it 
    appears as a function definition later in the code. */
char encrypt_rotation(char *message, int i, int encryptRotKey);
char decrypt_rotation(char *cipher_text, int i, int decryptRotKey);
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
        
    /* The following 6 printf statements are used to create a menu that the 
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
                     An array is a collection of variables of the same data type. It has the 
                     following syntax:
                        data_type name[N], where N is the array length
                     'i' represents an array index. This must be an integer. An array index 
                     accesses a unique variable that is stored in the array. When i = 0, it 
                     accesses the first element of the array. 
                     
                     'int' is the data type that stores integers. */
                    int i; 
                    /*The variable below represents the key that the user selects that will
                    be used to shift the letters in the alphabet in order to encrypt a message.*/
                    int encryptRotKey;
                    /*The variable below is an array. It represents the message the user will create to
                    be encrypted via rotation. The array has a length of 1000 meaning it can store up to
                    1000 characters that the user inputs.*/
                    char message[1000]; 
                    
                    
                    /*The following text in green will be printed to the terminal */
                    printf("create a key between 1 and 26: ");
                    /*Using the following scanf function, the number for the key that the user inputs into 
                    the terminal will be stored as a integer in the variable 'encryptRotKey'. The format specifier 
                    for an integer is 'd'. The & symbol returns the address of the variable */
                    scanf("%d", &encryptRotKey); 
                    /*The following text in green will be printed to the terminal*/
                    printf("create a message to encrypt: ");
                    /*The following scanf function reads the message the user previously entered 
                    into the terminal. Since the message is an array, it is stored as a string
                    of characters, ie has the format specifier 's'. However, since this format specifier
                    does not read white spaces (therefore it does not read spaces), the '[^\n]' must be 
                    added. It tells the function to only stop reading the string once a new line is encounted
                    and therefore allows the user to encrypt a sentence of words instead of just one word. 
                    
                    Additionally, since this variable is an array, the '&' is not required for the scanf 
                    function to read the user's input. In other words it is not neeeded as the name of an array
                    is a pointer to the first element of the array*/
                    scanf(" %[^\n]s", message);        
                    
                    /* Go to row 200 before reading the rest of this case as the following is executed AFTER the function
                    definition starting at row 200. */
                    
                    /*The two lines of code following this comment are executed as follows: 
                        - The encrypted message that was created using the encrypt_rotation function is passed back here 
                        - The encrypted message is printed to the user interface.*/
                    encrypt_rotation(message, i, encryptRotKey); 
                    printf("encrypted message is: %s \n", message);
                    
                    /*The break statement tells the program to stop executing. If it was not included, 
                    the program would continue to run each case in the switch case*/
                    break; 
                }
            case 'b':
                {
                    int i = 0; //same as case 'a'
                    /*The variable initialised below has the same purpose as with case 'a', 
                    except it will be used to decrypt a cipher text (a message that has 
                    previously been encrypted using rotation). Hence, it is named 'decryptRotKey*/
                    int decryptRotKey; 
                    /*The variable below is an array and represents the message the user will choose
                    to be decrypted via rotation. The array has a length of 1000 characters.*/
                    char cipher_text[1000];
                    
                    
                    printf("create a key between 1 and 26: ");
                    /* the scanf function below reads the user's input and stores it as the decryption key
                    variable with data type int ie stores it as an integer. */
                    scanf("%d", &decryptRotKey); 
                    printf("Enter text to decrypt: ");
                    /* Same principles apply for the following scanf function as did with the corresponding scanf
                    for case 'a'. However, it is stored as the array 'cipher_text', not the array called 'message' */
                    scanf(" %[^\n]s", cipher_text);
                    
                    /* Go to row AHAHAHAHAHHAHA before reading the rest of the code in case 'b' as the block of code that starts there
                    under the decryptRotation function definition is executed FIRST. */
                    
                    /*The following two lines of code are executed as follows:
                        - The message that was decrypted using the decrypt_rotation function is passed back
                        - The decrypted message is printed to the user interface*/
                    decrypt_rotation(cipher_text, i, decryptRotKey);
                    printf("decrypted message using rotation is: %s\n", cipher_text);
                    
                    break;
                }
            case 'c':
                {
                    int i = 0; // same as case 'a'
                    /*The variable initialised below is an array of data type char. It represents the substitution
                    implemented by the user in order to encrypt a chosen message. Since substitution encryption 
                    involves each letter to be changed to another in no particular order, the key must be an array
                    of 26 characters in length, with each letter only appearing once in the key. */
                    char encryptSubKey[26];
                    char message[1000]; //same as case 'a'
                    
                    printf("Enter a key for substitution encryption: ");
                    /*The key for substitution ciphers is a string of characters (also known as an array) and therefore
                    has the format specifier 's'. Since they key should contain no whitespaces, the '[^\n]' is not required. */
                    scanf("%s", encryptSubKey);
                    printf("Enter a message to encrypt using substitution: "); //PLEASE GET MILK AT THE SHOPS
                    scanf(" %[^\n]s", message); // same as case 'a'
                    
                    /*Go to row AHAHAHAHAHA before reading the rest of the code in this case as it is executed AFTER the block of code
                    following the encryptSubstitution function definition*/
                    
                    /*The following two lines of code are executed in the same way as seen in case 'a' */
                    encryptSubstitution(message, i, encryptSubKey);
                    printf("encrypted message is: %s\n", message);
                    
                    break;                
                }
            case 'd':
                {
                    int i = 0; // same as case 'a'
                    /* same as case 'c' except the key is reordered for decryption. For example, if the key used for 
                    substitution encryption was 'QWERTYUIOPASDFGHJKLZXCVBNM', then this key would be re-ordered to be
                    'KXVMCNOPHQRSZYIJADLEGWBUFT for decryption of the previously encrypted message. */
                    char decryptSubKey[26]; 
                    char cipher_text[1000]; //same as case 'b'
                    
                    printf("Enter the key for substitution decryption: ");
                    scanf("%s", decryptSubKey); // same as case 'c', except key now for decryption
                    printf("Enter text to decrypt using substitution: ");
                    scanf(" %[^\n]s", cipher_text); //same principles as case 'b'
                            
                    /*Go to row AHAHAHAHAHA before reading the rest of the code in this case as it is executed 
                    AFTER the block of code following the decryptSubstitution function definition */
                    
                    /*The following two lines of code are executed in the same way as seen in case 'b' */
                    decryptSubstitution(cipher_text, i, decryptSubKey);
                    printf("decrypted message is: %s\n", cipher_text);
                                                                        
                    break;                
                }
            /*If the user types in something other than either a, b, c OR d into the terminal, the following block
            of code will be executed under the default statement and the menu will be reprinted to the terminal */
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
ie if the key = 2, then A becomes C, B becomes D etc.

The return data type for this function is char and its name is 'encrypt_rotation'. 
The first argument for this function is 'message' and it has the data type char. However,
since 'message' is an array, it is not efficient to pass a whole array in a function and therefore, 
a pointer is used. A pointer is the memory address of the array's first element and has the syntax '*'. 
The remaining arguments of this function are not arrays and therefore do not require pointers in 
order to pass variables the function. These two arguments are explained under case 'a' of the above
switch case. */
char encrypt_rotation(char *message, int i, int encryptRotKey)
{
    /*The above function is implemented using a for loop and if loop inside the for loop.
    The function's arguments are passed from the main() function and are used below.
    
    The for loop used, initialises the array index to start at 0. It then states that
    that the array named 'message' cannot have a character that is equal to zero. This is 
    the loop's condition. (the ASCII character who has the corresponding number of 0, is NULL).
    It then specifies that each time the for loop is executed, the index is incremented by 1
    ie the first time the loop is executed, i=1, the second time, i=2 etc, until there index 
    reaches the end of the array. At this point the for loop will exit as message[i] = 0.
    
    The if loop is used to execute the rotation encryption tasks of this specific function. 
    The only characters that will be encrypted via rotation will be capital letters. Lower case
    letters, symbols and spaces will simply be reprinted to the terminal by the else statement of 
    the if loop. */
    for(i = 0; message[i] !=0; i ++)
       {
           
           if (message[i] > 64 && message[i] < 91)
           {
           /*The conditions for this if statement to be executed is that the specific variable of the
           array named 'message' must have a corresponding ASCII number that is greater than 64 but also 
           less than 91. Therefore only encrypting capital letters.
           
           The following equation takes the given variable of the array and assigns it a new ASCII character.
           Specifically, it does this by first sets the letter to an ASCII character between 0 and 25 by minusing
           65. The chosen key for rotation is added. Then the modulus of 26 is taken to prevent characters being 
           encrypted into ASCII characters that are not capital letters. To then re-assign the character to an ASCII 
           capital letter, 65 is added. 
           */
                message[i] = ((message[i] - 65) + encryptRotKey) %26 + 65;
           }
           
           else 
           {
               
           }
    
         
    }
    /*The following statement takes each variable of the array 'message' that was assigned a new ASCII character
    and returns it the main() function. Go to row 132.*/
    return message[i]; 
  } 
  
 
 
  /* The following is the function defintion for the function (when called using the switch
    case) that will take the user's previously encrypted message and selected key (a number between 0 and 26) to 
    decrypt the message using the rotation cipher. The "key" is the number of letters by which 
    the alphabet is shifted (in the opposite direction to encryption) when calculating what letter 
    will be changed to what letter. ie if the key = 2, then C becomes A, D becomes B etc.
    
    The return data type for this function is char and its name is 'decrypt_rotation'. 
    The first argument for this function is 'message' and it has the data type char. However,
    since 'message' is an array, it is not efficient to pass a whole array in a function and therefore, 
    a pointer is used. A pointer is the memory address of the array's first element and has the syntax '*'. 
    The remaining arguments of this function are not arrays and therefore do not require pointers in 
    order to pass variables the function. These two arguments are explained under case 'a' of the above
    switch case. */
  
  char decrypt_rotation(char *cipher_text, int i, int decryptRotKey)
  {
      /*The above function is implemented using a for loop and if loop inside the for loop.
      The function's arguments are passed from the main() function and are used below.
    
      The for loop used, initialises the array index to start at 0. It then states that
      that the array named 'message' cannot have a character that is equal to zero. This is 
      the loop's condition. (the ASCII character who has the corresponding number of 0, is NULL).
      It then specifies that each time the for loop is executed, the index is incremented by 1
      ie the first time the loop is executed, i=1, the second time, i=2 etc, until there index 
      reaches the end of the array. At this point the for loop will exit as message[i] = 0.
    
      The if loop is used to execute the rotation encryption tasks of this specific function. 
      The only characters that will be encrypted via rotation will be capital letters. Lower case
      letters, symbols and spaces will simply be reprinted to the terminal by the else statement of 
      the if loop. */
      for(i = 0; cipher_text[i] != 0; i ++)
      {
          if (cipher_text[i] > 64 && cipher_text[i] < 91)
          {
           /*The conditions for this if statement to be executed is that the specific variable of the
           array named 'message' must have a corresponding ASCII number that is greater than 64 but also 
           less than 91. Therefore only encrypting capital letters.
           
           The following equation takes the given variable of the array and assigns it a new ASCII character.
           Specifically, it does this by first sets the letter to an ASCII character between 0 and 25 by minusing
           65. The chosen key for rotation is added. Then the modulus of 26 is taken to prevent characters being 
           encrypted into ASCII characters that are not capital letters. To then re-assign the character to an ASCII 
           capital letter, 65 is added. 
           */
                cipher_text[i] = ((cipher_text[i] - 65) - decryptRotKey + 26) %26 + 65;
          }
          else 
          {
              
          }
      }
      /*The following statement takes each variable of the array 'message' that was assigned a new ASCII character
        and returns it the main() function. Go to row 29.*/
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
  
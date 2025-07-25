#include <stdio.h>
#include <stdbool.h>
#include <time.h>

//Manual key insert and manual decryption
void VigenereCipher_ManualKey_ManualDecipher(void);

//Manual key insert and Auot decryption with Key Embedding
void VigenereCipher_ManualKey_AutoDecipher(void);

//Automatic key/Encryption and manual decryption with Key display
void VigenereCipher_AutoKey_ManualDecipher(void);

//Automatic key/Encryption and Auto decryption with Key Embedding
void VigenereCipher_AutoKey_AutoDecipher(void);

int BlumBlumShub(int *a);
void CeaserCipher_ManualKey_ManualDecipher(void);
void CeaserCipher_ManualKey_AutoDecipher(void);
void PassWordGenerator_BBS(void);
int LinearCongurentialGenerator(int *a);
void PassWordGenerator_LCG(void);
//void HillCipher(void); work in progress 

int main(void)
{


    //control variables
    bool menu = true;
    int choice , control_switch,i,Key_type_specifier;

    //loop to run menu
    while(menu)
    {
        //presents choice list to user
        printf("\nPress 1 for Embeded Key Vigenere Cipher");
        printf("\nPress 2 for Manual Key Vigenere Cipher");
        printf("\nPress 3 for PassWord Generator ( Using BlumBlumShub Algorithm)");
        printf("\nPress 4 for PassWord Generator ( Using Linear Congurential Generation Algorithm)");
        printf("\nPress 5 for Ceaser Cipher");
        printf("\nPress 6 for Hill Cipher ** WORK IN PROGRESS , WILL NOT WORK **");
        printf("\nEnter the process you would like to Enter : ");
        scanf("%d",&choice);
        
        //conditions to enter desired Cipher Type
        if(choice == 1)
        {
            //this block is embeded key type , encryption types are - automatic key generator and manual key
            printf("\n\nPress 1 for Automatic Encryption and Automatic Embedder  ");
            printf("\n\nPress 2 for Manual Encryption and Automatic Embedder ");
                        
            //takes user input for cipher type
            scanf("%d",&Key_type_specifier);
            
            //condition to start relevant cipher process
            if(Key_type_specifier == 1)
            {
                VigenereCipher_AutoKey_AutoDecipher();
            }else if(Key_type_specifier == 2)
            {
                VigenereCipher_ManualKey_AutoDecipher();
            }
            
            printf("\nWould you like to go back to the menu (press 1 for back , 2 to exit) : ");
            scanf("%d",&control_switch);
            
            //switch of the loop if user enters 2
            if(control_switch == 2)
            {
                menu = false;
            }

        }else if(choice ==2)
        {

            printf("\n\nPress 1 for Automatic Encryption Key Generated Display ");
            printf("\n\nPress 2 for Manual Encryption  ");
            
            //takes user input for cipher type
            scanf("%d",&Key_type_specifier);
            
            //condition to start relevant cipher process
            if(Key_type_specifier == 1)
            {
                VigenereCipher_AutoKey_ManualDecipher();
            }else if(Key_type_specifier == 2)
            {
                VigenereCipher_ManualKey_ManualDecipher();
            }

            printf("\nWould you like to go back to the menu (press 1 for back , 2 to exit) : ");
            scanf("%d",&control_switch);
            
            //switch of the loop if user enters 2
            if(control_switch == 2)
            {
                menu = false;
            }
        } else if(choice == 3)
        {
            PassWordGenerator_BBS();
            printf("\nWould you like to go back to the menu (press 1 for back , 2 to exit) : ");
            scanf("%d",&control_switch);

            //switch of the loop if user enters 2
            if(control_switch == 2)
            {
                menu = false;
            }

        } else if(choice ==4)
        {
            PassWordGenerator_LCG();
            printf("\nWould you like to go back to the menu (press 1 for back , 2 to exit) : ");
            scanf("%d",&control_switch);

            //switch of the loop if user enters 2
            if(control_switch == 2)
            {
                menu = false;
            }
 
        } else if (choice==5)
        {
            CeaserCipher_ManualKey_AutoDecipher();
            printf("\nWould you like to go back to the menu (press 1 for back , 2 to exit) : ");
            scanf("%d",&control_switch);

            //switch of the loop if user enters 2
            if(control_switch == 2)
            {
                menu = false;
            }
        }else
        {
            printf("\nInvalid Input , transferring control back to main menu");

        }
    }
    return 0;
}

void VigenereCipher_ManualKey_ManualDecipher(void)
{
    printf("\n\n || Manual key insert and manual decryption ||\n\n");
        //Messege input Array
    char plaintext[100];

    //Key for Vigenere Table
    char Key[100] ;

    //support variables
    int i , j ,process;
    char ch;

    //Support variable(for running menu)
    bool control = true;

    //control variable
    int plaintext_end , key_end;
    
    //presents choice for user
    printf("Enter 1 for Encryption and 2 for Decryption : ");
    scanf("%d",&process);

    //clears input buffer
    ch = getchar();
    if(process == 1)
    {
        while(control)
        {
        printf("Enter the messege (Type 'help' for list of valid characters ) :\n");

        //Loop to take input in plaintext[]
        ch=getchar();
        for(i=0;i<100 && ch != '\n';i++)
        {
        plaintext[i] = ch;
        ch=getchar();
        }

        //sets up values for control variable
        plaintext_end = i;
        control = false;

            //check for users input for help
            if(plaintext[0] == 'h' && plaintext[1] == 'e' && plaintext[2] == 'l' && plaintext[3] == 'p' )
            {
                if(i==4)
                {
                    printf("\n! \" # $ %% & ' ( \n) * + , - . / : \n; < = > ? @ [ \\ \n] ^ _ ` { | } ~ ");
                    printf("\n And all alphabets\n\n");
                    control = true;
                }

            }
        }

      printf("\nEnter the key word for Encryption : ");
      //Inputs Key
      for(i=0 , ch = getchar(); i<100 && ch !='\n' ; i++)
      {
        Key[i] = ch;
        ch = getchar();
      }

        //setsup support variable
        key_end = i;

        //encryption process starts
        for(i=0 ; i<plaintext_end ; i++)
        {
           plaintext[i] = ((plaintext[i] - 32) + (Key[ i % key_end] - 32 ))%95;
        }
    
        //displays Encrypted code
        printf("\nYour Encrypted Code is : ");
        for(i=0 ; i<plaintext_end ; i++)
        {
           printf("%c",plaintext[i] + 32);
        }

        
    }else if(process == 2)
    {
        while(control)
        {
        printf("Enter the messege for Decryption (Type 'help' for list of valid characters ) :\n");

        //Loop to take input in plaintext[]
         ch=getchar();
        for(i=0;i<100 && ch != '\n';i++)
        {
        plaintext[i] = ch;
        ch=getchar();
        }

        //sets up values for control variable
        plaintext_end = i;
        control = false;

            //check for users input for help
            if(plaintext[0] == 'h' && plaintext[1] == 'e' && plaintext[2] == 'l' && plaintext[3] == 'p' )
            {
                if(i==4)
                {
                    printf("\n! \" # $ %% & ' ( \n) * + , - . / : \n; < = > ? @ [ \\ \n] ^ _ ` { | } ~ ");
                    printf("\n And all alphabets\n\n");
                    control = true;
                }

            }
        }

      printf("\nEnter the key word for Decryption : ");
      //Inputs Key
      for(i=0 , ch = getchar(); i<100 && ch !='\n' ; i++)
      {
        Key[i] = ch;
        ch = getchar();
      }

        //setsup support variable
        key_end = i;

        //decryption process starts
        for(i=0 ; i<plaintext_end ; i++)
        {
           plaintext[i] = ((plaintext[i] - 32) - (Key[ i % key_end] - 32 ) +95)%95;
        }
    
        //displays Decrypted code
        printf("\nYour Decrypted code is : ");
        for(i=0 ; i<plaintext_end ; i++)
        {
           printf("%c",plaintext[i] + 32);
        }

      
    }
    
}

void VigenereCipher_ManualKey_AutoDecipher(void)
{
    printf("\n\n|| Manual key insert and Auot decryption with Key Embedding ||\n\n");
    //Messege input Array
    char plaintext[100];

    //Key for Vigenere Table
    char Key[100] ;

    //support variables
    int i , j ,process;
    char ch;

    //Support variable(for running menu)
    bool control = true;

    //control variable
    int plaintext_end , key_end , key_length , plaintext_lenght;
    
    //presents choice for user
    printf("Enter 1 for Encryption and 2 for Decryption : ");
    scanf("%d",&process);

    //clears input buffer
    ch = getchar();
    if(process == 1)
    {
        printf("\n|| Embedding the decryption key in messege is risky and may reduce security || \n\n ");
        while(control)
        {
        printf("Enter the messege of less than 80 words\n(Type 'help' for list of valid characters ) :\n");

        //Loop to take input in plaintext[]
        ch=getchar();
        for(i=0;i<100 && ch != '\n';i++)
        {
        plaintext[i] = ch;
        ch=getchar();
        }

        //sets up values for control variable
        plaintext_end = i;
        control = false;

            //check for users input for help
            if(plaintext[0] == 'h' && plaintext[1] == 'e' && plaintext[2] == 'l' && plaintext[3] == 'p' )
            {
                if(i==4)
                {
                    printf("\n! \" # $ %% & ' ( \n) * + , - . / : \n; < = > ? @ [ \\ \n] ^ _ ` { | } ~ ");
                    printf("\n And all alphabets\n\n");
                    control = true;
                }

            }
        }

      printf("\nEnter the key word for Encryption ( lenght should be less than 20 characters) : ");
      //Inputs Key
      for(i=0 , ch = getchar(); i<100 && ch !='\n' ; i++)
      {
        Key[i] = ch;
        ch = getchar();
      }

        //setsup support variable
        key_end = i;

        //encryption process starts
        for(i=0 ; i<plaintext_end ; i++)
        {
           plaintext[i] = ((plaintext[i] - 32) + (Key[ i % key_end] - 32 ))%95;
        }

        
        //displays Encrypted code
        printf("\nYour Encrypted Code is : ");
        printf("%c",key_end+32);
        for(i=0 ; i<plaintext_end ; i++)
        {
           printf("%c",plaintext[i] + 32);
        }

        //embedes the decryption key(in somewhat hidden form) for automatic decryption
        for(i=0 ; i<key_end ; i++)
        {
           printf("%c",Key[i]+1);
        }

        
    }else if(process == 2)
    {
        while(control)
        {
        printf("Enter the messege for Decryption (Type 'help' for list of valid characters ) :\n");

        //Loop to take input in plaintext[]
         ch=getchar();
        for(i=0;i<100 && ch != '\n';i++)
        {
        plaintext[i] = ch;
        ch=getchar();
        }

        //sets up values for control variable
        plaintext_end = i;
        control = false;

            //check for users input for help
            if(plaintext[0] == 'h' && plaintext[1] == 'e' && plaintext[2] == 'l' && plaintext[3] == 'p' )
            {
                if(i==4)
                {
                    printf("\n! \" # $ %% & ' ( \n) * + , - . / : \n; < = > ? @ [ \\ \n] ^ _ ` { | } ~ ");
                    printf("\n And all alphabets\n\n");
                    control = true;
                }

            }
        }

        //sets the length of key and support variable
        key_length = plaintext[0]-32;
        key_end = key_length;
        plaintext_lenght = plaintext_end;

        //sets up the key 
        for(i=0;i<key_end;i++)
        {
            Key[key_length - 1 -i ] = (plaintext[plaintext_lenght - 1 - i]-1);
        }
      

        //setsup support variable
        key_end = i;

        //decryption process starts
        for(i=0 ; i<(plaintext_end -1 -key_length) ; i++)
        {
           plaintext[i+1] = ((plaintext[i+1] - 32) - (Key[ i % key_end] - 32 ) +95)%95;
        }
    
        //displays Decrypted code
        printf("\nYour Decrypted code is : ");
        for(i=0 ; i<(plaintext_end -1 -key_length)  ; i++)
        {
           printf("%c",plaintext[i+1] + 32);
        }

      
    }
  
}

void PassWordGenerator_BBS(void)
{
  
    //control variable
    int i;
    
    //sets up seed for CSePRNG
    int time_seed = time(NULL);
    
    printf("\n Random PassWord ( CryptoGraphically Secure ) : ");

    //loop to generate Random Numbers
    for(i=0;i<20;i++)
    {
        printf("%c",(((BlumBlumShub(&time_seed))%95+95)%95)+32);
    }
    printf("\n");
}

int BlumBlumShub(int *seed)
{
    //BlumBlumShub works by Xn+1 = (Xn)^2 % N , N = product of 2 large primes
    int a = 5209, b = 5197;
    int N = a*b;
    //sets up inital state 
    static int state = 37;
    
    //transfers seed to state
    if(*seed !=0)
    {
        state = *seed;
        *seed = 0; //prevents seed for overwriting state in subsequent calls
    }

    //applies BBS formula
    state = (state*state)%N;
    return state;
}

void PassWordGenerator_LCG(void)
{
    //control variable
    int i;

    //sets up seed for PRNG
    int time_seed = time(NULL);  

    printf("\nYour Random Number( CryptoGraphically *INSECURE* ):  ");
    //loop to generate Random Numbers
    for(i = 0; i < 20; i++)
    {
        printf("%c", (((LinearCongurentialGenerator(&time_seed)) % 95 + 95) % 95)+32);
    }
    printf("\n");

}

int LinearCongurentialGenerator(int *seed)
{
    //Sets up constants for LCG formula , LCG formula is Xn+1 = (a*Xn + c)%m
    int a = 1664525, c = 101390422, m = 429496729;  

    //sets up inital state
    static int state = 37;  
    
    //loop to initialize seed as state
    if (*seed != 0)
    {
        state = *seed;  
        *seed = 0; //prevents seed for overwriting state in subsequent calls
    }

    //LCG formula is Xn+1 = (a*Xn + c)%m
    state = (a * state + c) % m;

    return state;
}

void VigenereCipher_AutoKey_AutoDecipher(void)
{
    printf("\n\n|| Automatic key/Encryption and Auto decryption with Key Embedding || \n\n");
        //Messege input Array
    char plaintext[100];

    //Key for Vigenere Table
    char Key[100] ;

    //support variables
    int i , j ,process;
    char ch;

    //Support variable(for running menu)
    bool control = true;

    //control variable
    int plaintext_end , key_end , key_length , plaintext_lenght;
    
    //presents choice for user
    printf("Enter 1 for Encryption and 2 for Decryption : ");
    scanf("%d",&process);

    //clears input buffer
    ch = getchar();
    if(process == 1)
    {
        printf("\n|| Embedding the decryption key in messege is risky and may reduce security || \n\n ");
        while(control)
        {
        printf("Enter the messege of less than 80 words\n(Type 'help' for list of valid characters ) :\n");

        //Loop to take input in plaintext[]
        ch=getchar();
        for(i=0;i<100 && ch != '\n';i++)
        {
        plaintext[i] = ch;
        ch=getchar();
        }

        //sets up values for control variable
        plaintext_end = i;
        control = false;

            //check for users input for help
            if(plaintext[0] == 'h' && plaintext[1] == 'e' && plaintext[2] == 'l' && plaintext[3] == 'p' )
            {
                if(i==4)
                {
                    printf("\n! \" # $ %% & ' ( \n) * + , - . / : \n; < = > ? @ [ \\ \n] ^ _ ` { | } ~ ");
                    printf("\n And all alphabets\n\n");
                    control = true;
                }

            }
        }


      //Inputs Key and sets up seed
      int time_seed = time(NULL);
      for(i=0 ;i<20 ; i++)
      {
        Key[i] = ((((BlumBlumShub(&time_seed)%95)+95)%95)+32);
      }

        //setsup support variable
        key_end = i;

        //encryption process starts
        for(i=0 ; i<plaintext_end ; i++)
        {
           plaintext[i] = ((plaintext[i] - 32) + (Key[ i % key_end] - 32 ))%95;
        }

        
        //displays Encrypted code
        printf("\nYour Encrypted Code is : ");
        printf("%c",key_end+32);
        for(i=0 ; i<plaintext_end ; i++)
        {
           printf("%c",plaintext[i] + 32);
        }

        //embedes the decryption key(in somewhat hidden form) for automatic decryption
        for(i=0 ; i<key_end ; i++)
        {
           printf("%c",Key[i]);
        }

        
    }else if(process == 2)
    {
        while(control)
        {
        printf("Enter the messege for Decryption (Type 'help' for list of valid characters ) :\n");

        //Loop to take input in plaintext[]
         ch=getchar();
        for(i=0;i<100 && ch != '\n';i++)
        {
        plaintext[i] = ch;
        ch=getchar();
        }

        //sets up values for control variable
        plaintext_end = i;
        control = false;

            //check for users input for help
            if(plaintext[0] == 'h' && plaintext[1] == 'e' && plaintext[2] == 'l' && plaintext[3] == 'p' )
            {
                if(i==4)
                {
                    printf("\n! \" # $ %% & ' ( \n) * + , - . / : \n; < = > ? @ [ \\ \n] ^ _ ` { | } ~ ");
                    printf("\n And all alphabets\n\n");
                    control = true;
                }

            }
        }

        //sets the length of key and support variable
        key_length = plaintext[0]-32;
        key_end = key_length;
        plaintext_lenght = plaintext_end;

        //sets up the key 
        for(i=0;i<key_end;i++)
        {
            Key[key_length - 1 -i ] = (plaintext[plaintext_lenght - 1 - i]);
        }
      

        //setsup support variable
        key_end = i;

        //decryption process starts
        for(i=0 ; i<(plaintext_end -1 -key_length) ; i++)
        {
           plaintext[i+1] = ((plaintext[i+1] - 32) - (Key[ i % key_end] - 32 ) +95)%95;
        }
    
        //displays Decrypted code
        printf("\nYour Decrypted code is : ");
        for(i=0 ; i<(plaintext_end -1 -key_length)  ; i++)
        {
           printf("%c",plaintext[i+1] + 32);
        }

      
    }

}

void VigenereCipher_AutoKey_ManualDecipher(void)
{
    printf("\n\n|| Automatic key/Encryption and manual decryption with Key display ||\n\n");
        //Messege input Array
    char plaintext[100];

    //Key for Vigenere Table
    char Key[100] ;

    //support variables
    int i , j ,process;
    char ch;

    //Support variable(for running menu)
    bool control = true;

    //control variable
    int plaintext_end , key_end;
    
    //presents choice for user
    printf("Enter 1 for Encryption and 2 for Decryption : ");
    scanf("%d",&process);

    //clears input buffer
    ch = getchar();
    if(process == 1)
    {
        while(control)
        {
        printf("Enter the messege (Type 'help' for list of valid characters ) :\n");

        //Loop to take input in plaintext[]
        ch=getchar();
        for(i=0;i<100 && ch != '\n';i++)
        {
        plaintext[i] = ch;
        ch=getchar();
        }

        //sets up values for control variable
        plaintext_end = i;
        control = false;

            //check for users input for help
            if(plaintext[0] == 'h' && plaintext[1] == 'e' && plaintext[2] == 'l' && plaintext[3] == 'p' )
            {
                if(i==4)
                {
                    printf("\n! \" # $ %% & ' ( \n) * + , - . / : \n; < = > ? @ [ \\ \n] ^ _ ` { | } ~ ");
                    printf("\n And all alphabets\n\n");
                    control = true;
                }

            }
        }

      //Inputs Key and sets up seed
      int time_seed = time(NULL);
      for(i=0 ;i<20 ; i++)
      {
        Key[i] = ((((BlumBlumShub(&time_seed)%95)+95)%95)+32);
      }

        //setsup support variable
        key_end = i;

        //encryption process starts
        for(i=0 ; i<plaintext_end ; i++)
        {
           plaintext[i] = ((plaintext[i] - 32) + (Key[ i % key_end] - 32 ))%95;
        }
    
        //displays Encrypted code
        printf("\n\nYour Encrypted Code is : ");
        for(i=0 ; i<plaintext_end ; i++)
        {
           printf("%c",plaintext[i] + 32);
        }
       
        //displays key generated
        printf("\n\nThe Key generated is : ");
        for(i=0 ; i<20 ; i++)
        {
           printf("%c",Key[i]);
        }


        
    }else if(process == 2)
    {
        while(control)
        {
        printf("Enter the messege for Decryption (Type 'help' for list of valid characters ) :\n");

        //Loop to take input in plaintext[]
         ch=getchar();
        for(i=0;i<100 && ch != '\n';i++)
        {
        plaintext[i] = ch;
        ch=getchar();
        }

        //sets up values for control variable
        plaintext_end = i;
        control = false;

            //check for users input for help
            if(plaintext[0] == 'h' && plaintext[1] == 'e' && plaintext[2] == 'l' && plaintext[3] == 'p' )
            {
                if(i==4)
                {
                    printf("\n! \" # $ %% & ' ( \n) * + , - . / : \n; < = > ? @ [ \\ \n] ^ _ ` { | } ~ ");
                    printf("\n And all alphabets\n\n");
                    control = true;
                }

            }
        }

      printf("\nEnter the key word for Decryption : ");
      //Inputs Key
      for(i=0 , ch = getchar(); i<100 && ch !='\n' ; i++)
      {
        Key[i] = ch;
        ch = getchar();
      }

        //setsup support variable
        key_end = i;

        //decryption process starts
        for(i=0 ; i<plaintext_end ; i++)
        {
           plaintext[i] = ((plaintext[i] - 32) - (Key[ i % key_end] - 32 ) +95)%95;
        }
    
        //displays Decrypted code
        printf("\nYour Decrypted code is : ");
        for(i=0 ; i<plaintext_end ; i++)
        {
           printf("%c",plaintext[i] + 32);
        }

      
    }

}

void CeaserCipher_ManualKey_AutoDecipher(void)
{
    printf("\n\n || * CEASER CIPHER IS AN EXTREMELY WEAK CIPHER ( proceed at your own risk) * ||\n\n");
        char ch[80] ; int shift , i,j,choise; 
    printf("Enter 1 for Encryption and 2 for Decryption : ");
    scanf("%d",&choise);
    ch[0] = getchar();
    //Encryption 
    if(choise==1)
    {
         printf("\nEnter the code to be encrypted : ");
    for(i=0;i<80;i++)
    {
        ch[i] = getchar();
        if(ch[i]=='\n')
        {
            break;
        }
    }
    printf("\nEnter the shift amount(1-25 only) : ");
    scanf("%d",&shift);
    printf("\nEncrypted Code : ");
    for(i=0;i<80;i++)
    {
        if(ch[i]=='\n')
        {
            break;
        } else if(ch[i]>='a' && ch[i]<='z')
        {
            ch[i] = (ch[i] -'a' +shift)%26 +'a';
        }else if(ch[i]>='A' && ch[i]<='Z')
        {
            ch[i] = (ch[i] -'A' +shift)%26 +'A';
        }
    }
    for(i=0;i<80;i++)
    {
        if(ch[i]=='\n')
        {
            break;
        }
        printf("%c",ch[i]);
    }
    printf("%d",shift);
    } else if(choise==2)  //Decryption 
    {
         printf("\nEnter the code to be Decypted : ");
    for(i=0;i<80;i++)
    {
        ch[i] = getchar();
        if(ch[i]=='\n')
        {
            break;
        }
    }
    for(i -=1,j=1,shift=0;;i--,j*=10)
    {
        if(ch[i]<='9'&&ch[i]>='0') 
        {
                       shift += (ch[i] - 48)*j;
        } else
        {
            ch[i+1]='\n';
            break;
        } 

    }
    printf("\nDecrypted Code : ");
    for(i=0;i<80;i++)
    {
        if(ch[i]=='\n')
        {
            break;
        } else if(ch[i]>='a' && ch[i]<='z')
        {
            ch[i] = (ch[i] -'a' + 26 - shift)%26 +'a';
        }else if(ch[i]>='A' && ch[i]<='Z')
        {
            ch[i] = (ch[i] -'A' + 26 - shift)%26 +'A';
        }
    }
    for(i=0;i<80;i++)
    {
        if(ch[i]=='\n')
        {
            break;
        }
        printf("%c",ch[i]);
    }
    }
   
}

/*

  //Encrypt/Decrypted text
    char plaintext[100]  ;  

    // input looping charater 
    char ch; 

    // keys for the process 
    int CipherKey[3][3] , DecipherKey[3][3];

    //loop running variables and support variables 
    int i ,j,det;
    int invDet;
    int EncryptStop;  // indicates when to stop the incription process ; 

    //messege input
    printf("Enter the messege for encryption : ");
    for(i=0,ch=getchar() ; ch!='\n' ; i++)
    {
        plaintext[i] = ch;
        ch = getchar();
    }  

    EncryptStop = i; // stores the element number where encryption prcocess stops 

    //supplies extra space 
    for(;EncryptStop%3 != 0 ;EncryptStop++)
    {
        plaintext[EncryptStop] = ' ';
    }

    //Encryption Key input 
    printf("\nEnter the 3X3 matrix as the key for Encryption");
    printf("\n(key values must be integer between 1-50 and enter 1 by 1)");
    for(i=0; i<3 ;i++)
    {
        for(j=0; j<3 ; j++)
        {
            printf("\nEnter the %dX%dth element : ",i+1,j+1);
            scanf("%d",&CipherKey[i][j]);
        }
    }

    //Calculation of Inverse Key
        //calculates determniant of CipherKey
        det =0;
        det += (CipherKey[0][0]*CipherKey[1][1]*CipherKey[2][2] );
        det += (CipherKey[1][0]*CipherKey[2][1]*CipherKey[0][2] );
        det += (CipherKey[2][0]*CipherKey[0][1]*CipherKey[1][2] );
        det -= (CipherKey[2][0]*CipherKey[1][1]*CipherKey[0][2] );
        det -= (CipherKey[1][0]*CipherKey[0][1]*CipherKey[2][2] );
        det -= (CipherKey[0][0]*CipherKey[2][1]*CipherKey[1][2] );

    // Calculate the modular inverse of det modulo 95
        invDet = modInverse(det, 95);
        printf("\ninv - det %d\n det - %d",invDet,det);
    
    //manually sets inverse Key 
    //didn't have the time to design a looping formula for inverse so just brute forced it 
    DecipherKey[0][0] = ((invDet * (CipherKey[1][1] * CipherKey[2][2] - CipherKey[1][2] * CipherKey[2][1]))%95  + 95) % 95;
    DecipherKey[0][1] = ((invDet * (CipherKey[0][2] * CipherKey[2][1] - CipherKey[0][1] * CipherKey[2][2]))%95  + 95) % 95;
    DecipherKey[0][2] = ((invDet * (CipherKey[0][1] * CipherKey[1][2] - CipherKey[0][2] * CipherKey[1][1]))%95  + 95) % 95;

    DecipherKey[1][0] = ((invDet * (CipherKey[1][2] * CipherKey[2][0] - CipherKey[1][0] * CipherKey[2][2]))%95  + 95) % 95;
    DecipherKey[1][1] = ((invDet * (CipherKey[0][0] * CipherKey[2][2] - CipherKey[0][2] * CipherKey[2][0]))%95  + 95) % 95;
    DecipherKey[1][2] = ((invDet * (CipherKey[0][2] * CipherKey[1][0] - CipherKey[0][0] * CipherKey[1][2]))%95  + 95) % 95;

    DecipherKey[2][0] = ((invDet * (CipherKey[1][0] * CipherKey[2][1] - CipherKey[1][1] * CipherKey[2][0]))%95  + 95) % 95;
    DecipherKey[2][1] = ((invDet * (CipherKey[0][1] * CipherKey[2][0] - CipherKey[0][0] * CipherKey[2][1]))%95  + 95) % 95;
    DecipherKey[2][2] = ((invDet * (CipherKey[0][0] * CipherKey[1][1] - CipherKey[0][1] * CipherKey[1][0]))%95  + 95) % 95;

printf("\n") ;//temp line

        //temp loop to check key 
        for(i=0; i<3 ;i++)
    {
        for(j=0; j<3 ; j++)
        {
            printf("%d ",CipherKey[i][j]);
        }
        printf("\n");
    }

        printf("\n") ;//temp line

    //Encryption process starts 
    for(i=0; i < EncryptStop ; i++)
    {
        printf("%d",plaintext[i]); //temp
        if(i%3==0)
        {
           plaintext[i] = (((((plaintext[i]-' ')*CipherKey[0][0]) + ((plaintext[i+1]-' ')*CipherKey[1][0]) + ((plaintext[i+2]-' ')*CipherKey[2][0]))%95)+95)%95;
        } else if (i%3==1)
        {
           plaintext[i] = (((((plaintext[i-1]-' ')*CipherKey[0][1]) + ((plaintext[i]-' ')*CipherKey[1][1]) + ((plaintext[i+1]-' ')*CipherKey[2][1]))%95)+95)%95;
        } else
        {
           plaintext[i] = (((((plaintext[i-2]-' ')*CipherKey[0][2]) + ((plaintext[i-1]-' ')*CipherKey[1][2]) + ((plaintext[i]-' ')*CipherKey[2][2]))%95)+95)%95;
        }
         printf(" Encrypted value: %d \n", plaintext[i]);//temp
    }
    
    //prints the encrypted code with the Decryption key embedded in the back

    printf("\nEncrypted code : ");
    for(i=0;i<EncryptStop;i++)
    {
        printf("%d ",plaintext[i]);
    }
    //displays key
    printf("\nkey(int) : ");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",DecipherKey[i][j] );
        }
    }
    printf("\nkey int + 32 :  ");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",DecipherKey[i][j] + ' ');
        }
    }
    printf("\nkey char : ");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%c ",DecipherKey[i][j] );
        }
    }
    printf("\nkey char + 32 : ");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%c ",DecipherKey[i][j] + ' ');
        }
    }
    return 0;
}

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    
    if (m == 1) return 0;
    
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    
    if (x1 < 0) x1 += m0;
    
    return x1;
}
*/
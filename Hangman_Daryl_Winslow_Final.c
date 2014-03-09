/* Hangman Program 04/11/2012 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // to exit program gracefully


#define WORD 8
#define LETTERS 26

main()
{
    /*Intro Graphic*/
    printf("--------------------------------------------\n");
    printf("| #  #   #   #   #  #### #   #   #   #   # |\n");
    printf("| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
    printf("| #### ##### # # # #  ## # # # ##### # # # |\n");
    printf("| #  # #   # #  ## #   # #   # #   # #  ## |\n");
    printf("| #  # #   # #   #  ###  #   # #   # #   # |\n");
    printf("|-----------Irish Rebel Edition------------|\n");
    printf("-------------By Daryl Winslow---------------\n\n");
    
    /* Word list */
    int i; //index
    char republic[WORD] = {'r', 'e', 'p', 'u', 'b', 'l', 'i', 'c'};
    char imperial[WORD] = {'i', 'm', 'p', 'e', 'r', 'i', 'a', 'l'};
    char invasion[WORD] = {'i', 'n', 'v', 'a', 's', 'i', 'o', 'n'};
    char catholic[WORD] = {'c', 'a', 't', 'h', 'o', 'l', 'i', 'c'};
    char property[WORD] = {'p', 'r', 'o', 'p', 'e', 'r', 't', 'y'};
    
    char wordchosen[WORD]; //word to be guessed
    int count=5;//for loops
    int start=2;//for starting game
    
    /*Game Introduction*/
    printf("WELCOME TO HANGMAN!!!\n");
    printf("\nThe year is 1798. Your name is Theobald Wolfe Tone.\nYou have been convicted by the Royal Crown Court of the following crimes:");
    printf("\nStealing a pen;\nTalking loudly outside a church;\nBeing a leader of The United Irishmen Rebellion.\n");
    printf("\nI am your executioner.\n");
    printf("\nBizarrley, Lord Kilwarden has decided that if you correctly\nguess the word he has written down on this piece of paper then\nyou shall be acquitted of all your crimes.\n");
    printf("\nIf you fail to guess the word after 6 incorrect guesses...\nYou will be HANGED until you are DEAD!\n");
    
    /*To Start the game*/
    while (count==5)
    {
        printf("\nIs this OK with you?\nEnter 0 to quit\nEnter 1 to play\n");
        scanf("%d", &start);
        /*flushall();*/
        
        if (start==0)
        {
            printf("\nYOU SHALL BE STRUNG UP AT DAWN!!! Unless you attempt to take your own life\nwith a rusty blade and die from your wounds several days later... *cough cough*\n\n\nGoodbye!!!");
            Sleep(6000);
            return 0; //leaves program
        }
       
        if (start==1)
        {
            printf("\nAs Louis Lazare Hoche once said....LET'S DO THIS!!!\n");
            Sleep(2000);
            count=0; //to enter main game loop
            system ("cls"); //clears game intro from screen
        }
        
        else if (start != 1 || start != 0) //error checking
        {
            printf("\nI'm afraid I don't understand your input.\nHit Enter to continue\n");
            getchar();
        }
    }
   
    /*Main game loop*/
    while (count==0) 
   {
        int r; // for random number
        srand(time(NULL)); //random number generator
        r=rand() % 5 +1;
    
   
        /*Assigning words to random number*/
        for (i=0; i<WORD; i++)
        {
            if(r==1)
            {
                wordchosen[i]=republic[i];
            }
            if(r==2)
            {
                wordchosen[i]=imperial[i];
            }
            if(r==3)
            {
                wordchosen[i]=invasion[i];
            }
            if(r==4)
            {
                wordchosen[i]=catholic[i];
            }
            if(r==5)
            {
                wordchosen[i]=property[i];
            }
                
                
        }
            
        
              
        /*Variables*/
        char word[15]="_ _ _ _ _ _ _ _";//blank spaces
        char letters[LETTERS];
        int lives;
            lives=6; //number of wrong guesses allowed
        char guess;
        int k;
        int win; //to stop game if won
            win=0;
        char play; //to play again
        count=1;
                
            do 
            {
                while (count==1)
                {
                    /* User interface */
                    printf("\nGUESS FOR YOUR LIFE!!!\n");
                    printf("\nYou have %d incorrect guesses remaining\n", lives); //Amount of lives remaining
                    printf("\nPlease guess a letter and hit enter to try and complete the word\n");
                    scanf("%c", &guess);
                    /*flushall();*/
                    
                    
                    k=0;
                    
                    for (i=0; i<WORD; i++)
                        {
                            if(guess==wordchosen[i])
                            {
                                printf("\nCorrect\n");
                                word[i * 2]=guess;
                                win++;
                            }
            
                            
                            else if (guess!= wordchosen[i])
                            {
                                
                                k++;
                            }
                        }
                        
                        if(k>=WORD)
                            {
                                printf("\nIncorrect\n");
                                lives--; //taking away lives
                            }
                        printf("\n");
                            
                    /*Filling in the blanks*/
                    for (i=0;i<15;i++)
                        {
                            printf("%c", word[i]);
                        }      
                        printf("\n");
                        
                    if (win==8) //win
                    {
                        printf("\nYOU WON! You're a free man!!!\n");
                        count=3;
                    }
                    
                    if (lives==0) //lose
                    {
                        printf("\nYOU LOSE! You're totally getting hanged man!!!\nYou won't be starting rebellions and raising hell where you're going....HELL!!!\n");
                        printf("  _______\n");
                        printf("  |/   | \n");
                        printf("  |    X \n");
                        printf("  |   \\|/\n");
                        printf("  |    | \n");
                        printf("  |   / \\\n");
                        printf("__|_________\n\n");
                        count=3;
                    }
                    
                    /*New game or quit?*/
                    while (count==3)
                    {
                        printf("\nWell that was fun!\nWould you like to play again?\n\n");
                        printf("\ny/n?\n");
                        scanf("%c", &play);
                        /*flushall();*/
                        
                            if (play== 'y' || play== 'Y')
                            {
                                count = 0;
                                if (lives==0) //message for loser
                                {
                                    printf("\nYou've been resurrected!!! GOOD FOR YOU!!!\n");
                                    Sleep(4000);
                                }
                                if (lives>0) //message for winner
                                {
                                    printf("\nDo you have a deathwish? YOU'RE A MADMAN WOLFEY!!!\nOK then, step back onto the gallows and\nI'll get a new word to guess from Lord Kilwarden\n");
                                    Sleep(4000);
                                }
                                system ("cls"); //clears screen for new game
                            }
                            
                            if (play== 'n' || play=='N')
                            {
                                if (lives==0) //message for loser
                                {
                                printf("\nOf course you don't....YOU'RE DEAD!!!\n\n\nGoodbye!!!");
                                }
                                if (lives>0) //message for winner
                                {
                                printf("\nThanks for playing.\n");
                                printf("\nWhat will you do now Theobald?\nContinue to fight for a free Ireland?\nStart a band?\nPerhaps start a comedy rap band called Flight of the Earls?\n");
                                printf("The world is your oyster Wolfey!\n\n\nGoodbye!!!\n");
                                }
                                Sleep(7000);
                                return 0; //exits program
                            }

                            
                            if (lives==0) //for resetting lives to play again
                            {
                                lives=6;
                            }
                    }   
                }
                        
                
            }while (count==1);
    }//end of main game loop
        

   
}//end main

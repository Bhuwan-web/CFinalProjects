#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
struct hangman
{
    char word[20];
    char hint[100];
};
int CHANCES=10;
void after_game();
int game(char *hang_word,char *hang_hint,int len,char userAns[20],char letter);
int main(){
    srand(time(0));
    char letter;
    char userAns[20];

    //MAINTAINABLE SECTION................
    struct hangman words[20]={
        {"hello","english greeting"},
        {"world","The place where we live"},
        {"summer"," one of season"},
        {"potato","Everyday Vegitable"},
        {"bhuwan","programmer of this game"}
    };
    const int WORDS=5;
    // .................................................


    //GAME ENGINE
    const int NUMBER=rand()%WORDS;
    char *hang_word =words[NUMBER].word;
    char *hang_hint=words[NUMBER].hint;
    int len=strlen(hang_word);
    for(int i=0;i<len;i++){
        userAns[i]='_';
    }
    // STARTING A GAME
    game(hang_word,hang_hint,len,userAns,letter);

}

int game(char *hang_word,char *hang_hint,int len,char userAns[20],char letter)
{

    for(int play=0;CHANCES>=0;play++){
        fflush(stdin);
        system("clear");
        if(play==0 || letter == '\n'){
            printf("A Hint: %s",hang_hint);
            printf("\n\nChances Left: %d\n\n",CHANCES);
            for(int wordlen=0;wordlen<len;wordlen++){
                printf("%c ",userAns[wordlen]);
            }
        }
        userAns[len]='\0';
        for(int i=0;i<1;i++){
            if(play==0 || letter == '\n'){
                printf("\n\nGuess a word :");
            }
            letter=fgetc(stdin);
        }
        if(letter !='\n'){
            int curr_chance=CHANCES;
        for(int j=0;j<len;j++){
            if(letter == hang_word[j]){
                CHANCES=curr_chance+1;
                userAns[j]=letter;
            }
        }
        if(strcmp(hang_word,userAns)==0){
            system("clear");
            printf("\n\n \tYOU WON!!\n\n");
            after_game();
            
            return 0;
            }
        CHANCES--;
        if(CHANCES==0){
            system("clear");
            printf("You lose the game!!\n\n");
            after_game();
            
        }
        printf("\n");
        }
    }
}
void after_game(){
    int choice;
    printf("Would you like to replay the game:\
    \n1.End \
    \n2.Replay \
    \n");
    scanf("%d",&choice);
    if(choice==2){
        main();
    }
}


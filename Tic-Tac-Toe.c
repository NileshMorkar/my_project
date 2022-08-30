#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void show(char *);
int checkwin(char *);
void input(char *,int *,char);
void ifWin(char *);
int selfWin(char *);
int cheating(char *);
int main()
{
    char mark,name1[20],name2[20];
    int i,player,place,choise;
    while(1)
    {   
        char A[9]={'1','2','3','4','5','6','7','8','9'};
        srand(time(NULL));
        player=1; 
        system("cls");
        system("color 70");
        printf("\nEnter Your choise Number __\n");
        printf("1.Want to Play with SMART COMPUTER\n");
        printf("2.Want to Play with EVIL COMPUTER\n");
        printf("3.Want to play With PLAYER\n");
        printf("4.EXIT\n");
        printf("\n==> ");
        scanf("%d",&choise);
        system("cls");
        fflush(stdin);
        switch (choise)
        {
            case 1:
                system("color 90");
                printf("Enter Your Name ==> ");
                fgets(name1,20,stdin);
                name1[strlen(name1)-1]='\0';
                fflush(stdin);
                strcpy(name2," SMART COMPUTER");
                do 
                {
                    system("color 60");
                    system("cls");
                    printf("\n\t   player {%s} Symbol  : X :\n",name2);
                    printf("\t   player {%s} Symbol  : 0 :",name1);
                    show(A);
                    player=player%2?1:2;
                    if(player==1)
                    {
                      printf("\n\nPlayer {%s} , Enter Your Marking Place ==> ",(player==1?name1:name2));
                      scanf("%d",&place);
                      input(A,&place,'O');
                    }
                    else 
                    {
                      if(selfWin(A))
                        ifWin(A);
                    }
                    if(place==-1)
                        player--;
                    
                    i=checkwin(A);
                    player++;
                }while(i==-1);
                system("cls");
                system("color 50");
                show(A);
                if(i==1)
                {
                    printf("\n==>..!!..!! Player {%s} WON ..!!..!!\n\n",(player-1==1?name1:name2));
                    printf("###########################################\n\n");        
                }
                else
                {
                    printf("\n==>..!!..!! Game Draw ..!!..!!\n\n");
                    printf("###########################################\n\n");
                }
                getch();            
            break;
            case 2:
                system("color 60");
                player=2;
                printf("Enter Your Name ==> ");
                fgets(name1,20,stdin);
                name1[strlen(name1)-1]='\0';
                fflush(stdin);
                strcpy(name2,"SMART EVIL COMPUTER");
                do 
                {
                    system("color 50");
                    system("cls");
                    printf("\n\t   player {%s} Symbol  : X :\n",name2);
                    printf("\t   player {%s} Symbol  : 0 :",name1);
                    show(A);
                    player=player%2?1:2;
                    if(player==1)
                    {
                        printf("\n\nPlayer {%s} , Enter Your Marking Place ==> ",(player==1?name1:name2));
                        scanf("%d",&place);
                        input(A,&place,'O');
                    }
                    else 
                    {
                        if(selfWin(A))
                            ifWin(A);
                        if(cheating(A))
                            ifWin(A);
                    }
                    if(place==-1)
                        player--;
                    
                    i=checkwin(A);
                    player++;
                }while(i==-1);
                system("cls");
                system("color C0");
                show(A);
                if(i==1)
                {
                    printf("\n==>..!!..!! Player {%s} WON ..!!..!!\n\n",(player-1==1?name1:name2));
                    printf("###########################################\n\n");        
                }
                else
                {
                    printf("\n==>..!!..!! Game Draw ..!!..!!\n\n");
                    printf("###########################################\n\n");
                }
                getch();
            break;
            case 3:
                system("color 50");
                fflush(stdin);
                printf("Enter First Player Name ==> ");
                fgets(name1,20,stdin);
                name1[strlen(name1)-1]='\0';
                fflush(stdin);
                printf("Enter Second Player Name ==> ");
                fgets(name2,20,stdin);
                name2[strlen(name2)-1]='\0';
                    
                do 
                {
                    system("cls");
                    system("color 10");
                    printf("\n\t   player {%s} Symbol  : X :\n",name1);
                    printf("\t   player {%s} Symbol  : 0 :",name2);
                    show(A);
                    player=player%2?1:2;
                    printf("\n\nPlayer {%s} , Enter Your Marking Place ==> ",(player==1?name1:name2));
                    scanf("%d",&place);
                    mark=(player==1)?'X':'O';
                    
                    input(A,&place,mark);
                    
                    if(place==-1)
                        player--;
                    
                    i=checkwin(A);
                    player++;
                }while(i==-1);
                system("cls");
                system("color C0");
                show(A);
                if(i==1)
                {
                    printf("\n==>..!!..!! Player {%s} WON ..!!..!!\n\n",(player-1==1?name1:name2));
                    printf("###########################################\n\n");        
                }
                else
                {
                    printf("\n==>..!!..!!  Game Draw ..!!..!!\n\n");
                    printf("###########################################\n\n");
                }
                getch();
            break;
            case 4:exit(0);                        
        }
    }    
    return 0;
}
int cheating(char *A)
{
    int count=0;
    if(((A[0]==A[8] && A[0]=='O')||(A[2]==A[6] && A[2]=='O')||(A[1]==A[7] && A[1]=='O')||(A[3]==A[5]&& A[3]=='O')) && (A[4]!='O'&& A[4]!='X'))
        count++;
    
    if(((A[1]==A[2] && A[1]=='O')||(A[3]==A[6] && A[3]=='O')||(A[4]==A[8] && A[4]=='O')) && (A[0]!='O'&& A[0]!='X'))
        count++;
    
    if(((A[0]==A[2] && A[0]=='O')||(A[4]==A[7] && A[4]=='O')) && (A[1]!='O'&& A[1]!='X'))
        count++;
    
    if(((A[0]==A[1] && A[0]=='O')||(A[6]==A[4] && A[6]=='O')||(A[5]==A[8] && A[5]=='O')) && (A[2]!='O'&& A[2]!='X'))
        count++;
    
    if(((A[0]==A[6] && A[0]=='O')||(A[4]==A[5] && A[4]=='O')) && (A[3]!='O'&& A[3]!='X'))
        count++;
    
    if(((A[2]==A[8] && A[2]=='O')||(A[3]==A[4] && A[3]=='O')) && (A[5]!='O'&& A[5]!='X'))
        count++;
    
    if(((A[0]==A[3] && A[0]=='O')||(A[7]==A[8] && A[7]=='O')||(A[4]==A[2] && A[4]=='O')) && (A[6]!='O'&& A[6]!='X'))
        count++;
    
    if(((A[1]==A[4]) && A[1]=='O'||(A[8]==A[6] && A[8]=='O')) && (A[7]!='O'&& A[7]!='X'))
        count++;
    
    if(((A[5]==A[2] && A[5]=='O')||(A[0]==A[4] && A[0]=='O')||(A[6]==A[7] && A[6]=='O')) && (A[8]!='O'&& A[8]!='X'))
        count++;
    
    return count;
}
int selfWin(char *A)
{
    if(((A[0]==A[8] && A[0]=='X')||(A[2]==A[6] && A[2]=='X')||(A[1]==A[7] && A[1]=='X')||(A[3]==A[5]&& A[3]=='X')) && (A[4]!='O'&& A[4]!='X'))
    {
        A[4]='X';
        return 0;
    }
    else if(((A[1]==A[2] && A[1]=='X')||(A[3]==A[6] && A[3]=='X')||(A[4]==A[8] && A[4]=='X')) && (A[0]!='O'&& A[0]!='X'))
    {
        A[0]='X';
        return 0;
    }
    else if(((A[0]==A[2] && A[0]=='X')||(A[4]==A[7] && A[4]=='X')) && (A[1]!='O'&& A[1]!='X'))
    {
        A[1]='X';
        return 0;
    }
    else if(((A[0]==A[1] && A[0]=='X')||(A[6]==A[4] && A[6]=='X')||(A[5]==A[8] && A[5]=='X')) && (A[2]!='O'&& A[2]!='X'))
    {
        A[2]='X';
        return 0;
    }
    else if(((A[0]==A[6] && A[0]=='X')||(A[4]==A[5] && A[4]=='X')) && (A[3]!='O'&& A[3]!='X'))
    {
        A[3]='X';
        return 0;
    }
    else if(((A[2]==A[8] && A[2]=='X')||(A[3]==A[4] && A[3]=='X')) && (A[5]!='O'&& A[5]!='X'))
    {
        A[5]='X';
        return 0;
    }
    else if(((A[0]==A[3] && A[0]=='X')||(A[7]==A[8] && A[7]=='X')||(A[4]==A[2] && A[4]=='X')) && (A[6]!='O'&& A[6]!='X'))
    {
        A[6]='X';
        return 0;
    }
    else if(((A[1]==A[4]) && A[1]=='X'||(A[8]==A[6] && A[8]=='X')) && (A[7]!='O'&& A[7]!='X'))
    {
        A[7]='X';
        return 0;
    }
    else if(((A[5]==A[2] && A[5]=='X')||(A[0]==A[4] && A[0]=='X')||(A[6]==A[7] && A[6]=='X')) && (A[8]!='O'&& A[8]!='X'))
    {
        A[8]='X';
        return 0;
    }
    else
    {
        return 1;
    }
}
void ifWin(char *A)
{
    int place;
    if((A[0]==A[8]||A[2]==A[6]||A[1]==A[7]||A[3]==A[5]) && (A[4]!='O'&& A[4]!='X'))
    {
        A[4]='X';
    }
    else if((A[1]==A[2]||A[3]==A[6]||A[4]==A[8]) && (A[0]!='O'&& A[0]!='X'))
    {
        A[0]='X';
    }
    else if((A[0]==A[2]||A[4]==A[7]) && (A[1]!='O'&& A[1]!='X'))
    {
        A[1]='X';
    }
    else if((A[0]==A[1]||A[6]==A[4]||A[5]==A[8]) && (A[2]!='O'&& A[2]!='X'))
    {
        A[2]='X';
    }
    else if((A[0]==A[6]||A[4]==A[5]) && (A[3]!='O'&& A[3]!='X'))
    {
        A[3]='X';
    }
    else if((A[2]==A[8]||A[3]==A[4]) && (A[5]!='O'&& A[5]!='X'))
    {
        A[5]='X';
    }
    else if((A[0]==A[3]||A[7]==A[8]||A[4]==A[2]) && (A[6]!='O'&& A[6]!='X'))
    {
        A[6]='X';
    }
    else if((A[1]==A[4]||A[8]==A[6]) && (A[7]!='O'&& A[7]!='X'))
    {
        A[7]='X';
    }
    else if((A[5]==A[2]||A[0]==A[4]||A[6]==A[7]) && (A[8]!='O'&& A[8]!='X'))
    {
        A[8]='X';
    }
    else
    {
        while(1)
        {
            place=rand()%9;
            if(A[place]!='X' && A[place]!='O')
            {
                A[place]='X';
                break;
            }
        }        
    }
}
void input(char *A,int *place,char mark)
{
    if(A[0]== '1' && *place==1)
        A[0]=mark;
    else if(A[1]== '2' && *place==2)
        A[1]=mark;
    else if(A[2]== '3' && *place==3)
        A[2]=mark;
    else if(A[3]== '4' && *place==4)
        A[3]=mark;
    else if(A[4]== '5' && *place==5)
        A[4]=mark;
    else if(A[5]== '6' && *place==6)
        A[5]=mark;
    else if(A[6]== '7' && *place==7)
        A[6]=mark;
    else if(A[7]== '8' && *place==8)
        A[7]=mark;
    else if(A[8]== '9' && *place==9)
        A[8]=mark;
    else
    {
        printf("Invalid Input\n");
        *place=-1;
        getch();
    }
}
int checkwin(char *A)
{
    if(A[0]==A[1] && A[1]==A[2])
        return 1;
    else if(A[0]==A[3] && A[3]==A[6])
        return 1;
    else if(A[0]==A[4] && A[4]==A[8])
        return 1;
    else if(A[1]==A[4] && A[4]==A[7])
        return 1;
    else if(A[2]==A[5] && A[5]==A[8])
        return 1;
    else if(A[2]==A[4] && A[4]==A[6])
        return 1;
    else if(A[3]==A[4] && A[4]==A[5])
        return 1;
    else if(A[6]==A[7] && A[7]==A[8])
        return 1;
    else if(A[0]!='1' && A[1]!='2' && A[2]!='3' && A[3]!='4' && A[4]!='5' && A[5]!='6' && A[6]!='7' && A[7]!='8' && A[8]!='9')
        return 0;
    else 
    return -1;
}
void show (char *A)
{
    printf("\n\n\n###########################################\n");
    printf("\t\tTic Tac Toe\n");
    printf("###########################################\n");
    printf("\n\t\t    |  |  \n");
    printf("\t\t   %c|%c |%c\n",A[0],A[1],A[2]);
    printf("\t\t ___|__|___\n");
    printf("\t\t   %c|%c |%c\n",A[3],A[4],A[5]);
    printf("\t\t ___|__|___  \n");
    printf("\t\t   %c|%c |%c\n",A[6],A[7],A[8]);
    printf("\t\t    |  |  \n");    
    printf("\n###########################################\n");
}

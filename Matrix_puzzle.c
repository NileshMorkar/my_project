#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void fill_random(int B[4][4]);
void Display_Rule();
void show_matrix(int A[4][4]);
int win_matrix(int A[4][4]);
int main()
{
    int i,j,chance,ch='y',A[4][4];
    char name[25];
    system("color 4F");
    srand(time(NULL));
    
    while(ch=='y')           
    {    
        system("cls");
        printf("Player Name : ");
        fflush(stdin);
        fgets(name,25,stdin);
        system("cls");
        
        Display_Rule();
        fill_random(A);
        
        for(chance=15;chance>=1;chance--)
        {
            system("cls");
            printf("\nPlayer Name :- %sRemaining Moves :- %d\n\n",name,chance);
            show_matrix(A); 

            for(i=0;i<4;i++)
            {
                ch=1;
                for(j=0;j<4;j++)
                {
                    if(A[i][j]==32)
                    {    
                        ch=0;
                        break;
                    }
                }
                if(ch==0)
                    break;    
            }
            printf("\nPress Any Arrow\n");
            fflush(stdin);
            ch=getch();
                        
            if(ch==75 && j!=3)              //you can't use left arrow for 4th column....
            {
                A[i][j]=A[i][j+1];
                A[i][j+1]=32;
            }
            else if(ch==72 && i!=3)           //you can't use upper arrow for bottom row....
            {
                A[i][j]=A[i+1][j];
                A[i+1][j]=32;    
            }
            else if(ch==77 && j!=0)             //you can't use right arrow for 1st column........
            {
                A[i][j]=A[i][j-1];
                A[i][j-1]=32;    
            }
            else if(ch==80 && i!=0)             //you can't use down arrow for 1st row....
            {
                A[i][j]=A[i-1][j];
                A[i-1][j]=32;    
            }
            else if(ch =='e'||ch=='E')
            {
                exit(0);
            }
            else
            {
                chance++;
            }        
        }
        system("cls");
        printf("\nPlayer Name :- %sRemaining Moves :- %d\n\n",name,chance);
        show_matrix(A);
        ch=win_matrix(A);
        system("color 34");
        if(ch==0)
        {
            printf("\n\t\tYOU LOSE !\n\n");
            printf("Want to play again ?\n");
            printf("Enter 'y' to play again :  ");;
            scanf("%c",&ch);
        }
        else 
        {
            printf("\n\t\tCongratulation !!....YOU WIN !\n\n");
            printf("Want to play again ?\n");
            printf("Enter 'y' to play again :  ");
            scanf("%c",&ch);
        }
    }
    system("cls");
    system("color 2");
    printf("\t.........TNANK YOU FOR PLAYING.......");
    getch();
    return 0;
}
int win_matrix(int A[4][4])
{
    int i,j,k=1;

    if (A[3][3]!=32)
        return 0;               // 1st condition for wining...
    
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if (i==3 && j==3)
                continue;
            if(A[i][j]!=k)              //check from 1 to 15 ...
                return 0;
            k++;
        }    
    }
    return 1;
}
void show_matrix(int A[4][4])
{
    int i,j;
    system("color 70");
    printf("-----------------------\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(A[i][j]==32)
                printf("|%c   ",A[i][j]);
            else 
                printf("|%4d",A[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------------\n");
}
void fill_random(int A[4][4])
{
    int i,j,k,m,l,flag;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
                A[i][j]=(rand()%15)+1;
        }
    }
    //make zeros for repeted values...
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            m=A[i][j];
            for(k=i;k<4;k++)
            {
                for(l=0;l<4;l++)
                {
                    if(i==k && j==l)
                        continue;
                    if(m==A[k][l])
                        A[k][l]=0;
                }
            }
        }
    }
    //at the place of zero place remaining numbers between 1 to 15...
    for(k=1;k<=15;k++)
    {
        flag=1;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(A[i][j]==k)
                {    
                    flag=0;
                    break;
                }
            }
            if(flag==0)
                break;
        }
        if(flag)
        {
            m=0;
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(A[i][j]==0)
                    {
                        A[i][j]=k;
                        m=1;
                        break;
                    }
                }
                if(m)
                    break;
            }   
        }
        //A[3][3]='\x20';
    }
    // finally place the zero at last position of 2D array
    if(A[3][3]!=0)
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                    if(A[i][j]==0)
                    {
                        A[i][j]=A[3][3];
                        A[3][3]=0;
                        break;
                    }
            }
            if(A[3][3]==0)
                break;
        }
    }
    A[3][3]=32;
}
void Display_Rule()
{
    printf("\t\t\tMATRIX PUZZLE\n\n");
    system("color 94");
    printf("\t\t      RULES OF THIS GAME\n\n");
    printf("1.You can move only 1 step at a time by arrow key\n");
    printf("\tMove Up   :by Up arrow key\n");
    printf("\tMove Down :by Down Arrow key\n");
    printf("\tMove left :by Left arrow key\n");
    printf("\tMove Right:by Right arrow key\n");
    printf("\n2.You can move number at empty position only\n");
    printf("\n3.For each valid move  : your total number of move will decreased by 1\n");
    printf("\n4.Wining sitution  : Number in a 4*4 matrix should be in order from 1 to 15\n\n");
    printf("\tWinning Situation:\n");
    printf("------------------\n");
    printf("|  1|  2|  3|  4|\n");
    printf("|  5|  6|  7|  8|\n");
    printf("|  9| 10| 11| 12|\n");
    printf("| 11| 12| 13|   |\n");
    printf("------------------\n");
    printf("\n5. You can Exit the game at any time by pressing 'E' OR 'e'\n");
    printf("So Try to win in minimum no of move\n");
    printf("\n\tHappy Gaming...Good Luck..!\n");
    printf("\nFor Start : Press Any Key\n");
    getch();
    system("cls");
}

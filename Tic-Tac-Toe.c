

#include <stdio.h>
#include <stdlib.h>


void InitializeBoard(int m, int n, char board[][n]);
void PrintBoard(int m,int n, char board[][n]);
void CreateBoard ( int m, int n, char board[][n]);
int IsValidBoard ( int m, int n, char board[][n]);
void ListWinningCells ( int m, int n, char board[][n]);
char WhoIsTheWinner ( int m, int n, char board[][n]);
char tester(char array[],int size);


int main() {
  
    int m= 3,n=3,result;
    char arr[m][n];
    char option = 'a';
    InitializeBoard(m, n, arr);
    
    while(option!='e'){
        
        printf("press 'p' to print the tic-tac-toe board\n");
        printf("press 'c' to create a tic-tac-toe board with some X and O cells\n");
        printf("press 't' to test if a tic-tac-toe board is valid or invalid board\n");
        printf("press 'w' to predict winning cell for player X or O\n");
        printf("press 'e' to exit\n");
        
       scanf(" %c",&option);
        switch(option)
        {
        case 'p': PrintBoard(m,n,arr);
        break;
        case 'c': CreateBoard(m,n,arr);
        break;
        case 't': result = IsValidBoard(m,n,arr);
        if(result)
        printf("Valid\n");
        else
        printf("Invalid\n");
        break;
        case 'w': ListWinningCells(m,n,arr);
        break;
        case 'e': break;
        default: printf("Enter a valid input: \n");
        }
    }
    
    int i = IsValidBoard(m, n, arr);
    int winner = WhoIsTheWinner(m,n,arr);
    
    
        
        if(winner == 'D'){
            printf("No player won!\n");
        }else{
            printf("Player %c has won.\n", winner);
        }
    
    return 0;
}

void InitializeBoard(int m, int n, char board[][n]){
    int c = 1;
    for(int i=0; i<m; i++){
        for(int j =0; j<n; j++){
            board[i][j] = c +'0';
            c++;
        }
    }
   
}

void PrintBoard(int m,int n, char board[][n]){
    int i, j;
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%c", board[i][j]);
                if(j==n-1){
                    printf("\n");
                }else{
                    printf("|");
                }
        }
        
        if(i!=m-1){
            printf("_|_|_\n");
        }
        
    }
               
}


 void CreateBoard ( int m, int n, char board[][n]){
     int number=0;
     char choice;
     
     while(number!=-1){
         PrintBoard(m, n, board);
         printf("Enter the number of the cell you want to enter X or 0 or -1 to exit.\n");
         scanf("%d", &number);
              
         if(number==-1){
             break;
         }else if(!(number>=1 && number<=9)){
             continue;
         }
        
        puts("Type x or o ");
        scanf(" %c", &choice);
             
        if(choice == 'x' ||  choice =='o'){
             
         if(number==1){
             if( board[0][0]=='x' ||  board[0][0]=='o'){
                 printf("You've already used the cell\n");
             }else
                 board[0][0] = choice;
         }
                 
         if(number == 2){
             if( board[0][1]=='x' ||  board[0][1]=='o'){
                printf("You've already used the cell\n");
            }else
                board[0][1] = choice;
         }
         
         if(number== 3){
             if( board[0][2]=='x' ||  board[0][2]=='o'){
                printf("You've already used the cell\n");
            }else
                board[0][2] = choice;
         }
                 
         if(number == 4){
             if( board[1][0]=='x' ||  board[1][0]=='o'){
                printf("You've already used the cell\n");
            }else
             board[1][0] = choice;
         }
                 
         if(number== 5){
             if( board[1][1]=='x' ||  board[1][1]=='o'){
                printf("You've already used the cell\n");
            }else
                board[1][1] = choice;
         }
         
         if(number == 6){
            if( board[1][2]=='x' ||  board[1][2]=='o'){
                printf("You've already used the cell\n");
            }else
                board[1][2] = choice;
         }
         
         if(number== 7){
             if( board[2][0]=='x' ||  board[2][0]=='o'){
                printf("You've already used the cell\n");
            }else
             board[2][0] = choice;
         }
         
         if(number == 8){
             if( board[2][1]=='x' ||  board[2][1]=='o'){
                 printf("You've already used the cell\n");
             }else
                 board[2][1] = choice;
         }
         if(number== 9){
             if( board[2][2]=='x' ||  board[2][2]=='o'){
                 printf("You've already used the cell\n");
             }else
                 board[2][2] = choice;
         }
        
        else {
            continue;
        }
    }
         
}
}


int IsValidBoard ( int m, int n, char board[][n]){
    int countX=0,countO=0;
    
    for(int i=0; i<m; i++){
        for(int j =0; j<n; j++){
            if(board[i][j] == 'x'){
                countX++;
            }else if(board[i][j] == 'o'){
                countO++;
                }
            }
        }
    
    if(countX-countO == 1 || countX-countO == 0 || countO-countX== 1 || countO-countX==0){
        return 1;
    }else
        return 0;
}

void ListWinningCells ( int m, int n, char board[][n]){
    int i = IsValidBoard(m, n, board);
    
    if(i){
    
    if(board[0][0]==board[2][0] && board[1][0]=='4')
        printf("Enter %c in cell %c\n",board[2][0],board[1][0]);
        
    if(board[0][1]==board[2][1] && board[1][1]=='5')
        printf("Enter %c in cell %c\n",board[2][1],board[1][1]);
        
    if(board[0][2]==board[2][2] && board[1][2]=='6')
        printf("Enter %c in cell %c\n",board[2][2],board[1][2]);

    if(board[0][0]==board[0][1] && board[0][2]=='3')
        printf("Enter %c in cell %c\n",board[0][1],board[0][2]);
        
    if(board[1][0]==board[1][1] && board[1][2]=='6')
        printf("Enter %c in cell %c\n",board[1][1],board[1][2]);
        
    if(board[2][0]==board[2][1] && board[2][2]=='9')
        printf("Enter %c in cell %c\n",board[2][1],board[2][2]);

    if(board[0][2]==board[0][1] && board[0][0]=='1')
        printf("Enter %c in cell %c\n",board[2][1],board[2][2]);
        
    if(board[1][2]==board[1][1] && board[1][0]=='4')
        printf("Enter %c in cell %c\n",board[2][1],board[2][2]);
        
    if(board[2][2]==board[2][1] && board[2][0]=='7')
        printf("Enter %c in cell %c\n",board[2][1],board[2][2]);

    if(board[0][0]==board[0][2] && board[0][1]=='2')
        printf("Enter %c in cell %c\n",board[0][2],board[0][1]);
        
    if(board[1][0]==board[1][2] && board[1][1]=='5')
        printf("Enter %c in cell %c\n",board[1][2],board[1][1]);
        
    if(board[2][0]==board[2][2] && board[2][1]=='8')
        printf("Enter %c in cell %c\n",board[2][2],board[2][1]);

    if(board[0][0]==board[1][0] && board[2][0]=='7')
        printf("Enter %c in cell %c\n",board[1][0],board[2][0]);
        
    if(board[0][1]==board[1][1] && board[2][1]=='8')
        printf("Enter %c in cell %c\n",board[1][1],board[2][1]);
        
    if(board[0][2]==board[1][2] && board[2][2]=='9')
        printf("Enter %c in cell %c\n",board[1][2],board[2][2]);

    if(board[1][0]==board[2][0] && board[0][0]=='1')
        printf("Enter %c in cell %c\n",board[1][0],board[0][0]);
        
    if(board[1][1]==board[2][1] && board[0][1]=='2')
        printf("Enter %c in cell %c\n",board[1][1],board[0][1]);
        
    if(board[1][2]==board[2][2] && board[0][2]=='3')
        printf("Enter %c in cell %c\n",board[1][2],board[0][2]);

    if(board[0][0]==board[1][1] && board[2][2]=='9')
        printf("Enter %c in cell %c\n",board[1][1],board[2][2]);
        
    if(board[2][0]==board[1][1] && board[0][2]=='3')
        printf("Enter %c in cell %c\n",board[1][1],board[0][2]);

    if(board[2][2]==board[1][1] && board[0][0]=='1')
        printf("Enter %c in cell %c\n",board[1][1],board[0][0]);
        
    if(board[0][2]==board[1][1] && board[2][0]=='7')
        printf("%c %c\n",board[1][1],board[2][0]);

    if(board[0][0]==board[2][2] && board[1][1]=='5')
        printf("Enter %c in cell %c\n",board[2][2],board[1][1]);
        
    if(board[2][0]==board[0][2] && board[1][1]=='5')
        printf("Enter %c in cell %c\n",board[0][2],board[1][1]);

    }else
        printf("Board is not valid, winning move can not be predicted\n");
    
}

char WhoIsTheWinner( int m, int n, char board[][n])
{
    char b;
    char arr[3];

    arr[0] = board[0][0], arr[1] = board[0][1], arr[2] = board[0][2];
    b = tester(arr, n);

    if(b == 'D'){
        arr[0] = board[1][0], arr[1] = board[1][1], arr[2] = board[1][2];
        b = tester(arr,3);
    }

    if(b == 'D')
    {
        arr[0] = board[2][0], arr[1] = board[2][1], arr[2] = board[2][2];
        b = tester(arr,3);
    }
    if(b == 'D')
    {
        arr[0] = board[0][0], arr[1] = board[1][0], arr[2] = board[2][0];
        b = tester(arr, 3);
    }

    if(b == 'D')
    {
        arr[0] = board[0][1], arr[1] = board[1][1], arr[2] = board[2][1];
        b = tester(arr, 3);
    }

    if(b == 'D')
    {
        arr[0] = board[0][2], arr[1] = board[1][2], arr[2] = board[2][2];
        b = tester(arr, 3);
    }

    if(b == 'D')
    {
        arr[0] = board[0][0], arr[1] = board[1][1], arr[2] = board[2][2];
        b = tester(arr, 3);
    }

    if(b == 'D')
    {
        arr[0] = board[2][0], arr[1] = board[1][1], arr[2] = board[0][2];
        b = tester(arr, 3);
    }

    return b;
}

char tester(char array[],int size)
{
    if(array[size - 2] == array[size - 1])
    {
        if(size == 2)
        {
            return array[0];
        }
        else
        {
            return tester(array, size - 1);
        }
    }
    else
    {
        return 'D';
    }
}



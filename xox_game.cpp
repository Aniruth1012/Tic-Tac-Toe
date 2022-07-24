#include <iostream>
#include<Windows.h>
#include<Wchar.h>
using namespace std;

char s;
int q=0;
char grid[5][5];

int reenter()
{
    int b;
    cout<<endl<<"The entered number is already chosen,please choose another : ";
    cin>>b;
    return b;
}

int printRules()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return GetLastError();
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return GetLastError();
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return GetLastError();
    }

      wprintf(L"\x1b[35m***************************************************************************************\n");
      wprintf(L"\x1b[36m\t\t      TIC-TAC-TOE GAME\n");
      wprintf(L"\x1b[35m***************************************************************************************\n");
      wprintf(L"\x1b[36m"); // turns all text below it as blue
      wprintf(L" >> The game consists of a 3x3 grid.\n");
      wprintf(L" >> Player 1 goes with 'X' and Player 2 with 'O'.\n");
      wprintf(L" >> At your turn, enter your number of choice, representing the corresponding square.\n");
      wprintf(L"\t\t\t | \t | \t\n");
      wprintf(L"\t\t     1   |   2   |   3\n");
      wprintf(L"\t\t  _______|_______|_______\n");
      wprintf(L"\t\t\t | \t | \t\n");
      wprintf(L"\t\t     4   |   5   |   6\n");
      wprintf(L"\t\t  _______|_______|_______\n");
      wprintf(L"\t\t\t | \t | \t\n");
      wprintf(L"\t\t     7   |   8   |   9\n");
      wprintf(L"\t\t\t | \t | \t\n");
      wprintf(L" >> However, re-entering a number is not allowed.\n");
      wprintf(L" >> The two players take turns in marking the squares until a win is detected.\n");
      wprintf(L" >> Else, it is a tie.\n");
      wprintf(L"\x1b[35m***************************************************************************************\n");
      wprintf(L"\x1b[0m"); // explicitly turns text to default color
}
void putg(int a)
{
    if(a==1)
    {
        if(grid[0][0]==' ')
        {
            grid[0][0]=s;
        }
        else
        {
            putg(reenter());
        }
    }
    else if(a==2)
    {
        if(grid[0][2]==' ')
        {
            grid[0][2]=s;
        }
        else
        {
            putg(reenter());
        }
    }
    else if(a==3)
    {
        if(grid[0][4]==' ')
        {
            grid[0][4]=s;
        }
        else
        {
            putg(reenter());
        }
    }
    else if(a==4)
    {
        if(grid[2][0]==' ')
        {
            grid[2][0]=s;
        }
        else
        {
            putg(reenter());
        }
    }
    else if(a==5)
    {
        if(grid[2][2]==' ')
        {
            grid[2][2]=s;
        }
        else
        {
            putg(reenter());
        }
    }
    else if(a==6)
    {
        if(grid[2][4]==' ')
        {
            grid[2][4]=s;
        }
        else
        {
            putg(reenter());
        }
    }
    else if(a==7)
    {
        if(grid[4][0]==' ')
        {
            grid[4][0]=s;
        }
        else
        {
            putg(reenter());
        }
    }
    else if(a==8)
    {
        if(grid[4][2]==' ')
        {
            grid[4][2]=s;
        }
        else
        {
            putg(reenter());
        }
    }
    else if(a==9)
    {
        if(grid[4][4]==' ')
        {
            grid[4][4]=s;
        }
        else
        {
            putg(reenter());
        }
    }
    else
    {
        int b;
        cout<<"The entered number is invalid,please enter another number : ";
        cin>>b;
        putg(b);
    }
}

void display()
{
    for(int i=0;i<5;i++)
    {
        cout<<"\t";
        for(int j=0;j<5;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int check(int *ptr)
{
    for(int i=0;i<5;i+=2)
    {
        char a;
        int count=0;
        for(int j=0;j<5;j+=2)
        {
            if(grid[i][j]=='x'||grid[i][j]=='o')
            {
                a=grid[i][j];
                break;
            }
        }
        for(int j=0;j<5;j+=2)
        {
            if(a==grid[i][j])
            {
                count+=1;
            }
        }
        if(count==3)
        {
            *ptr=1;
            return *ptr;
            break;
        }
    }
    for(int j=0;j<5;j+=2)
    {
        char a1;
        int count1=0;
        for(int i=0;i<5;i+=2)
        {
            if(grid[i][j]=='x'||grid[i][j]=='o')
            {
                a1=grid[i][j];
                break;
            }
        }
        for(int i=0;i<5;i+=2)
        {
            if(a1==grid[i][j])
            {
                count1+=1;
            }
        }
        if(count1==3)
        {
            *ptr=1;
            return *ptr;
            break;
        }
    }
    char a2=grid[2][2];
    if(a2!=' ')
    {
        if(grid[0][0]==a2&&grid[4][4]==a2)
        {
            *ptr=1;
            return *ptr;
        }
        if(grid[0][4]==a2&&grid[4][0]==a2)
        {
            *ptr=1;
            return *ptr;
        }
    }
    return 0;
}

int main()
{
    printRules();
    string name1,name2;
    cout<<"Enter Player 1 name : ";
    getline(cin,name1);
    cout<<"Enter Player 2 name : ";
    getline(cin,name2);
    int move;
    int strike;
    int *ptr,*ptr1;
    ptr=&strike;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            grid[i][j]=' ';
        }
    }
    for(int i=1;i<5;i+=2)
    {
        for(int j=0;j<5;j+=1)
        {
            grid[i][j]='-';
        }
    }
    for(int j=1;j<5;j+=2)
    {
        for(int i=0;i<5;i+=1)
        {
            grid[i][j]='|';
        }
    }
    for(int i=0;i<5;i+=1)
    {
        cout<<name1<<"'s turn : ";
        s='x';
        cin>>move;
        putg(move);
        check(ptr);
        if(*ptr==1)
        {
            cout<<endl<<"\t   "<<name1<<" WINS!"<<endl;
            q=1;
            break;
        }
        display();
        cout<<endl;
        if(i==4)
        {
            break;
        }
        cout<<name2<<" 's turn : ";
        s='o';
        cin>>move;
        putg(move);
        check(ptr);
        if(*ptr==1)
        {
            cout<<endl<<"\t   "<<name2<<" WINS!"<<endl;
            q=1;
            break;
        }
        display();
        cout<<endl;
    }
    if(q==0)
    {
        cout<<"It's a tie!"<<endl;
    }
    cout<<endl;
    display();
    wprintf(L"\n\n");
    wprintf(L"\x1b[35m***************************************************************************************\n");
    wprintf(L"\x1b[36m\t\tVIT Mathematical Association (VITMAS)\n");
    wprintf(L"\x1b[35m***************************************************************************************\n");
    wprintf(L"\x1b[36m  TEAM MEMBERS\n");
    wprintf(L"\x1b[35m***************************************************************************************\n");
    wprintf(L"\x1b[36m");
    wprintf(L" >> Aniruth Ramanathan V (21BCE2356)\n");
    wprintf(L" >> Pooja Priya S (21BCE2149)\n");
    wprintf(L"\x1b[0m");
    return 0;
}

# Tic-Tac-Toe
My first project on c++ , a most played common game tic-tac-toe

Code :
#include <iostream>
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
        cout<<"The enterd number is invalid,please enter another number : ";
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
    //cout<<grid[2][2];
    //cout<<grid[0][0];
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
            //cout<<"a is "<<a;
            //cout<<" grid is "<<grid[i][j];
            if(a==grid[i][j])
            {
                //cout<<"i,j"<<i<<" "<<j<<" "<<grid[i][j];
                count+=1;
                //cout<<count<<endl;
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
            //cout<<"a is "<<a;
            //cout<<" grid is "<<grid[i][j];
            if(a1==grid[i][j])
            {
                //cout<<"i,j"<<i<<" "<<j<<" "<<grid[i][j];
                count1+=1;
                //cout<<count<<endl;
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
            cout<<endl<<name1<<" wins"<<endl;
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
            cout<<endl<<name2<<" wins"<<endl;
            q=1;
            break;
        }
        display();
        cout<<endl;
    }
    if(q==0)
    {
        cout<<"It's a tie"<<endl;
    }
    cout<<endl;
    display();
} 
 

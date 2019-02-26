#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
#include <string.h>

using namespace std;

//the program will have two matrix

char game_table[20][20]; //the matrix that the user will see
int number_table[20][20]; //the core matrix


void create_table()  //this function creates and initializes both matrix with *, respectively 0.
{

    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            game_table[i][j] = '*';

    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            number_table[i][j] = 0;
}

int neighbourgh_number(int i, int j) //this function calculates the number of neighbourgh that are mines for every element in the number_table, for every particular case
{
    int number = 0;
    if(i!=0 && i!=19 && j!=0 && j!=19)
    {
        if(number_table[i-1][j-1] != -1)
            number++;
        if(number_table[i-1][j] != -1)
            number++;
        if(number_table[i-1][j+1] != -1)
            number++;
        if(number_table[i][j-1] != -1)
            number++;
        if(number_table[i][j+1] != -1)
            number++;
        if(number_table[i+1][j-1] != -1)
            number++;
        if(number_table[i+1][j] != -1)
            number++;
        if(number_table[i+1][j+1] != -1)
            number++;
    }
    else if(i==0 && j!=0 && j!=19)
    {
        if(number_table[i][j-1] != -1)
            number++;
        if(number_table[i][j+1] != -1)
            number++;
        if(number_table[i+1][j-1] != -1)
            number++;
        if(number_table[i+1][j] != -1)
            number++;
        if(number_table[i+1][j+1] != -1)
            number++;
    }
    else if(i==19 && j!=0 && j!=19)
    {
        if(number_table[i-1][j-1] != -1)
            number++;
        if(number_table[i-1][j] != -1)
            number++;
        if(number_table[i-1][j+1] != -1)
            number++;
        if(number_table[i][j-1] != -1)
            number++;
        if(number_table[i][j+1] != -1)
            number++;
    }
    else if(i!=0 && i!=19 && j==0)
    {
        if(number_table[i-1][j] != -1)
            number++;
        if(number_table[i-1][j+1] != -1)
            number++;
        if(number_table[i][j+1] != -1)
            number++;
        if(number_table[i+1][j] != -1)
            number++;
        if(number_table[i+1][j+1] != -1)
            number++;
    }
    else if(i!=0 && i!=19 && j==19)
    {
        if(number_table[i-1][j-1] != -1)
            number++;
        if(number_table[i-1][j] != -1)
            number++;
        if(number_table[i][j-1] != -1)
            number++;
        if(number_table[i+1][j-1] != -1)
            number++;
        if(number_table[i+1][j] != -1)
            number++;
    }
    else if(i==0 && j==0)
    {
        if(number_table[i][j+1] != -1)
            number++;
        if(number_table[i+1][j] != -1)
            number++;
        if(number_table[i+1][j+1] != -1)
            number++;
    }
    else if(i==0 && j==19)
    {
        if(number_table[i][j-1] != -1)
            number++;
        if(number_table[i+1][j-1] != -1)
            number++;
        if(number_table[i+1][j] != -1)
            number++;
    }
    else if(i==19 && j==0)
    {
        if(number_table[i-1][j] != -1)
            number++;
        if(number_table[i-1][j+1] != -1)
            number++;
        if(number_table[i][j+1] != -1)
            number++;
    }
    else if(i==19 && j==19)
    {
        if(number_table[i-1][j-1] != -1)
            number++;
        if(number_table[i-1][j] != -1)
            number++;
        if(number_table[i][j-1] != -1)
            number++;
    }
    return number;
}

void table_number()  //giving every element the count of his neighbourgh mines
{
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            if(number_table[i][j] != -1)
                number_table[i][j] = neighbourgh_number(i,j);
}

void create_mines() // creating mines at random positions in the number_table
{
    int i,j, mines = 0;
    while(mines < 50)
    {
        i=rand() % 19;
        j=rand() % 19;
        if(number_table[i][j] != -1)
        {
            number_table[i][j] = -1;
            mines++;
        }
    }
}

void print_table()
{
    for(int i=0; i<19; i++)
    {
        for(int j=0; j<20; j++)
            cout<<setw(1)<<game_table[i][j]<<"  ";
        cout<<endl;
    }

}

void reveal() //the function that reveals and element at a given position by the user
{
    print_table();
    int i,j,x;
    create_mines();
    table_number();
    cout<<"Insert the position that you want to reveal: "<<endl<<"i: ";
    cin>>i;
    cout<<"j: ";
    cin>>j;
    game_table[i][j] = number_table[i][j] + '0';
    system("cls");
    print_table();
    while(number_table[i][j]!=-1)
    {
        cout<<"Insert the position that you want to reveal: "<<endl<<"i: ";
        cin>>i;
        cout<<"j: ";
        cin>>j;
        game_table[i][j] = number_table[i][j] + '0';
        system("cls");
        print_table();
    }
    if(number_table[i][j]==-1)
        cout<<endl<<"GAME OVER! YOU HIT A MINE!";
}

int main()
{
    create_table();
    reveal();
    return 0;
}

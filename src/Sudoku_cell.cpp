#include "include/Sudoku_cell.hpp"
#include <iostream>
using namespace std;

char Sudoku_cell::unic_id=0;

Sudoku_cell::Sudoku_cell()
{
    if ((unic_id < 81) && (unic_id >=0))
    {
        ID=unic_id;
        column=ID%9;
        row=ID/9;
        switch (row)
        {
        case 0:
        case 1:
        case 2:
            if ((column>=0)&&(column<=2))block=0;
            else if ((column>=3)&&(column<=5))block=1;
            else block=2;
            break;
        case 3:
        case 4:
        case 5:
            if ((column>=0)&&(column<=2))block=3;
            else if ((column>=3)&&(column<=5))block=4;
            else block=5;
            break;
        case 6:
        case 7:
        case 8:
            if ((column>=0)&&(column<=2))block=6;
            else if ((column>=3)&&(column<=5))block=7;
            else block=8;
            break;
        default:
            break;
        };
    }
    is_solved=0;
    value=0;
    unic_id++;
}

void Sudoku_cell::Set_cell_block(char b)
{if((b>=0)||(b<=8))block=b;}
void Sudoku_cell::Set_cell_row(char r)
{if((r>=0)||(r<=8))row=r;}
void Sudoku_cell::Set_cell_column(char c)
{if((c>=0)||(c<=8))column=c;}
void Sudoku_cell::Set_cell_value(char v)
{if((v>=1)||(v<=9))value=v;}
void Sudoku_cell::Set_cell_solve_status(bool s)
{if((s==0)||(s==1))is_solved=s;}
void Sudoku_cell::Set_cell_canbe_x_status(unsigned char x,bool s)
{if((x>=0)&&(x<=8))canbe_x[x]=s;}
void Sudoku_cell::Set_cell_id(char id)
{ID=id;}

char Sudoku_cell::Get_cell_block()
{return block;}
char Sudoku_cell::Get_cell_row()
{return row;}
char Sudoku_cell::Get_cell_column()
{return column;}
char Sudoku_cell::Get_cell_value()
{return value;}
bool Sudoku_cell::Get_cell_solve_status()
{return is_solved;}
bool Sudoku_cell::Get_cell_canbe_x_status(unsigned char x)
{return canbe_x[x];}
char Sudoku_cell::Get_cell_id()
{return ID;}

Sudoku_cell::~Sudoku_cell()
{
}

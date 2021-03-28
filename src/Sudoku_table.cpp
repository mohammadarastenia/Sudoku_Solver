#include "include/Sudoku_table.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

bool Sudoku_table::Check_one_row(const unsigned char fix_row)
{
    unsigned char column,j,num,comment,first_id,last_id;
    bool solve_row_successful=0;
    comment = fix_row + '0';
    cout<<"Checking row "<<comment<<endl;
    for (column = 0; column < 9; column++)//sweep all columns of single row
    {
        if(cells[column + (9*fix_row)].Get_cell_solve_status())//if we have full cell
        {
            num=cells[column + (9*fix_row)].Get_cell_value();
            for (j = 0; j < 9; j++)
            {
                if(cells[j + (9*fix_row)].Get_cell_solve_status() == 0)cells[j + (9*fix_row)].Set_cell_canbe_x_status((num-1),0);
            }
        }
    }
    first_id=fix_row*9;
    last_id=first_id + 8;
    for (j = first_id; j <= last_id; j++)
    {
        if(Solve_cell(j))solve_row_successful=1;
    }
    return solve_row_successful;
}

bool Sudoku_table::Check_one_column(const unsigned char fix_column)
{
    unsigned char row,i,num,comment,last_id;
    bool solve_column_successful=0;
    comment = fix_column + '0';
    cout<<"Checking column "<<comment<<endl;
    for (row = 0; row < 9; row++)//sweep all rows of single column
    {
        if(cells[fix_column + (row*9)].Get_cell_solve_status())//if we have full cell
        {
            num=cells[fix_column + (row*9)].Get_cell_value();//get it's value
            for (i = 0; i < 9; i++)
            {
                if (cells[fix_column + (i*9)].Get_cell_solve_status() == 0)cells[fix_column + (i*9)].Set_cell_canbe_x_status((num-1),0);
            }
        }

    }
    last_id=fix_column + (8*9);
    for (i = fix_column; i <= last_id; i=i+9)
    {
        if(Solve_cell(i))solve_column_successful=1;
    }
    return solve_column_successful;
}


bool Sudoku_table::Check_one_block(const unsigned char fix_block)
{
    unsigned char column,x1,x2,row,y1,y2,num,i,j,comment,id;
    bool solve_block_successful=0;
    comment = fix_block +'0';
    cout<<"Checking block "<<comment<<endl;
    switch (fix_block)
    {
    case 0:
        x1=0;
        x2=2;
        y1=0;
        y2=2;
        break;
    case 1:
        x1=3;
        x2=5;
        y1=0;
        y2=2;
        break;
    case 2:
        x1=6;
        x2=8;
        y1=0;
        y2=2;
        break;
    case 3:
        x1=0;
        x2=2;
        y1=3;
        y2=5;
        break;
    case 4:
        x1=3;
        x2=5;
        y1=3;
        y2=5;
        break;
    case 5:
        x1=6;
        x2=8;
        y1=3;
        y2=5;
        break;
    case 6:
        x1=0;
        x2=2;
        y1=6;
        y2=8;
        break;
    case 7:
        x1=3;
        x2=5;
        y1=6;
        y2=8;
        break;                                
    case 8:
        x1=6;
        x2=8;
        y1=6;
        y2=8;
        break;                               
    default:
        break;
    }
    for (column = x1; column <= x2; column++)//sweep all columns of single block
    {
        for (row = y1; row <= y2; row++)//sweep all rows of single block
        {
            if(cells[column + (row*9)].Get_cell_solve_status())//if we have full cell
            {
                num=cells[column + (row*9)].Get_cell_value();//get it's value
                for (i = x1; i <= x2; i++)
                {
                    for (j = y1; j <= y2; j++)
                    {
                        if (cells[i + (j*9)].Get_cell_solve_status() == 0)cells[i + (j*9)].Set_cell_canbe_x_status((num-1),0);
                    }
                }
            }
        }
    }
    for (column = x1; column <= x2; column++)
    {
        for (row = y1; row <= y2; row++)
        {
            id=column + (row*9);
            if(Solve_cell(id))solve_block_successful=1;
        }
    }
    return solve_block_successful;
}
void Sudoku_table::Solve_table(void)
{
    bool solve_row_successful=0;
    bool solve_column_successful=0;
    bool solve_block_successful=0;
    unsigned char counter;
    do
    {
        solve_row_successful=0;
        solve_column_successful=0;
        solve_block_successful=0;
        for ( counter = 0; counter < 9; counter++)if(Check_one_row(counter))solve_row_successful=1;
        if(empty_cells == 0)break;
        for ( counter = 0; counter < 9; counter++)if(Check_one_column(counter))solve_column_successful=1;
        if(empty_cells == 0)break;
        for ( counter = 0; counter < 9; counter++)if(Check_one_block(counter))solve_block_successful=1;
        if(empty_cells == 0)break;
    } while (solve_block_successful || solve_row_successful || solve_column_successful);
    if(empty_cells == 0)cout<<"Sudoku Solved :)"<<endl;
    else 
    {
        cout<<"Sudoku not Solve :("<<endl;
        for ( counter = 0; counter < 81; counter++)
        {
            if(cells[counter].Get_cell_solve_status() == 0){
                cout<<"----------------------------"<<endl;
                Check_cell_properties(counter);
                cout<<"----------------------------"<<endl;
            }
        }
    }
}
bool Sudoku_table::Solve_cell(unsigned char id)//if solved an empty cell return 1 else 0
{
    unsigned char a,b,c,i,num,confirm=0;
    if(cells[id].Get_cell_solve_status())return false;
    for (i = 0; i < 9; i++)
    {
        if (cells[id].Get_cell_canbe_x_status(i))//if a cell can be a value
        {
            confirm++;
            num=(i+1);
        }
    }
    if(confirm == 1)//but can not be other value 
    {
        if(cells[id].Get_cell_solve_status() == 0)
        {
            cells[id].Set_cell_value(num);
            cells[id].Set_cell_solve_status(true);
            empty_cells--;
            a=(id/10)+'0';
            b=(id%10)+'0';
            c=num + '0';
            cout<<"cell [ ";
            if(a != '0')cout<<a;
            cout<<b;
            cout<<"]= ";
            cout<<c<<endl;
        }
        
        return true;
    }
    return false;
}
void Sudoku_table::Get_table(void)
{
    unsigned char buffer[9];
    unsigned char i,j,value,count=0;
    cout<<"Please pay attention that 0 mean empty cell and enter value without any space "<<endl;
    for ( i = '0'; i < '9'; i++)
    {
        cout<<"Enter line "<<i<<" of Sudoku table"<<endl;
        cin>>setw(10)>>buffer;
        cin.ignore(256, '\n');
        for ( j = 0; j < 9; j++)
        {
            value=buffer[j] -'0';
            if(value != 0)
            {
                for(char k=0;k<9;k++)cells[count].Set_cell_canbe_x_status(k,0);
                cells[count].Set_cell_canbe_x_status((value-1),1);
                cells[count].Set_cell_solve_status(1);
                empty_cells--;
            }
            else
            {
                for(char k=0;k<9;k++)cells[count].Set_cell_canbe_x_status(k,1);
            }
            cells[count].Set_cell_value(value);
            count++;
        }
    }   
}
void Sudoku_table::Get_table(unsigned char* s)
{
    unsigned char value,count=0;
    for ( count = 0; count < 81; count++)
    {
        value=s[count];
        if(value != 0)
        {
            for(char k=0;k<9;k++)cells[count].Set_cell_canbe_x_status(k,0);
            cells[count].Set_cell_canbe_x_status((value-1),1);
            cells[count].Set_cell_solve_status(1);
            empty_cells--;
        }
        else
        {
            for(char k=0;k<9;k++)cells[count].Set_cell_canbe_x_status(k,1);
        }
        cells[count].Set_cell_value(value);
    }  
}
void Sudoku_table::Show_table(void)
{
    unsigned char i,j,value,k=0;
    cout<<"col|row  ";
    for(j='0';j<='8';j++)cout<<j<<"\t";
    cout<<endl;
    for(j=0;j<=8;j++)
    {
        if(j==0)cout<<"   |----";
        else cout<<"--------";
    }
    cout<<endl;
    for(i='0';i<='8';i++)
    {
        cout<<i <<"  |     ";
        for(j='0';j<='8';j++)
        {
            value=cells[k].Get_cell_value() + '0';
            cout<<value<<"\t";
            k++;
        }
        cout<<endl;
    } 
}
void Sudoku_table::Check_cell_properties(unsigned char id)
{
    unsigned char temp,t1,t2;
    temp=cells[id].Get_cell_id();
    t1=(temp/10)+'0';
    t2=(temp%10)+'0';
    cout<<"cell ID="<<t1<<t2<<endl;
    temp=cells[id].Get_cell_row() + '0';
    cout<<"cell row="<<temp<<endl;
    temp=cells[id].Get_cell_column() + '0';
    cout<<"cell column="<<temp<<endl;
    temp=cells[id].Get_cell_block() + '0';
    cout<<"cell block="<<temp<<endl;
    temp=cells[id].Get_cell_value() + '0';
    cout<<"cell value="<<temp<<endl;
    temp=cells[id].Get_cell_solve_status() + '0';
    if(temp == '0')cout<<"cell is empty"<<endl;
    else cout<<"cell has good value"<<endl;
    for (char i = 0; i < 9; i++)
    {
        if (cells[id].Get_cell_canbe_x_status(i))
        {
            temp=(i+1)+ '0';
            cout<<"cell can have value "<<temp<<endl;
        }
        
    }
    
}
char Sudoku_table::Get_Emty_cells(void)
{
    unsigned char a,b;
    a=empty_cells/10 + '0';
    b=empty_cells%10 + '0';
    cout<<"Empty cells= ";
    if(a != '0')cout<<a;
    cout<<b<<endl;
    return empty_cells;
}

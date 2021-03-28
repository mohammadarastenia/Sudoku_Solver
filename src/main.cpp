#include "include/Sudoku_table.hpp"
#include <iostream>
int main()
{
	unsigned char sellect;
    //ID=column + 9xrow
    unsigned char table[81]={//very hard sample
        5,3,0,0,7,0,0,0,0,
        6,0,0,1,9,5,0,0,0,
        0,9,8,0,0,0,0,6,0,
        8,0,0,0,6,0,0,0,3,
        4,0,0,8,0,3,0,0,1,
        7,0,0,0,2,0,0,0,6,
        0,6,0,0,0,0,2,8,0,
        0,0,0,4,1,9,0,0,5,
        0,0,0,0,8,0,0,7,9
    };
	Sudoku_table Sudoku;
    std::cout<<"Do you like to solve sample in program table( 1 ) or type value in terminal( 2 )?";
    std::cin >> sellect;
    if(sellect == '1')Sudoku.Get_table(table);
    else Sudoku.Get_table();
    Sudoku.Show_table();
    Sudoku.Solve_table();
    Sudoku.Show_table();
	return 0;
}

/*Complete of above table
        5,3,4,6,7,8,9,1,2,
        6,7,2,1,9,5,3,4,8,
        1,9,8,3,4,2,5,6,7,
        8,5,9,7,6,1,4,2,3,
        4,2,6,8,5,3,7,9,1,
        7,1,3,9,2,4,8,5,6,
        9,6,1,5,3,7,2,8,4,
        2,8,7,4,1,9,6,3,5,
        3,4,5,2,8,6,1,7,9
*/

/*
r/c>0   1   2   3   4   5   6   7   8
V.....................................
0.  0   1   2   3   4   5   6   7   8
1.  9   10  11  12  13  14  15  16  17
2.  18  19  20  21  22  23  24  25  26
3.  27  28  29  30  31  32  33  34  35
4.  36  37  38  39  40  41  42  43  44
5.  45  46  47  48  49  50  51  52  53
6.  54  55  56  57  58  59  60  61  62
7.  63  64  65  66  67  68  69  70  71
8.  72  73  74  75  76  77  78  79  80
*/
#include "Sudoku_cell.hpp"
class Sudoku_table
{
    private:
		Sudoku_cell cells[81];
        unsigned char empty_cells=81;
    public:
        bool Check_one_row(const unsigned char fix_row);
        bool Check_one_column(const unsigned char fix_column);
        bool Check_one_block(const unsigned char fix_block);
        void Solve_table(void);
        bool Solve_cell(unsigned char id);
        void Get_table(unsigned char* s);
        void Get_table(void);
        void Show_table(void);
        void Check_cell_properties(unsigned char id);
        char Get_Emty_cells(void);
};
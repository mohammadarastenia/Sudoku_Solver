class Sudoku_table;
class Sudoku_cell
{
private:
    char block;
    char row;
    char column;
    char value;
    bool is_solved;
    bool canbe_x[9];
    char ID;
    static char unic_id;
public:
    Sudoku_cell();
    
    void Set_cell_block(char b);
    void Set_cell_row(char r);
    void Set_cell_column(char c);
    void Set_cell_value(char v);
    void Set_cell_solve_status(bool s);
    void Set_cell_canbe_x_status(unsigned char x,bool s);
    void Set_cell_id(char id);

    char Get_cell_block();
    char Get_cell_row();
    char Get_cell_column();
    char Get_cell_value();
    bool Get_cell_solve_status();
    bool Get_cell_canbe_x_status(unsigned char x);
    char Get_cell_id();
    friend class Sudoku_table;
    ~Sudoku_cell();
};

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
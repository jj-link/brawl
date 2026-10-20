#pragma force_active on
struct Row {
    unsigned int* entries[100];
};

struct Menu {
    unsigned char padding[0x8C];
    Row rows[1];
};

extern "C" unsigned char fn_2_36D68(Menu* base, int row, int col)
{
    return ((unsigned char*)base)[*base->rows[row].entries[col] + 0x13CF];
}

#pragma force_active on
typedef unsigned int u32;

struct FtKirbyWork {
    char pad[0xc];
    u32 *table;
};

extern "C" void fn_96_F5A8(FtKirbyWork *work, u32 value, u32 index)
{
    work->table[index] += value;
}

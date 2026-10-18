#pragma force_active on
typedef unsigned int u32;

struct FtGwWork {
    char pad[0x1c];
    u32 *table;
};

extern "C" void fn_107_C54C(FtGwWork *work, u32 index)
{
    work->table[index] = 0;
}

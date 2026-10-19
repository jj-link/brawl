#pragma force_active on
typedef unsigned int u32;

struct PeachFlagTable
{
    unsigned char padding[0x1C];
    u32* values;
};

extern "C" bool fn_103_A124(PeachFlagTable* table, u32 mask, int index)
{
    return (mask & table->values[index]) != 0;
}

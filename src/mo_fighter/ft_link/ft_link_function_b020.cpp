#include <types.h>
#pragma force_active on

struct UnknownStruct {
    u32 m0;
    u32 m1;
};

struct UnknownTable {
    u32 m0;
    UnknownStruct mMembers[2];
};

extern "C" UnknownStruct *fn_93_B020(UnknownTable *table, int index)
{
    return &table->mMembers[index];
}

#include <types.h>
#pragma force_active on

extern "C" extern unsigned char lbl_109_data_6168[];

struct FighterInfo {
    unsigned long entries[16];
};

extern "C" FighterInfo *fn_109_C45C(FighterInfo *info)
{
    info->entries[0] = (unsigned long)&lbl_109_data_6168;
    return info;
}
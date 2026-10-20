#include <types.h>
#pragma force_active on

struct FlagHolder {
    u32 unk0;
    u32 unk4;
    u32 mFlags;
};

extern "C" {

int fn_27_1CFAC4(FlagHolder* holder)
{
    return (holder->mFlags >> 13) & 1;
}

}


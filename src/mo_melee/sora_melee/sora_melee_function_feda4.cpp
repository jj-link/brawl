#include <types.h>
#pragma force_active on

struct BitfieldHolder {
    u32 m0;
    u32 m4;
    s32 m8;
};

extern "C" {

s32 fn_27_FEDA4(BitfieldHolder* a)
{
    return a->m8 >> 26;
}

}

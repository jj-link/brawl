#include <types.h>
#pragma force_active on

struct BitfieldHolder {
    u32 pad0;
    u32 pad4;
    s32 bitfields;
};

extern "C" {

s32 fn_27_1CFD38(BitfieldHolder* obj)
{
    return obj->bitfields >> 27;
}

}

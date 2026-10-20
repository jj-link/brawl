#include <types.h>
#pragma force_active on

extern "C" {

struct __bitfield {
    s32 unk0;
    s32 unk4;
    s32 low : 10;
    s32 field : 10;
    s32 high : 12;
};

s32 fn_27_1A3DAC(const struct __bitfield* p)
{
    return p->field;
}

}

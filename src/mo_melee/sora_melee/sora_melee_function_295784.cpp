#include <types.h>
#pragma force_active on

struct FnParam {
    u8 pad[8];
    u32 bits;
};

extern "C" s32 fn_27_295784(FnParam* p)
{
    return (s32)(((p->bits >> 16) & 0x3F) << 26) >> 27;
}

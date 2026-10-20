#include <types.h>
#pragma force_active on

struct ftX {
    u32 unk0;
    u32 unk4;
    union {
        struct {
            u32 low : 15;
            u32 flag : 1;
            u32 high : 16;
        };
        u32 raw;
    } field8;
};

extern "C" {
u32 fn_27_295770(ftX* self)
{
    return self->field8.flag;
}
}

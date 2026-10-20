#include <types.h>
#pragma force_active on

struct _ftClassInfo {
    u32 unk0;
    u32 unk4;
    u32 low : 9;
    u32 flag : 1;
    u32 high : 22;
};

extern "C" int fn_27_1A7550(_ftClassInfo *self) {
    return self->flag;
}

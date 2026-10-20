#include <types.h>
#pragma force_active on

struct FlagObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1A45FC(FlagObj* p) {
    p->flags |= 0x2;
}

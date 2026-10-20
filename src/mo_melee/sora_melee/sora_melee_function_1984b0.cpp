#include <types.h>
#pragma force_active on

struct FlagHolder {
    u32 unk0;
    u32 unk4;
    u32 : 3;
    u32 field : 3;
    u32 : 26;
};

extern "C" void fn_27_1984B0(FlagHolder* p, u32 v) {
    p->field = v;
}

#include <types.h>
#pragma force_active on

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 field : 4;
    u32 rest : 28;
};

extern "C" void fn_27_19F868(Obj* p, u32 value) {
    p->field = value;
}

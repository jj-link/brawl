#include <types.h>
#pragma force_active on

struct FF148Obj {
    u32 unk0;
    u32 unk4;
    u32 type : 4;
    u32 rest : 28;
};

extern "C" {
void fn_27_FF148(FF148Obj* obj, u32 value) {
    obj->type = value;
}
}

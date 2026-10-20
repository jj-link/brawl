#include <types.h>
#pragma force_active on

struct Param {
    u32 unk0;
    float unk4;
};

struct Object {
    u32 unk0;
    u32 unk4;
    float unk8;
};

extern "C" void fn_27_1DC32C(Object* obj, u32 index, const Param* param) {
    obj->unk8 = param->unk4;
}

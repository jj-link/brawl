#include <types.h>
#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

struct Obj {
    u32 unk0;
    u32 unk4;
    Vec3f pos;
};

extern const float lbl_27_rodata_BC0;

extern "C" void fn_27_8A9C8(Obj* obj) {
    Vec3f tmp;
    tmp.x = lbl_27_rodata_BC0;
    tmp.y = lbl_27_rodata_BC0;
    tmp.z = lbl_27_rodata_BC0;
    obj->pos = tmp;
}

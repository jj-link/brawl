#include <types.h>
#pragma force_active on

extern "C" const float lbl_10_rodata_6A8;

struct Vec3f {
    float x;
    float y;
    float z;
};

#pragma dont_inline on
extern "C" void fn_10_1C97C(Vec3f* a, int b, int c, Vec3f* d);
#pragma dont_inline reset

extern "C" void fn_10_18614(void* obj) {
    u8* base = (u8*)obj;
    int val = *(int*)(base + 0x1d4);
    Vec3f local;
    local.z = lbl_10_rodata_6A8;
    local.y = lbl_10_rodata_6A8;
    local.x = lbl_10_rodata_6A8;
    fn_10_1C97C((Vec3f*)(base + 0x1fc), 1, val, &local);
}

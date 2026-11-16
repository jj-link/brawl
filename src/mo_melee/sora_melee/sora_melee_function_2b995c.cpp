#pragma force_active on
#include <types.h>

extern "C" const f32 lbl_27_rodata_5EBC;

class SubObj {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void run(s32, f32*, s32, s32) = 0;
};

struct Vec3 {
    f32 x, y, z;
    Vec3(f32 a, f32 b, f32 c) : x(a), y(b), z(c) {}
};

extern "C" void fn_27_2B995C(void* self, s32 arg1, const f32* arg2, s32 arg3) {
    f32 local[2];
    local[0] = lbl_27_rodata_5EBC;
    local[1] = lbl_27_rodata_5EBC;
    ((SubObj*)((char*)self + 0x168))->run(-1, local, arg1, arg3);
    *(f32*)((char*)self + 0x188) = lbl_27_rodata_5EBC;
    *(f32*)((char*)self + 0x18C) = lbl_27_rodata_5EBC;
    *(f32*)((char*)self + 0x190) = lbl_27_rodata_5EBC;
    *(f32*)((char*)self + 0x194) = arg2[0];
    *(f32*)((char*)self + 0x198) = arg2[1];
    *(f32*)((char*)self + 0x19C) = arg2[2];
    *((u8*)self + 0x16D) |= 0x80;
    f32 tail[3];
    *(f32*)((char*)&tail + 0) = lbl_27_rodata_5EBC;
    *(f32*)((char*)&tail + 4) = lbl_27_rodata_5EBC;
    *(f32*)((char*)&tail + 8) = lbl_27_rodata_5EBC;
}
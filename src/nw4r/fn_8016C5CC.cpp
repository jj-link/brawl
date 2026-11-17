#include <types.h>
#pragma force_active on

extern const f32 lbl_805A2D28;
extern const f32 lbl_805A2D2C;

class Object_vptr_0 {
public:
    virtual s32 slot0(u8 a, void* b, f32 d);
};

extern "C" s32 fn_8016C5CC(u8* self, u8* arg1, u8* arg2) {
    f32 zero = lbl_805A2D2C;
    f32 one = lbl_805A2D28;
    *(s32*)(self + 0x10) = 0;
    *(s32*)(self + 0xC) = 1;
    *(s32*)(self + 0x38) = 0;
    *(s16*)(self + 0x40) = 0;
    *(s32*)(self + 0x3C) = 0;
    *(s32*)(self + 0x44) = 0;
    *(s16*)(self + 0x4C) = 0;
    *(s32*)(self + 0x48) = 0;
    *(s16*)(self + 0x50) = 0;
    *(f32*)(self + 0x58) = one;
    *(f32*)(self + 0x5C) = one;
    *(f32*)(self + 0x60) = zero;
    *(f32*)(self + 0x64) = zero;
    *(f32*)(self + 0x68) = zero;
    *(u8**)(self + 0x20) = arg1;
    s32 r6 = *(s32*)(arg1 + 0x10);
    *(s32*)(arg1 + 0x10) = r6 + 1;
    *(u8**)(self + 0x24) = arg2;
    *(s32*)(self + 0x28) = 0;
    *(u8*)(self + 0x8A) = 1;
    Object_vptr_0* obj = *(Object_vptr_0**)(*(u8**)(*(u8**)(*(u8**)(self + 0x20) + 0xBC) + 0x20) + 0x8);
    s32 ret = obj->slot0(arg2[0x13C], arg2, one);
    *(s32*)(self + 0x2C) = ret;
    *(s32*)(self + 0x54) = 0;
    f32 v78 = *(f32*)(arg2 + 0x110);
    self[0x6C] = arg2[0x107];
    self[0x6D] = arg2[0x108];
    self[0x6E] = arg2[0x109];
    self[0x6F] = arg2[0x10A];
    self[0x70] = arg2[0x10B];
    self[0x71] = arg2[0x10C];
    self[0x72] = arg2[0x10D];
    self[0x73] = arg2[0x10E];
    self[0x74] = arg2[0x10F];
    *(f32*)(self + 0x78) = v78;
    *(f32*)(self + 0x7C) = *(f32*)(arg2 + 0x114);
    *(f32*)(self + 0x80) = *(f32*)(arg2 + 0x118);
    *(f32*)(self + 0x84) = *(f32*)(arg2 + 0x11C);
    return 1;
}
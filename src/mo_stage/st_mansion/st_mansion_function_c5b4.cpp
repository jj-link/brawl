#include <types.h>
#include <revolution/OS/OSFastCast.h>

#pragma force_active on

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
extern "C" float fn_801622C4(float);
extern "C" const float lbl_47_rodata_110[];

extern "C" void fn_47_C5B4(u8* self) {
    const float* f = lbl_47_rodata_110;
    if (*(u8*)(self + 0x150) == 7) {
        u8* cb = self + 0xd0;
        if (cb != 0) {
            u8* model = *(u8**)(*(u8**)(self + 0x44));
            if (model != 0) {
                if (*(int*)(model + 0x11c) == 0) {
                    *(int*)(cb + 0xc) = 0;
                    *(int*)(*(u8**)(cb + 4)) = *(int*)(self + 0xc4);
                    *(u8**)(model + 0x11c) = cb;
                    EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                    *(short*)(model + 0x122) = (short)*(int*)(*(u8**)(cb + 4));
                }
                Vec3* src = *(Vec3**)(self + 0x168);
                if (src != 0) {
                    Vec3 v;
                    v.x = src->x;
                    v.y = src->y;
                    v.z = src->z;
                    float amount = f[9] - *(float*)(self + 0x164) / f[3];
                    if (amount < f[0])
                        amount = f[0];
                    if (amount > f[9])
                        amount = f[9];
                    u16 angle = (u16)(f[10] * amount);
                    float value = fn_801622C4(f[11] * __OSu16tof32(&angle));
                    u8* dst = *(u8**)(cb + 4);
                    v.y = v.y - f[2] * value;
                    *(float*)(dst + 8) = v.x;
                    *(float*)(dst + 0xc) = v.y;
                    *(float*)(dst + 0x10) = v.z;
                }
            }
        }
    }
}

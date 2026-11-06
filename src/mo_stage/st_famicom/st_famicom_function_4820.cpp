#include <types.h>
#pragma force_active on

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
extern "C" const float lbl_68_rodata_88[];

extern "C" void fn_68_4820(u8* self) {
    const float* f = lbl_68_rodata_88;
    u8* cb = self + 0xd0;
    if (cb != 0) {
        u8* model = *(u8**)(*(u8**)(self + 0x44));
        if (model != 0) {
            if (*(u32*)(model + 0x11c) == 0) {
                *(u32*)(cb + 0xc) = 0;
                **(u32**)(cb + 4) = *(u32*)(self + 0xc4);
                *(u8**)(model + 0x11c) = cb;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                *(u16*)(model + 0x122) = (u16)**(u32**)(cb + 4);
            }
            Vec3* src = *(Vec3**)(self + 0x15c);
            if (src != 0) {
                s32 sw = *(u8*)(self + 0x164);
                float t;
                switch (sw) {
                case 0:
                    t = f[4];
                    break;
                case 1:
                    t = f[5];
                    break;
                case 2:
                    t = f[6];
                    break;
                default:
                    t = f[7];
                    break;
                }
                Vec3 v;
                v.x = src->x;
                v.y = src->y;
                v.z = src->z;
                u8* dst = *(u8**)(cb + 4);
                *(float*)(dst + 0x8) = v.x;
                v.y = v.y + f[9] * (f[4] - t);
                *(float*)(dst + 0xc) = v.y;
                *(float*)(dst + 0x10) = v.z;
                dst = *(u8**)(cb + 4);
                *(float*)(dst + 0x20) = f[4];
                *(float*)(dst + 0x24) = t;
                *(float*)(dst + 0x28) = f[4];
            }
        }
    }
}

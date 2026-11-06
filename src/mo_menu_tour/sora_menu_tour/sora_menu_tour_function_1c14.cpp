#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern const float lbl_3_rodata_8120;
extern "C" void fn_3_131C(void*, int);

extern "C" void fn_3_1C14(u8* self, u32 value, int arg2) {
    u8* p = self;
    for (u32 i = 0; i < *(u32*)(self + 0xB90); p += 4, i++) {
        int n = *(int*)(p + 0xF14);
        Vec3f t;
        t = *(Vec3f*)(*(u8**)(self + 0xFD0 + n * 4) + 0x3C);
        if (value == *(u32*)(self + 0xBAC + n * 0x1C)) {
            *(u32*)(self + 0xF28) = i;
            *(float*)(p + 0xF2C) = t.m_y;
            fn_3_131C(self, *(int*)(p + 0xF14));
            u8* e = self + *(int*)(p + 0xF14) * 0x1C;
            u8 b = e[0xB95 + e[0xB94] * 2];
            t = *(Vec3f*)(*(u8**)(self + 4 + b * 4) + 0x3C);
            *(float*)(p + 0xF3C) = t.m_y;
        } else {
            *(float*)(p + 0xF2C) = t.m_x;
            u8* e = self + *(int*)(p + 0xF14) * 0x1C;
            u8 b = e[0xB95 + e[0xB94] * 2];
            if (b == 0) {
                *(float*)(p + 0xF3C) = lbl_3_rodata_8120;
            } else {
                t = *(Vec3f*)(*(u8**)(self + 4 + b * 4) + 0x3C);
                *(float*)(p + 0xF3C) = t.m_x;
            }
        }
    }
    *(int*)(self + 0xF4C) = arg2;
    *(int*)(self + 0xF24) = 0;
}
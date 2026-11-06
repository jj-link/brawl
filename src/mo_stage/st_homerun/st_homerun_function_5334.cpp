#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#pragma force_active on

extern "C" void fn_88_5334(u8* self) {
    u8* p = self + 0xD0;
    if (p != 0) {
        u8* a = *(u8**)(self + 0x44);
        nw4r::g3d::ScnMdlSimple* m = *(nw4r::g3d::ScnMdlSimple**)a;
        if (m != 0) {
            if (*(u32*)((u8*)m + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                *(u32*)(*(u8**)(p + 4)) = *(u32*)(self + 0x1cc);
                *(u32*)(*(u8**)(p + 4) + 0x80) = *(u32*)(self + 0x1d4);
                *(u32*)(*(u8**)(p + 4) + 0x100) = *(u32*)(self + 0x1dc);
                *(u32*)(*(u8**)(p + 4) + 0x180) = *(u32*)(self + 0x1d0);
                *(u32*)(*(u8**)(p + 4) + 0x200) = *(u32*)(self + 0x1e0);
                *(u32*)(*(u8**)(p + 4) + 0x280) = *(u32*)(self + 0x1d8);
                *(u8**)((u8*)m + 0x11c) = p;
                m->EnableScnMdlCallbackTiming(1);
                *(u16*)((u8*)m + 0x122) = (u16)**(u32**)(p + 4);
            }
            float* d = *(float**)(p + 4);
            d[2] = *(float*)(self + 0x184);
            d[3] = *(float*)(self + 0x188);
            d[4] = *(float*)(self + 0x18c);
            d = *(float**)(p + 4);
            d[34] = *(float*)(self + 0x19c);
            d[35] = *(float*)(self + 0x1a0);
            d[36] = *(float*)(self + 0x1a4);
            d = *(float**)(p + 4);
            d[66] = *(float*)(self + 0x1b4);
            d[67] = *(float*)(self + 0x1b8);
            d[68] = *(float*)(self + 0x1bc);
            d = *(float**)(p + 4);
            d[98] = *(float*)(self + 0x190);
            d[99] = *(float*)(self + 0x194);
            d[100] = *(float*)(self + 0x198);
            d = *(float**)(p + 4);
            d[130] = *(float*)(self + 0x1c0);
            d[131] = *(float*)(self + 0x1c4);
            d[132] = *(float*)(self + 0x1c8);
            d = *(float**)(p + 4);
            d[162] = *(float*)(self + 0x1a8);
            d[163] = *(float*)(self + 0x1ac);
            d[164] = *(float*)(self + 0x1b0);
        }
    }
}
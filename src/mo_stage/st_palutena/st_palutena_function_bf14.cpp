#pragma force_active on
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
extern "C" const float lbl_67_rodata_168;
extern "C" void fn_67_BF14(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* p = s + 0xD0;
    if (p != 0) {
        unsigned char* a = *(unsigned char**)(s + 0x44);
        unsigned char* m = *(unsigned char**)a;
        if (m != 0) {
            if (*(unsigned int*)(m + 0x11C) == 0) {
                *(unsigned int*)(p + 0xC) = 0;
                unsigned int srcOffset;
                unsigned int dstOffset;
                unsigned int count;
                count = 0;
                srcOffset = 0;
                dstOffset = 0;
                for (int i = 0; i < 3; i++) {
                    count += 7;
                    *(unsigned int*)(*(unsigned char**)(p + 4) + dstOffset + 0x00) = *(unsigned int*)(*(unsigned char**)(s + 0x168) + srcOffset + 0x00);
                    *(unsigned int*)(*(unsigned char**)(p + 4) + dstOffset + 0x80) = *(unsigned int*)(*(unsigned char**)(s + 0x168) + srcOffset + 0x04);
                    *(unsigned int*)(*(unsigned char**)(p + 4) + dstOffset + 0x100) = *(unsigned int*)(*(unsigned char**)(s + 0x168) + srcOffset + 0x08);
                    *(unsigned int*)(*(unsigned char**)(p + 4) + dstOffset + 0x180) = *(unsigned int*)(*(unsigned char**)(s + 0x168) + srcOffset + 0x0C);
                    *(unsigned int*)(*(unsigned char**)(p + 4) + dstOffset + 0x200) = *(unsigned int*)(*(unsigned char**)(s + 0x168) + srcOffset + 0x10);
                    *(unsigned int*)(*(unsigned char**)(p + 4) + dstOffset + 0x280) = *(unsigned int*)(*(unsigned char**)(s + 0x168) + srcOffset + 0x14);
                    *(unsigned int*)(*(unsigned char**)(p + 4) + dstOffset + 0x300) = *(unsigned int*)(*(unsigned char**)(s + 0x168) + srcOffset + 0x18);
                    srcOffset += 0x1C;
                    dstOffset += 0x380;
                }
                *(unsigned int*)(*(unsigned char**)(p + 4) + count * 0x80) = *(unsigned int*)(*(unsigned char**)(s + 0x168) + count * 4);
                *(unsigned int*)(*(unsigned char**)(p + 4) + count * 0x80 + 0x80) = *(unsigned int*)(*(unsigned char**)(s + 0x168) + count * 4 + 4);
                *(unsigned char**)(m + 0x11C) = s + 0xD0;
                ((nw4r::g3d::ScnMdlSimple*)m)->EnableScnMdlCallbackTiming(1);
                *(short*)(m + 0x122) = (short)**(unsigned int**)(p + 4);
            }
            unsigned int i5 = 0;
            unsigned int i6 = 0;
            unsigned int i7 = 0;
            for (int i = 0; i < 0x17; i++) {
                *(nw4r::math::VEC3*)(*(unsigned char**)(p + 4) + i6 + 8) =
                    *(nw4r::math::VEC3*)(*(unsigned char**)(s + 0x15C) + i5);
                i5 += 12;
                float angle = *(float*)(*(unsigned char**)(s + 0x160) + i7);
                unsigned char* destination = *(unsigned char**)(p + 4) + i6;
                *(float*)(destination + 0x14) = lbl_67_rodata_168;
                *(float*)(destination + 0x18) = lbl_67_rodata_168;
                *(float*)(destination + 0x1C) = angle;
                i6 += 0x80;
                i7 += 4;
            }
        }
    }
}

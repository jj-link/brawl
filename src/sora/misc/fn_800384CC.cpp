#include <revolution/GX/GXTypes.h>
#pragma force_active on

extern "C" void fn_801E8DC8(void*);
extern "C" void fn_801E98B0(void);
extern unsigned char lbl_80423488[];

extern "C" void fn_800384CC(unsigned char* arg0, unsigned int arg1) {
    unsigned char b = arg0[0x4C];

    if (((b >> 5) & 1) != arg1) {
        b = GX_BITSET(b, 26, 1, arg1);
        arg0[0x4C] = b;

        unsigned short state = 0;
        if ((b >> 5) & 1) {
            state = 1;
        }

        unsigned int offset = ((unsigned int)state << 3) & 0x7FFF8;
        unsigned int index = *(unsigned int*)(arg0 + 0x50) * 16;
        unsigned char* entry = lbl_80423488 + index;
        entry = (unsigned char*)((unsigned int)entry + offset);
        unsigned short height =
            *(unsigned short*)((unsigned int)lbl_80423488 + offset + index);
        int diff = 0x2D0 - height;

        *(float*)(arg0 + 0x44) = *(float*)(entry + 4);
        *(unsigned short*)(arg0 + 0x0E) = height;
        *(short*)(arg0 + 0x0A) = diff / 2;

        fn_801E8DC8(arg0);
        fn_801E98B0();
    }
}

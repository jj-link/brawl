#include <types.h>
#pragma force_active on

extern const int lbl_27_rodata_DE8[5];
extern "C" void cmRemoveQuake__Fi(int idx);

extern "C" void fn_27_B49B0(void* self, int type) {
    if (type == 3) {
        unsigned char flags = ((unsigned char*)self)[0x14];
        if (((flags >> 6) & 1) == 0) {
            return;
        }
        ((unsigned char*)self)[0x14] = flags & ~0x40;
    }
    cmRemoveQuake__Fi(lbl_27_rodata_DE8[type]);
}

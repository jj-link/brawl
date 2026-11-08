#include <revolution/GX/GXHardware.h>
#pragma force_active on
extern "C" unsigned char lbl_805A32F8;
extern "C" void fn_8019DB1C(int index) {
 GX_BP_LOAD_REG(0xFE00C000);
 unsigned char value = *(&lbl_805A32F8 + index);
 *(unsigned char*)0xCC008000 = 0x61;
 *(unsigned int*)0xCC008000 = (unsigned int)value << 14;
}

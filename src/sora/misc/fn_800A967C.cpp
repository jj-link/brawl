#include <string.h>
#pragma force_active on

extern "C" void fn_800A967C(void* dest, void* src) {
    memset(dest, 0, 0x28);
    *(float*)((char*)dest + 0x00) = *(float*)((char*)src + 0x28);
    *(float*)((char*)dest + 0x04) = *(float*)((char*)src + 0x2C);
    *(float*)((char*)dest + 0x08) = *(float*)((char*)src + 0x30);
    *(float*)((char*)dest + 0x0C) = *(float*)((char*)src + 0x34);
    *(float*)((char*)dest + 0x10) = *(float*)((char*)src + 0x38);
    *(float*)((char*)dest + 0x14) = *(float*)((char*)src + 0x3C);
    *(int*)((char*)dest + 0x18) = *(int*)((char*)src + 0x40);
    *(float*)((char*)dest + 0x1C) = *(float*)((char*)src + 0x44);
    *(float*)((char*)dest + 0x20) = *(float*)((char*)src + 0x48);
    *(float*)((char*)dest + 0x24) = *(float*)((char*)src + 0x4C);
}

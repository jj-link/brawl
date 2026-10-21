#pragma force_active on
#include <string.h>

extern "C" char g_thpObject[];

extern "C" int fn_8007D0F8(void* dest) {
    if (*(void**)(g_thpObject + 0xA0) != 0) {
        memcpy(dest, g_thpObject + 0x80, 0xC);
        return 1;
    }
    return 0;
}

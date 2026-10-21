#pragma force_active on
#include <string.h>

extern "C" char g_thpObject[];

extern "C" int fn_8007D140(void* p) {
    if (*(void**)(g_thpObject + 0xA0) != 0) {
        memcpy(p, g_thpObject + 0x8C, 0x10);
        return 1;
    }
    return 0;
}

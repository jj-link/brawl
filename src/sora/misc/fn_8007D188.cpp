#include <types.h>
#pragma force_active on

extern "C" char g_thpObject[];

extern "C" void* fn_8007D188(void) {
    if (*(void**)(g_thpObject + 0xA0) != 0) {
        return *(void**)(g_thpObject + 0x50);
    }
    return 0;
}

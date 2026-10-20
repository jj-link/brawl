#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_14548C(const void* self);
extern unsigned char g_ftCommonDataAccesser[];

void* fn_27_14D594() {
    return *(void**)((unsigned char*)fn_27_14548C(g_ftCommonDataAccesser) + 0x234);
}
}

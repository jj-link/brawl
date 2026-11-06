#include <types.h>
#pragma force_active on

extern void fn_80281BBC(void* dst, s32 src, s32 n);
extern int vsnprintf(char* s, u32 n, const char* fmt, void* ap);

void fn_8028196C(char* s, u32 n, const char* fmt, void* ap) {
    u32 sp8[3];
    fn_80281BBC(sp8, (s32)ap, 0xC);
    vsnprintf(s, n, fmt, sp8);
}

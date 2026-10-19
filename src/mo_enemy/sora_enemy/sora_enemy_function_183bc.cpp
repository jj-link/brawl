#pragma force_active on
typedef int s32;
typedef unsigned int u32;
typedef signed char s8;

extern "C" {
u32 fn_27_88118(void*, s8);

u32 fn_41_183BC(void* self, s32 c) {
    u32 ret = 0;
    if (fn_27_88118(self, (s8)c) == 1 || (s8)c == 0x66) {
        ret = 1;
    }
    return ret;
}
}

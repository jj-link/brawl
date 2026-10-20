#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_27_D0EB4(void *p) {
    u32 *flags = (u32 *)((char *)p + 8);
    *flags &= ~0x400;
}

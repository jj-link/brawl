#pragma force_active on
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
    void fn_41_300FC(void*, s16);
    void fn_41_2FD94(void*, s16);
    void __dl__FPv(void*);
}

extern "C" void* fn_41_30174(void* r3, s32 r4) {
    if (r3 != 0) {
        fn_41_300FC((char*)r3 + 0x1d54, -1);
        fn_41_2FD94(r3, 0);
        if ((s16)r4 > 0) {
            __dl__FPv(r3);
        }
    }
    return r3;
}

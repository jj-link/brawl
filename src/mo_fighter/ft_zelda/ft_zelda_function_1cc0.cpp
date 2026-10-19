#pragma force_active on
typedef int s32;
typedef short s16;

extern "C" {
void fn_104_1B48(void*, s16);
void __dl__FPv(void*);
void* fn_104_1CC0(void* p, s32 flag);
}

void* fn_104_1CC0(void* p, s32 flag) {
    if (p) {
        s16 zero = 0;
        fn_104_1B48(p, zero);
        if ((s16)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

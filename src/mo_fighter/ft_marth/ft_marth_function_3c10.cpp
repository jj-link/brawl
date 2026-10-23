#pragma force_active on
typedef short s16;

extern "C" {
void* fn_106_3C88(void*, s16);
void* fn_27_1A1E70(void*, s16);
void __dl__FPv(void*);

void* fn_106_3C10(void* p, s16 n) {
    if (p) {
        fn_27_1A1E70((char*)p + 0x190, (s16)-1);
        if (p) {
            fn_106_3C88(p, 0);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

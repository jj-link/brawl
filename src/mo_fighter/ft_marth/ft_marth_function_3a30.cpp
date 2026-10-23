#pragma force_active on
typedef short s16;

extern "C" {
void* fn_27_1A1B88(void*, s16);
void* fn_106_3AA8(void*, s16);
void __dl__FPv(void*);

void* fn_106_3A30(void* p, s16 n) {
    if (p != 0) {
        fn_27_1A1B88((char*)p + 0x2D0, (s16)-1);
        if (p != 0) {
            fn_106_3AA8(p, (s16)0);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

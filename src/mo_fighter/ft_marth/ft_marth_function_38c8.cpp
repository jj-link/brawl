#pragma force_active on
typedef short s16;

extern "C" {
void* fn_27_1A18A0(void*, s16);
void* fn_106_3940(void*, s16);
void __dl__FPv(void*);

void* fn_106_38C8(void* p, s16 n) {
    if (p != 0) {
        fn_27_1A18A0((char*)p + 0x354, (s16)-1);
        if (p != 0) {
            fn_106_3940(p, (s16)0);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

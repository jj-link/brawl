#pragma force_active on
typedef short s16;

extern "C" {
void* fn_27_1A1B88(void*, s16);
void* fn_106_3E68(void*, s16);
void __dl__FPv(void*);

void* fn_106_3DF0(void* p, s16 n) {
    if (p) {
        fn_27_1A1B88((char*)p + 0xF0, (s16)-1);
        if (p) {
            fn_106_3E68(p, (s16)0);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

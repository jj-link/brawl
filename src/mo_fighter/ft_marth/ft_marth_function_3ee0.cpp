#pragma force_active on
typedef short s16;

extern "C" void* fn_27_1A1B88(void*, s16);
extern "C" void* fn_106_3F58(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_3EE0(void* p, s16 n) {
    if (p) {
        fn_27_1A1B88((char*)p + 0x88, -1);
        if (p) {
            fn_106_3F58(p, 0);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

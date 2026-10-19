#pragma force_active on
typedef short s16;

extern "C" void* fn_106_8D88(void*, s16);
extern "C" void* fn_106_8C50(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_8DE8(void* p, s16 n) {
    if (p) {
        fn_106_8D88((char*)p + 0xEC, -1);
        if (p) {
            fn_106_8C50(p, 0);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

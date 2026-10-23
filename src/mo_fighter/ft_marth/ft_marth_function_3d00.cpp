#pragma force_active on
typedef short s16;

extern "C" void* fn_27_1A15B8(void*, s16);
extern "C" void* fn_106_3D78(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_3D00(void* p, s16 n) {
    if (p) {
        fn_27_1A15B8((char*)p + 0x138, -1);
        if (p) {
            fn_106_3D78(p, 0);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

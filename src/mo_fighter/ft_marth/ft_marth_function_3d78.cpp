#pragma force_active on

extern "C" {
void* fn_27_1A15B8(void*, short);
void* fn_106_3DF0(void*, short);
void __dl__FPv(void*);

void* fn_106_3D78(void* p, short n) {
    if (p != 0) {
        fn_27_1A15B8((char*)p + 0x11C, (short)-1);
        if (p != 0) {
            fn_106_3DF0(p, (short)0);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

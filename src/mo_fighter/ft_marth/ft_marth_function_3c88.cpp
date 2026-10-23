#pragma force_active on
typedef short s16;

extern "C" {
void* fn_27_D2904(void* member, s16 deleteFlag);
void* fn_106_3D00(void* p, s16 n);
void __dl__FPv(void* p);

void* fn_106_3C88(void* p, s16 n) {
    if (p) {
        fn_27_D2904((char*)p + 0x154, -1);
        if (p) {
            fn_106_3D00(p, 0);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

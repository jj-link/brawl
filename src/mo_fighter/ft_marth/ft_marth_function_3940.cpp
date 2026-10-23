#pragma force_active on
typedef short s16;

extern "C" {
void* fn_27_D2904(void* member, s16 deleteFlag);
void* fn_106_39B8(void* p, s16 flag);
void __dl__FPv(void* p);

void* fn_106_3940(void* p, s16 n) {
    if (p != 0) {
        fn_27_D2904((char*)p + 0x318, (s16)-1);
        if (p != 0) {
            fn_106_39B8(p, (s16)0);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

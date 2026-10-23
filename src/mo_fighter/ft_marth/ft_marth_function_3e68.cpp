#pragma force_active on
extern "C" {
void* fn_27_D2904(void* member, short deleteFlag);
void* fn_106_3EE0(void* p, short flag);
void __dl__FPv(void* p);

void* fn_106_3E68(void* p, short flag) {
    if (p != 0) {
        fn_27_D2904((char*)p + 0xB4, (short)-1);
        if (p != 0) {
            fn_106_3EE0(p, (short)0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

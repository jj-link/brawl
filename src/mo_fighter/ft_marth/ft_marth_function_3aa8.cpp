#pragma force_active on
extern "C" {
void* fn_27_1A1FE4(void*, short);
void* fn_106_3B20(void*, short);
void __dl__FPv(void*);

void* fn_106_3AA8(void* p, int flag) {
    if (p != 0) {
        fn_27_1A1FE4((char*)p + 0x244, (short)-1);
        if (p != 0) {
            fn_106_3B20(p, (short)0);
        }
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

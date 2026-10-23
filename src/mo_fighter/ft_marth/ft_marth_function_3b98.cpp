#pragma force_active on
extern "C" {
void* fn_27_1A15B8(void*, short);
void* fn_106_3C10(void*, short);
void __dl__FPv(void*);

void* fn_106_3B98(void* p, int flag) {
    if (p != 0) {
        fn_27_1A15B8((char*)p + 0x1FC, (short)-1);
        if (p != 0) {
            fn_106_3C10(p, (short)0);
        }
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

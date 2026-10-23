#pragma force_active on
extern "C" {
void* fn_27_1A1E70(void*, short);
void* fn_106_37D8(void*, short);
void __dl__FPv(void*);

void* fn_106_3760(void* p, int flag) {
    if (p != 0) {
        fn_27_1A1E70((char*)p + 0x4B8, (short)-1);
        if (p != 0) {
            fn_106_37D8(p, (short)0);
        }
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

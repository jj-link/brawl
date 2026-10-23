#pragma force_active on
extern "C" {
void* fn_27_1A1CFC(void*, short);
void* fn_106_3760(void*, short);
void __dl__FPv(void*);

void* fn_106_36E8(void* p, int flag) {
    if (p != 0) {
        fn_27_1A1CFC((char*)p + 0x524, (short)-1);
        if (p != 0) {
            fn_106_3760(p, (short)0);
        }
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

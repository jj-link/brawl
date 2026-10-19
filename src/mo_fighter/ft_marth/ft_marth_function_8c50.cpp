#pragma force_active on
extern "C" {
void* fn_106_8BF0(void*, short);
void* fn_106_8AC0(void*, short);
void __dl__FPv(void*);

void* fn_106_8C50(void* p, int flag) {
    if (p != 0) {
        fn_106_8BF0((char*)p + 0x94, (short)-1);
        if (p != 0) {
            fn_106_8AC0(p, (short)0);
        }
        if ((short)flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

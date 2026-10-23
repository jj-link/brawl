#pragma force_active on
extern "C" {
void* fn_27_1A1B88(void*, short);
void* fn_106_3850(void*, short);
void __dl__FPv(void*);

void* fn_106_37D8(void* p, short flag) {
    if (p != 0) {
        fn_27_1A1B88((char*)p + 0x48C, (short)-1);
        if (p != 0) {
            fn_106_3850(p, (short)0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

#pragma force_active on
extern "C" {
void* fn_27_1A3940(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_125_6574(void* p, short flag) {
    if (p != 0) {
        fn_27_1A3940(p, (short)-1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

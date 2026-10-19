#pragma force_active on
extern "C" {
void fn_125_1B84(void* p, short flag);
void __dl__FPv(void* p);

void* fn_125_1CFC(void* p, short flag) {
    if (p != 0) {
        fn_125_1B84(p, (short)0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}

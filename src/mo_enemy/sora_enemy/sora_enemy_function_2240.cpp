#pragma force_active on
extern "C" void fn_27_D4380(void* self, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_2240(void* p, short flag) {
    if (p != 0) {
        fn_27_D4380(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

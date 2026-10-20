#pragma force_active on
extern "C" void* fn_27_1A4D90(void* ptr, short count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_113_2CC54(void* p, short flag) {
    if (p != 0) {
        fn_27_1A4D90(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

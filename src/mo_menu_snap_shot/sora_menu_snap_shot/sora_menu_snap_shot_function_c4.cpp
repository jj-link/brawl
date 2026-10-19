#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void fn_6_1E4(void* self, int flag);

extern "C" void* fn_8_C4(void* p, int flag) {
    if (p != 0) {
        fn_6_1E4(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

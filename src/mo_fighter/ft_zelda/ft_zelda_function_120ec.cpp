#pragma force_active on
extern "C" void* fn_104_12148(void* p, short size);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_104_120EC(void* p, short size) {
    if (p != 0) {
        fn_104_12148(p, 0);
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

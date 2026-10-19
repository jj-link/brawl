#pragma force_active on
extern "C" void* fn_41_2D204(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2D244(void* p, short mode) {
    if (p != 0) {
        fn_41_2D204(p, 0);
        if (mode > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

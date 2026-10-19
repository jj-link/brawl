#pragma force_active on
extern "C" void* fn_125_4CD8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_CB30(void* p, short flag) {
    if (p != 0) {
        short zero = 0;
        fn_125_4CD8(p, zero);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

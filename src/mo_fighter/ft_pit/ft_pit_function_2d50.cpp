#pragma force_active on
extern "C" void* fn_27_BED74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_2D50(void* p, short flag) {
    if (p != 0) {
        fn_27_BED74(p, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

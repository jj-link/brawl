#pragma force_active on
extern "C" void* fn_27_BED74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_14B28(void* p1, short p2) {
    if (p1 != 0) {
        fn_27_BED74(p1, static_cast<short>(-1));
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}

#pragma force_active on
extern "C" void* fn_27_D3B50(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2D8F4(void* p0, short p1) {
    if (p0) {
        fn_27_D3B50(p0, 0);
        if (p1 > 0)
            __dl__FPv(p0);
    }
    return p0;
}

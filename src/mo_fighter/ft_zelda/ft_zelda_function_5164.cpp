#pragma force_active on
extern "C" void* fn_27_1A2D10(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_5164(void* p, short del) {
    if (p != 0) {
        fn_27_1A2D10(p, -1);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

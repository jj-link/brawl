#pragma force_active on
extern "C" void* fn_27_BED74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_2B1C(void* p, short del) {
    if (p != 0) {
        fn_27_BED74(p, -1);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

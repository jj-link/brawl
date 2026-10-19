#pragma force_active on
extern "C" void* fn_27_A1E80(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2F9A4(void* p, short del) {
    if (p != 0) {
        fn_27_A1E80(p, -1);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

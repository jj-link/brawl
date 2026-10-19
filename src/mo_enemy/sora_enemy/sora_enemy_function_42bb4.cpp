#pragma force_active on
extern "C" void* fn_41_42B58(void*, short);
extern "C" void* fn_41_33D4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_42BB4(void* p1, short p2) {
    if (p1 != 0) {
        fn_41_42B58(reinterpret_cast<char*>(p1) + 8, -1);
        fn_41_33D4C(p1, 0);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}

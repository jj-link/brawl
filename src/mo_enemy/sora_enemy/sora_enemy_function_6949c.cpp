#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void fn_41_69430(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_6949C(char* p, short flag) {
    if (p) {
        fn_41_69BF0(p + 0x98, -1);
        fn_41_69430(p + 4, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

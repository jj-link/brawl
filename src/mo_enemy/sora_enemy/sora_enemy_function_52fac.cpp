#pragma force_active on
extern "C" void fn_41_53118(void*, short);
extern "C" void fn_41_52F40(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_52FAC(void* p1, short p2) {
    if (p1 != 0) {
        fn_41_53118((char*)p1 + 0x68, -1);
        fn_41_52F40((char*)p1 + 4, -1);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}

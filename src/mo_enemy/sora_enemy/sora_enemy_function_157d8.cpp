#pragma force_active on
extern "C" void fn_27_C7A94(void* p, short flag);
extern "C" void* fn_41_15778(void* p1, short p2);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_157D8(void* p1, short p2) {
    if (p1 != 0) {
        fn_27_C7A94((char*)p1 + 0x10, -1);
        fn_41_15778(p1, 0);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}

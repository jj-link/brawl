#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void fn_41_699AC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_69A18(void* p1, short p2) {
    if (p1 != 0) {
        fn_41_69BF0((char*)p1 + 0x308, -1);
        fn_41_699AC((char*)p1 + 4, -1);
        if (p2 > 0)
            __dl__FPv(p1);
    }
    return p1;
}

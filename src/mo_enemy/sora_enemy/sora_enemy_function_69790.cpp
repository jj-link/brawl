#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void fn_41_69724(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_69790(void* p1, int p2) {
    if (p1) {
        fn_41_69BF0((char*)p1 + 0x1e8, -1);
        fn_41_69724((char*)p1 + 4, -1);
        if ((short)p2 > 0)
            __dl__FPv(p1);
    }
    return p1;
}

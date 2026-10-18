#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_69364(void* p1, int p2) {
    if (p1) {
        fn_41_69BF0((char*)p1 + 8, -1);
        if ((short)p2 > 0)
            __dl__FPv(p1);
    }
    return p1;
}

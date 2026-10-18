#pragma force_active on
extern "C" void fn_41_3CDBC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3CE28(void* p1, short p2) {
    if (p1 != 0) {
        fn_41_3CDBC((char*)p1 + 4, -1);
        if (p2 > 0)
            __dl__FPv(p1);
    }
    return p1;
}

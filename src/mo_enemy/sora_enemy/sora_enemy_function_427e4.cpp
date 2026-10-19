#pragma force_active on
extern "C" void fn_41_428E4(void*, short);
extern "C" void fn_41_42784(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_427E4(void* p, int flag) {
    if (p) {
        fn_41_428E4((char*)p + 0x38, -1);
        fn_41_42784((char*)p + 4, -1);
        if ((short)flag > 0)
            __dl__FPv(p);
    }
    return p;
}

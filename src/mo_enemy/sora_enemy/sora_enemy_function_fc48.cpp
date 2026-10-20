#pragma force_active on
extern "C" void* fn_41_FBAC(void*, short);
extern "C" void* fn_41_FB50(void*, short);
extern "C" void* fn_27_5CC1C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_FC48(void* p, int flag) {
    if (p) {
        fn_41_FBAC((char*)p + 0xB8, 0);
        fn_41_FB50((char*)p + 0xAC, 0);
        fn_27_5CC1C(p, 0);
        if ((short)flag > 0)
            __dl__FPv(p);
    }
    return p;
}

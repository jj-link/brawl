#pragma force_active on
extern "C" void __destroy_arr(void*, void* (*)(void*, int), int, int);
extern "C" void* fn_96_1DFBC(void*, short);
extern "C" void* fn_27_C3C00(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_1DEE4(void* object, short deleting) {
    if (object != 0) {
        __destroy_arr(static_cast<unsigned char*>(object) + 0xC, fn_27_C3C00, 8, 7);
        fn_96_1DFBC(object, 0);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}

#pragma force_active on
extern "C" void fn_109_3B50(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_57A8(void* object, short deleting) {
    if (object != 0) {
        fn_109_3B50((char*)object + 0x88, -1);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}

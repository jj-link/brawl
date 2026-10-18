#pragma force_active on
extern "C" void fn_120_3A1C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_156A0(void* object, short deleting) {
    if (object != 0) {
        fn_120_3A1C((char*)object + 0x18, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

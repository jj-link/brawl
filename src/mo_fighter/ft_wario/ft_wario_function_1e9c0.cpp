#pragma force_active on
extern "C" void fn_110_355C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_1E9C0(void* object, short deleting) {
    if (object != 0) {
        fn_110_355C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

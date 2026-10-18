#pragma force_active on
extern "C" void fn_110_40EC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_408C(void* object, short deleting) {
    if (object != 0) {
        fn_110_40EC(static_cast<unsigned char*>(object) + 12, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

#pragma force_active on
extern "C" void fn_110_12FD0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_13030(void* object, short deleting) {
    if (object != 0) {
        fn_110_12FD0(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

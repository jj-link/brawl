#pragma force_active on
extern "C" void fn_110_13030(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_13090(void* object, short deleting) {
    if (object != 0) {
        fn_110_13030(static_cast<char*>(object) + 4, -1);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}

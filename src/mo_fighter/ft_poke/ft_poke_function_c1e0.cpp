#pragma force_active on
extern "C" void fn_116_C180(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_C1E0(void* object, short deleting) {
    if (object) {
        fn_116_C180(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

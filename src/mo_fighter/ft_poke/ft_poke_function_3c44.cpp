#pragma force_active on
extern "C" void fn_116_1EC4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_3C44(void* object, short deleting) {
    if (object != 0) {
        fn_116_1EC4(static_cast<unsigned char*>(object) + 8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

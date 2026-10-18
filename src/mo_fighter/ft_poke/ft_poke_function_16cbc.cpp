#pragma force_active on
extern "C" void* fn_116_163C8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_16CBC(void* object, short deleting) {
    if (object != 0) {
        fn_116_163C8(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

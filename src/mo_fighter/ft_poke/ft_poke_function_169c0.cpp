#pragma force_active on
extern "C" void* fn_116_163C8(void*, short);
extern "C" void* fn_116_16A30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_169C0(void* object, short deleting) {
    if (object != 0) {
        fn_116_163C8(static_cast<unsigned char*>(object) + 0x9E30, static_cast<short>(-1));
        fn_116_16A30(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}

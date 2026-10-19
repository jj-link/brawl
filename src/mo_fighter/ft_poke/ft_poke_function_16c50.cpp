#pragma force_active on
extern "C" void* fn_116_163C8(void*, short);
extern "C" void* fn_116_16CBC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_16C50(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_116_163C8(p + 0x16A0, -1);
        fn_116_16CBC(p + 0x4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

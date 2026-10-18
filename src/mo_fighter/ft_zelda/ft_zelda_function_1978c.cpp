#pragma force_active on
extern "C" void* fn_104_197EC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_1978C(void* object, short deleting) {
    if (object != 0) {
        fn_104_197EC(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

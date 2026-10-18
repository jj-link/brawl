#pragma force_active on
extern "C" void* fn_94_CEDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_CF3C(void* object, short deleting) {
    if (object != 0) {
        fn_94_CEDC(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

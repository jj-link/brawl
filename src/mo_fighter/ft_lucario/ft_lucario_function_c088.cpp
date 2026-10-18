#pragma force_active on
extern "C" void* fn_118_C02C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_118_C088(void* object, short deleting) {
    if (object != 0) {
        fn_118_C02C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

#pragma force_active on
extern "C" void* fn_98_BDDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_BE3C(void* object, short deleting) {
    if (object) {
        fn_98_BDDC(static_cast<char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

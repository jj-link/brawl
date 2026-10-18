#pragma force_active on
extern "C" void fn_95_3C6C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_40F4(void* object, short deleting) {
    if (object != 0) {
        fn_95_3C6C(static_cast<unsigned char*>(object) + 0x14, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

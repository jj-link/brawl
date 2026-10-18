#pragma force_active on
extern "C" void fn_120_3A1C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_178E0(void* object, short deleting) {
    if (object != 0) {
        fn_120_3A1C(static_cast<char*>(object) + 0x14, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

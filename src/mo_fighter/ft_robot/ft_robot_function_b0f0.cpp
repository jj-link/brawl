#pragma force_active on
extern "C" void* fn_120_B090(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_B0F0(void* object, short deleting) {
    if (object != 0) {
        fn_120_B090(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

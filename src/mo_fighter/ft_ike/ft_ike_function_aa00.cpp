#pragma force_active on
extern "C" void fn_119_A9A0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_AA00(void* object, short deleting) {
    if (object != 0) {
        fn_119_A9A0(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

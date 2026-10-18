#pragma force_active on
extern "C" void fn_119_35D8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_3578(void* object, short deleting) {
    if (object != 0) {
        fn_119_35D8(static_cast<unsigned char*>(object) + 0x1C0, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

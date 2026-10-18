#pragma force_active on
extern "C" void* fn_119_3A74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_3A14(void* object, short deleting) {
    if (object != 0) {
        fn_119_3A74(static_cast<unsigned char*>(object) + 0xC, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

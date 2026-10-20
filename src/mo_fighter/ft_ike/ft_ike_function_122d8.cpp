#pragma force_active on
extern "C" void* fn_119_12238(void*, short);
extern "C" void* fn_119_12278(void*, short);
extern "C" void* fn_119_121C4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_122D8(void* object, short deleting) {
    if (object != 0) {
        fn_119_12238(static_cast<unsigned char*>(object) + 0xB0, -1);
        fn_119_12278(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_119_121C4(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

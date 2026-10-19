#pragma force_active on
extern "C" void fn_119_129E0(void*, short);
extern "C" void fn_119_125AC(void*, short);

extern "C" void* fn_119_12A70(void* object, short deleting) {
    if (object != 0) {
        fn_119_129E0(static_cast<unsigned char*>(object) + 0x1BD8, -1);
        fn_119_125AC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

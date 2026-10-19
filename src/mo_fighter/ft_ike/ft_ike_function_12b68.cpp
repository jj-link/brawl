#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_11424(void*, short);
extern "C" void fn_119_12AE0(void*, short);

extern "C" void* fn_119_12B68(void* object, short deleting) {
    if (object != 0) {
        fn_119_11424(static_cast<unsigned char*>(object) + 0x22d4, -1);
        fn_119_12AE0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

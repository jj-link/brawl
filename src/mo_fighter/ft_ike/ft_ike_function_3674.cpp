#pragma force_active on
void operator delete(void*);

extern "C" void* fn_119_9DC4(void*, short);
extern "C" void* fn_119_36EC(void*, short);
extern "C" void* fn_119_374C(void*, short);

extern "C" void* fn_119_3674(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_119_9DC4(storage + 0xE0, -1);
        fn_119_36EC(storage + 0x30, -1);
        fn_119_374C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

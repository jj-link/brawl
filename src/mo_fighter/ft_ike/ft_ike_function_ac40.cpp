#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_ABE0(void*, short);
extern "C" void* fn_119_AAC0(void*, short);

extern "C" void* fn_119_AC40(void* object, short deleting) {
    if (object != 0) {
        fn_119_ABE0(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_119_AAC0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

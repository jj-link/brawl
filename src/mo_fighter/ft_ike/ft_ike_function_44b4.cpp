#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_4520(void*, short);
extern "C" void* fn_119_4580(void*, short);

extern "C" void* fn_119_44B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_119_4520(storage + 0x24, -1);
        fn_119_4580(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

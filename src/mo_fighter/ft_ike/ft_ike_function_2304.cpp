#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_2370(void*, short);
extern "C" void* fn_119_21CC(void*, short);

extern "C" void* fn_119_2304(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_119_2370(storage + 0x50, -1);
        fn_119_21CC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

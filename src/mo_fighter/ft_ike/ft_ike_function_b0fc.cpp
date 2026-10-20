#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_B09C(void* object, short deleting);
extern "C" void* fn_119_AF68(void* object, short deleting);

extern "C" void* fn_119_B0FC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_119_B09C(storage + 0x134, -1);
        if (object != 0) {
            fn_119_AF68(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

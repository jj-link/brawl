#pragma force_active on
void operator delete(void*);
extern "C" void* fn_119_B234(void* object, short deleting);
extern "C" void fn_119_B0FC(void* object, short deleting);

extern "C" void* fn_119_B294(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_119_B234(storage + 0x17C, -1);
        if (object != 0) {
            fn_119_B0FC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_1C5F8(void* object, short deleting);
extern "C" void* fn_113_1C528(void* object, short deleting);

extern "C" void* fn_113_1C658(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_1C5F8(storage + 0x64, -1);
        if (object != 0) {
            fn_113_1C528(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

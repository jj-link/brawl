#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_E890(void* object, short deleting);
extern "C" void fn_113_E75C(void* object, short deleting);

extern "C" void* fn_113_E8F0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_E890(storage + 0x134, -1);
        if (object != 0) {
            fn_113_E75C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_B708(void* object, short deleting);
extern "C" void fn_92_B5D4(void* object, short deleting);

extern "C" void* fn_92_B768(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_92_B708(storage + 0x1C8, -1);
        if (object != 0) {
            fn_92_B5D4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

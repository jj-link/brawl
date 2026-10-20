#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_EBBC(void* object, short deleting);
extern "C" void fn_113_EA88(void* object, short deleting);

extern "C" void* fn_113_EC1C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_EBBC(storage + 0x1C8, -1);
        if (object != 0) {
            fn_113_EA88(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

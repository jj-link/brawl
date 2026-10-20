#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_C1C4(void* object, short deleting);
extern "C" void fn_123_C090(void* object, short deleting);

extern "C" void* fn_123_C224(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_123_C1C4(storage + 0x204, -1);
        if (object != 0) {
            fn_123_C090(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

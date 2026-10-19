#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_3424(void* object, short deleting);
extern "C" void* fn_112_4054(void* object, short deleting);

extern "C" void* fn_112_33A8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_3424(storage + 0x20038, -1);
        if (object != 0) {
            fn_112_4054(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

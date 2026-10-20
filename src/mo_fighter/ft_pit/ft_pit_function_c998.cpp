#pragma force_active on
extern "C" void fn_112_C938(void* object, short deleting);
extern "C" void fn_112_C804(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_112_C998(void* object, short deleting) {
    if (object != 0) {
        fn_112_C938(static_cast<unsigned char*>(object) + 0x1C8, -1);
        if (object != 0) {
            fn_112_C804(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma force_active on
void operator delete(void*);
extern "C" void fn_105_33C4(void* object, short arg);
extern "C" void fn_105_4BAC(void* object, short arg);

extern "C" void* fn_105_3348(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_33C4(storage + 0x11C08, -1);
        if (object != 0) {
            fn_105_4BAC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

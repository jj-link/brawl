#pragma force_active on
void operator delete(void*);
extern "C" void* fn_109_AE7C(void* object, short deleting);
extern "C" void fn_109_AD48(void* object, short deleting);

extern "C" void* fn_109_AEDC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_AE7C(storage + 0x1C8, -1);
        if (object != 0) {
            fn_109_AD48(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_23B4(void*, short);
extern "C" void* fn_97_2210(void*, short);

// Release the embedded member at +0x50 and the base, then free storage when deleting > 0.
extern "C" void* fn_97_2348(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_23B4(storage + 0x50, -1);
        fn_97_2210(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

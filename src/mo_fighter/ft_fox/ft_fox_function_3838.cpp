#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_22EC(void*, short);
extern "C" void* fn_97_2210(void*, short);

// Release the embedded member before the base, retaining their storage.
extern "C" void* fn_97_3838(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_22EC(storage + 0x50, -1);
        fn_97_2210(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_2484(void* object, short deleting);
extern "C" void* fn_95_22E0(void* p, short flag);

// Release the embedded member at +0x50, then the base, and free storage when deleting > 0.
extern "C" void* fn_95_2418(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_2484(storage + 0x50, -1);
        fn_95_22E0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

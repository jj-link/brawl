#pragma force_active on
void operator delete(void*);
extern "C" void fn_117_3434(void*, short);
extern "C" void fn_117_3560(void*, short);

// Destroys the embedded member at +0x3AFF8 (0x40000 - 0x5008) with flag -1,
// then the base cleanup with flag 0, and frees the storage only when the
// deleting flag is positive. The pointer is returned in every case.
extern "C" void* fn_117_33B8(void* object, short deleting) {
    if (object != 0) {
        fn_117_3434(static_cast<unsigned char*>(object) + 0x3AFF8, -1);
        if (object != 0) {
            fn_117_3560(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

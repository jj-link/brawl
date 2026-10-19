#pragma force_active on
void operator delete(void*);
extern "C" void* fn_109_1F10(void*, short);
extern "C" void* fn_109_3C2C(void*, short);

// Release the embedded member before the base, deleting their storage if requested.
extern "C" void* fn_109_4C2C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_1F10(storage + 0x20, 0);
        fn_109_3C2C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

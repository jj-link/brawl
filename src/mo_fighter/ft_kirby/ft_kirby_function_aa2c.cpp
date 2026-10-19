#pragma force_active on
extern "C" void* fn_96_A9D0(void* object, short destroy);
extern "C" void* fn_96_6B10(void* object, short deleting);
void operator delete(void*);

// Release the embedded member before the base, retaining their storage.
extern "C" void* fn_96_AA2C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_A9D0(storage + 0x50, -1);
        fn_96_6B10(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

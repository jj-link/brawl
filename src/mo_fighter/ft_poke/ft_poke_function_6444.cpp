#pragma force_active on
extern "C" void* fn_27_6A3D8(void*, short);
extern "C" void* fn_27_199E3C(void*, short);
void operator delete(void*);

// Release the embedded member before the base, deleting their storage if requested.
extern "C" void* fn_116_6444(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_6A3D8(storage + 0x144, -1);
        fn_27_199E3C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

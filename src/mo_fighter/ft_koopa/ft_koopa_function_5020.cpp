#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_508C(void*, short);
extern "C" void* fn_102_3D8C(void*, short);

// Release the embedded member array before the base, retaining their storage.
extern "C" void* fn_102_5020(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_508C(storage + 0x24, -1);
        fn_102_3D8C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

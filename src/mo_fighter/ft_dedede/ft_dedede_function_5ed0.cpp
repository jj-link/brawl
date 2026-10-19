#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_25740(void*, short);
extern "C" void* fn_27_CC0F0(void*, short);

// Release the embedded member before the base, then optionally free the object.
extern "C" void* fn_117_5ED0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_25740(storage + 0x50, -1);
        fn_27_CC0F0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

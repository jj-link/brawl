#pragma force_active on
extern "C" void fn_102_1EE8(void*, short);
extern "C" void fn_102_3B68(void*, short);
extern "C" void __dl__FPv(void*);

// Release the embedded member before the object itself, then free the storage.
extern "C" void* fn_102_4444(void* object, short deleting) {
    if (object != 0) {
        short mode = 0;
        fn_102_1EE8(static_cast<unsigned char*>(object) + 0x20, mode);
        fn_102_3B68(object, mode);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

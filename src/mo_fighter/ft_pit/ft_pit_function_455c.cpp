#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_112_22C8(void*, short);
extern "C" void* fn_112_21EC(void*, short);

// Release the embedded members before the base, retaining their storage.
extern "C" void* fn_112_455C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_22C8(storage + 0x50, -1);
        fn_112_21EC(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

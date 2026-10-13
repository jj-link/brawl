void operator delete(void*);
extern "C" void* fn_117_22CC(void*, short);
extern "C" void* fn_117_21F0(void*, short);

// Release the embedded member before the base, retaining their storage.
extern "C" void* fn_117_14CC8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_22CC(storage + 0x50, -1);
        fn_117_21F0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

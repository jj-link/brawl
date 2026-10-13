void operator delete(void*);
extern "C" void* fn_117_14D34(void*, short);
extern "C" void* fn_117_14930(void*, short);

extern "C" void* fn_117_14DC4(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded aggregate before the non-deleting base form.
        fn_117_14D34(static_cast<unsigned char*>(object) + 0x17D4, -1);
        fn_117_14930(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

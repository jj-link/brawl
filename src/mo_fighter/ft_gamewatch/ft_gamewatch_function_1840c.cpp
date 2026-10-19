#pragma force_active on
extern "C" void operator delete(void*);

extern "C" void* fn_107_1847C(void*, short);
extern "C" void* fn_107_186B0(void*, short);

extern "C" void* fn_107_1840C(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded aggregate before the non-deleting base form.
        fn_107_1847C(static_cast<unsigned char*>(object) + 0x1990, -1);
        fn_107_186B0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma force_active on
void operator delete(void*);
extern "C" void* fn_120_13460(void*, short);
extern "C" void* fn_120_13038(void*, short);

extern "C" void* fn_120_134F0(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded aggregate before the non-deleting base form.
        fn_120_13460(static_cast<unsigned char*>(object) + 0x1928, -1);
        fn_120_13038(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

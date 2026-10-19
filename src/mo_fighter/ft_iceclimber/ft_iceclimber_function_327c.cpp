#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_32EC(void*, short);
extern "C" void* fn_105_628C(void*, short);

extern "C" void* fn_105_327C(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded aggregate before the non-deleting base form.
        fn_105_32EC(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_105_628C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma force_active on
void operator delete(void*);
extern "C" void* fn_95_D41C(void*, short);
extern "C" void* fn_95_D2FC(void*, short);

extern "C" void* fn_95_D47C(void* object, short deleting) {
    if (object != 0) {
        // Destroy the aggregate at +0x60 first, then the non-deleting
        // instance-pool body, then free the block if asked to.
        fn_95_D41C(static_cast<unsigned char*>(object) + 0x60,
                   static_cast<short>(-1));
        fn_95_D2FC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

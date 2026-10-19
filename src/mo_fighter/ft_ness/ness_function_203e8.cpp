#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_20458(void*, short);
void* fn_101_204E8(void*, short);
}

extern "C" void* fn_101_203E8(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_20458(static_cast<unsigned char*>(object) + 0x1A08, memberDeleting);
        fn_101_204E8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

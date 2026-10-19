#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_6960(void*, short);
void* fn_101_6F1C(void*, short);
}

extern "C" void* fn_101_68F0(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_6960(static_cast<unsigned char*>(object) + 0x21C8, memberDeleting);
        fn_101_6F1C(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

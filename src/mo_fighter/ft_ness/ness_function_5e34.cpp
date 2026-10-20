#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_5EAC(void*, short);
void* fn_101_68F0(void*, short);
}

extern "C" void* fn_101_5E34(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_5EAC(static_cast<unsigned char*>(object) + 0x430C, memberDeleting);
        if (object != 0) {
            fn_101_68F0(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

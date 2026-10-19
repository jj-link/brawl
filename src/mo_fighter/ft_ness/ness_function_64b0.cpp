#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_5F1C(void*, short);
void* fn_101_6520(void*, short);
}

extern "C" void* fn_101_64B0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_5F1C(members + 0xFCE0, memberDeleting);
        fn_101_6520(members + 0x04, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

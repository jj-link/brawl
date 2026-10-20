#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_D2904(void*, short);
void* fn_101_7F68(void*, short);
}

extern "C" void* fn_101_7EF0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_D2904(members + 0xB4, memberDeleting);
        if (object != 0) {
            fn_101_7F68(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

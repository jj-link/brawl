#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_101_2138(void*, short);
void fn_101_2194(void*, short);
void fn_27_57BA0(void*, short);
}

extern "C" void* fn_101_20B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x20 != 0) {
            short zero = 0;
            fn_27_57BA0(members + 0x20, zero);
        }
        short memberDeleting = 0;
        fn_101_2138(members + 0x14, memberDeleting);
        fn_101_2194(members + 0x8, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

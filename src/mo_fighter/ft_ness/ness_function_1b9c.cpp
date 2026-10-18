#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_1C3C(void*, short);
void* fn_101_201C(void*, short);
void* fn_101_20B8(void*, short);
void* fn_101_21F0(void*, short);
void fn_27_125E20(void*, short);
}

extern "C" void* fn_101_1B9C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_1C3C(members + 0x4AD68, memberDeleting);
        fn_101_201C(members + 0x4A8B0, memberDeleting);
        fn_101_20B8(members + 0x4A874, memberDeleting);
        fn_101_21F0(members + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_2274(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_101_2B2C(void*, short);
}

extern "C" void* fn_101_21F0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_2274(members + 0x490F4, memberDeleting);
        fn_27_C74E8(members + 0x490E4, memberDeleting);
        fn_101_2B2C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

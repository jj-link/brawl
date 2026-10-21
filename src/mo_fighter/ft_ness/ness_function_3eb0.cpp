#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_3F44(void*, short);
void* fn_27_1A241C(void*, short);
void* fn_101_3F84(void*, short);
void* fn_101_3FC4(void*, short);
}

extern "C" void* fn_101_3EB0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_3F44(members + 0xB0, memberDeleting);
        if (members + 0x30 != 0) {
            fn_27_1A241C(members + 0x40, memberDeleting);
            fn_101_3F84(members + 0x30, static_cast<short>(0));
        }
        fn_101_3FC4(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

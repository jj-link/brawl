#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_101_4784(void*, short);
}

extern "C" void* fn_101_46F8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_B5324(members + 0x20, memberDeleting);
        if (members + 0x10 != 0) {
            fn_101_4784(members + 0x10, static_cast<short>(0));
        }
        if (object != 0) {
            fn_101_4784(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

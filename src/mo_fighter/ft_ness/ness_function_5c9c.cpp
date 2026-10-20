#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_101_4900(void*, short);
}

extern "C" void* fn_101_5C9C(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_27_13C90(members + 0x9C, memberDeleting);
        fn_27_21038(members + 0x88, memberDeleting);
        fn_101_4900(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

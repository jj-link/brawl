#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_126_2000(void*, short);
void* fn_126_209C(void*, short);
void* fn_126_20DC(void*, short);
void* fn_126_26F8(void*, short);
void* fn_27_1A59C0(void*, short);
}

extern "C" void* fn_126_2660(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_126_2000(members + 0x9A4, memberDeleting);
        fn_126_209C(members + 0x988, memberDeleting);
        fn_126_20DC(members + 0x8DC, memberDeleting);
        fn_126_26F8(members + 0x46C, memberDeleting);
        if (object != 0) {
            fn_27_1A59C0(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

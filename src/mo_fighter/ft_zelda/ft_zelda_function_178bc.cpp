#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_104_21D0(void*, short);
void* fn_104_226C(void*, short);
void* fn_104_22AC(void*, short);
void* fn_104_17954(void*, short);
void* fn_27_1A5FD8(void*, short);
}

extern "C" void* fn_104_178BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_21D0(members + 0x9DC, memberDeleting);
        fn_104_226C(members + 0x9C0, memberDeleting);
        fn_104_22AC(members + 0x914, memberDeleting);
        fn_104_17954(members + 0x488, memberDeleting);
        if (object != 0) {
            fn_27_1A5FD8(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

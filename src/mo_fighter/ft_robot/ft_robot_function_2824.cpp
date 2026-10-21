#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_120_21C4(void*, short);
void* fn_120_2260(void*, short);
void* fn_120_22A0(void*, short);
void* fn_120_28BC(void*, short);
void fn_27_1A5ED4(void*, short);
}

extern "C" void* fn_120_2824(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_120_21C4(members + 0x9d4, memberDeleting);
        fn_120_2260(members + 0x9b8, memberDeleting);
        fn_120_22A0(members + 0x90c, memberDeleting);
        fn_120_28BC(members + 0x484, memberDeleting);
        if (object != 0) {
            fn_27_1A5ED4(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

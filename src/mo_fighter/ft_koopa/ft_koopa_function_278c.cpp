#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_102_212C(void*, short);
void* fn_102_21C8(void*, short);
void* fn_102_2208(void*, short);
void* fn_102_2824(void*, short);
void* fn_27_1A63E8(void*, short);
}

extern "C" void* fn_102_278C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_102_212C(members + 0x9FC, memberDeleting);
        fn_102_21C8(members + 0x9E0, memberDeleting);
        fn_102_2208(members + 0x934, memberDeleting);
        fn_102_2824(members + 0x498, memberDeleting);
        if (object != 0) {
            fn_27_1A63E8(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

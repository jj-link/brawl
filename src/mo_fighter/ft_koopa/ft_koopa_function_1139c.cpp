#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_102_212C(void*, short);
void* fn_102_21C8(void*, short);
void* fn_102_2208(void*, short);
void* fn_102_11434(void*, short);
void* fn_27_1A64EC(void*, short);
}

extern "C" void* fn_102_1139C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_102_212C(members + 0xA04, memberDeleting);
        fn_102_21C8(members + 0x9E8, memberDeleting);
        fn_102_2208(members + 0x93C, memberDeleting);
        fn_102_11434(members + 0x49C, memberDeleting);
        if (object != 0) {
            fn_27_1A64EC(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

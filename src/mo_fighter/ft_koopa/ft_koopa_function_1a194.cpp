#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_102_212C(void*, short);
void* fn_102_21C8(void*, short);
void* fn_102_2208(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_102_1A194(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_102_212C(members + 0xDC, memberDeleting);
        fn_102_21C8(members + 0xC0, memberDeleting);
        fn_102_2208(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

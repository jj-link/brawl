#pragma force_active on
void operator delete(void*);

extern "C" {
void fn_113_2F3C(void*, short);
void fn_113_15128(void*, short);
void fn_27_1998BC(void*, short);
}

extern "C" void* fn_113_150A8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_113_2F3C(members + 0xB8, memberDeleting);
        fn_113_15128(members + 0x98, memberDeleting);
        if (object != 0) {
            fn_27_1998BC(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

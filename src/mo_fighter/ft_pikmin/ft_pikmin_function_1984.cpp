#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_B81C4(void*, short);
void* fn_113_1A04(void*, short);
void* fn_27_198034(void*, short);
}

extern "C" void* fn_113_1984(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_B81C4(members + 0xA4, memberDeleting);
        fn_113_1A04(members + 0x48, memberDeleting);
        if (object != 0) {
            fn_27_198034(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

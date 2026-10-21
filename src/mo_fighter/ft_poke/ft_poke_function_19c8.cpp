#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_116_1A80(void*, short);
void* fn_116_1B40(void*, short);
void* fn_116_1B9C(void*, short);
void* fn_116_1BF8(void*, short);
void* fn_116_1C54(void*, short);
void* fn_116_1CB0(void*, short);
void* fn_116_1D0C(void*, short);
void* fn_116_1D68(void*, short);
}

extern "C" void* fn_116_19C8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_1A80(members + 0x84, memberDeleting);
        fn_116_1B40(members + 0x70, memberDeleting);
        fn_116_1B9C(members + 0x5C, memberDeleting);
        fn_116_1BF8(members + 0x48, memberDeleting);
        fn_116_1C54(members + 0x34, memberDeleting);
        fn_116_1CB0(members + 0x20, memberDeleting);
        fn_116_1D0C(members + 0x08, memberDeleting);
        fn_116_1D68(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

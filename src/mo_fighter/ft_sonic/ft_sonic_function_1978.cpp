#pragma force_active on
extern "C" {
void* fn_123_1A30(void*, short);
void* fn_123_1B48(void*, short);
void* fn_123_1BA4(void*, short);
void* fn_123_1C00(void*, short);
void* fn_123_1C5C(void*, short);
void* fn_123_1CB8(void*, short);
void* fn_123_1D14(void*, short);
void* fn_123_1D70(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_123_1978(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_123_1A30(members + 0x84, memberDeleting);
        fn_123_1B48(members + 0x70, memberDeleting);
        fn_123_1BA4(members + 0x5C, memberDeleting);
        fn_123_1C00(members + 0x48, memberDeleting);
        fn_123_1C5C(members + 0x34, memberDeleting);
        fn_123_1CB8(members + 0x20, memberDeleting);
        fn_123_1D14(members + 0x08, memberDeleting);
        fn_123_1D70(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

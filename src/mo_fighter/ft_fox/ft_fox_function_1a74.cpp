#pragma force_active on
extern "C" {
void* fn_97_1B2C(void*, short);
void* fn_97_1BEC(void*, short);
void* fn_97_1C48(void*, short);
void* fn_97_1CA4(void*, short);
void* fn_97_1D00(void*, short);
void* fn_97_1D5C(void*, short);
void* fn_97_1DB8(void*, short);
void* fn_97_1E14(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_97_1A74(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_97_1B2C(members + 0x84, memberDeleting);
        fn_97_1BEC(members + 0x70, memberDeleting);
        fn_97_1C48(members + 0x5C, memberDeleting);
        fn_97_1CA4(members + 0x48, memberDeleting);
        fn_97_1D00(members + 0x34, memberDeleting);
        fn_97_1D5C(members + 0x20, memberDeleting);
        fn_97_1DB8(members + 0x8, memberDeleting);
        fn_97_1E14(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

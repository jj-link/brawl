#pragma force_active on
extern "C" {
void* fn_112_1B08(void*, short);
void* fn_112_1BC8(void*, short);
void* fn_112_1C24(void*, short);
void* fn_112_1C80(void*, short);
void* fn_112_1CDC(void*, short);
void* fn_112_1D38(void*, short);
void* fn_112_1D94(void*, short);
void* fn_112_1DF0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_112_1A50(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_112_1B08(members + 0x84, memberDeleting);
        fn_112_1BC8(members + 0x70, memberDeleting);
        fn_112_1C24(members + 0x5C, memberDeleting);
        fn_112_1C80(members + 0x48, memberDeleting);
        fn_112_1CDC(members + 0x34, memberDeleting);
        fn_112_1D38(members + 0x20, memberDeleting);
        fn_112_1D94(members + 0x8, memberDeleting);
        fn_112_1DF0(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

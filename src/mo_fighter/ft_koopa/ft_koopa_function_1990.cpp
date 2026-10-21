#pragma force_active on
extern "C" {
void* fn_102_1A48(void*, short);
void* fn_102_1B08(void*, short);
void* fn_102_1B64(void*, short);
void* fn_102_1BC0(void*, short);
void* fn_102_1C1C(void*, short);
void* fn_102_1C78(void*, short);
void* fn_102_1CD4(void*, short);
void* fn_102_1D30(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_102_1990(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_102_1A48(members + 0x84, memberDeleting);
        fn_102_1B08(members + 0x70, memberDeleting);
        fn_102_1B64(members + 0x5C, memberDeleting);
        fn_102_1BC0(members + 0x48, memberDeleting);
        fn_102_1C1C(members + 0x34, memberDeleting);
        fn_102_1C78(members + 0x20, memberDeleting);
        fn_102_1CD4(members + 0x8, memberDeleting);
        fn_102_1D30(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

#pragma force_active on
extern "C" {
void* fn_93_1E40(void*, short);
void* fn_93_1DE4(void*, short);
void* fn_93_1D88(void*, short);
void* fn_93_1D2C(void*, short);
void* fn_93_1CD0(void*, short);
void* fn_93_1C74(void*, short);
void* fn_93_1C18(void*, short);
void* fn_93_1B74(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_93_1E9C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_93_1E40(members + 0x84, memberDeleting);
        fn_93_1DE4(members + 0x70, memberDeleting);
        fn_93_1D88(members + 0x5C, memberDeleting);
        fn_93_1D2C(members + 0x48, memberDeleting);
        fn_93_1CD0(members + 0x34, memberDeleting);
        fn_93_1C74(members + 0x20, memberDeleting);
        fn_93_1C18(members + 8, memberDeleting);
        fn_93_1B74(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

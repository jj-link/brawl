#pragma force_active on
extern "C" {
void* fn_126_1924(void*, short);
void* fn_126_19E4(void*, short);
void* fn_126_1A40(void*, short);
void* fn_126_1A9C(void*, short);
void* fn_126_1AF8(void*, short);
void* fn_126_1B54(void*, short);
void* fn_126_1BB0(void*, short);
void* fn_126_1C0C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_126_186C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_126_1924(members + 0x84, memberDeleting);
        fn_126_19E4(members + 0x70, memberDeleting);
        fn_126_1A40(members + 0x5C, memberDeleting);
        fn_126_1A9C(members + 0x48, memberDeleting);
        fn_126_1AF8(members + 0x34, memberDeleting);
        fn_126_1B54(members + 0x20, memberDeleting);
        fn_126_1BB0(members + 0x08, memberDeleting);
        fn_126_1C0C(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

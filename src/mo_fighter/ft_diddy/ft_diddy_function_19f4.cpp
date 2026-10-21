#pragma force_active on
extern "C" {
void* fn_115_1AAC(void*, short);
void* fn_115_1B6C(void*, short);
void* fn_115_1BC8(void*, short);
void* fn_115_1C24(void*, short);
void* fn_115_1C80(void*, short);
void* fn_115_1CDC(void*, short);
void* fn_115_1D38(void*, short);
void* fn_115_1D94(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_115_19F4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_115_1AAC(members + 0x84, memberDeleting);
        fn_115_1B6C(members + 0x70, memberDeleting);
        fn_115_1BC8(members + 0x5C, memberDeleting);
        fn_115_1C24(members + 0x48, memberDeleting);
        fn_115_1C80(members + 0x34, memberDeleting);
        fn_115_1CDC(members + 0x20, memberDeleting);
        fn_115_1D38(members + 8, memberDeleting);
        fn_115_1D94(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

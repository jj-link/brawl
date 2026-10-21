#pragma force_active on
extern "C" {
void* fn_27_55FD0(void*, short);
void* fn_27_D3464(void*, short);
void* fn_116_726C(void*, short);
void* fn_116_722C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_116_1CEBC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_116_20420(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_55FD0(members + 0x11160, memberDeleting);
        fn_27_D3464(members + 0x1114C, memberDeleting);
        fn_116_726C(members + 0x11130, memberDeleting);
        fn_116_722C(members + 0x11118, memberDeleting);
        fn_27_C74E8(members + 0x11104, memberDeleting);
        fn_116_1CEBC(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

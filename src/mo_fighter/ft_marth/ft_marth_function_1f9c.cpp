#pragma force_active on

extern "C" {
void* fn_106_2018(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_106_28D0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_106_1F9C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_106_2018(members + 0x6838, memberDeleting);
        fn_27_C74E8(members + 0x6828, memberDeleting);
        fn_106_28D0(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

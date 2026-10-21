#pragma force_active on
extern "C" {
void* fn_122_3EE4(void*, short);
void* fn_122_3F94(void*, short);
void* fn_122_3FD4(void*, short);
void fn_27_1A2314(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_122_6A84(void* object, short deleting) {
    if (object != 0) {
        unsigned char* base = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_122_3EE4(base + 0x80, memberDeleting);
        if (base + 0x30 != 0) {
            fn_27_1A2314(base + 0x40, memberDeleting);
            fn_122_3F94(base + 0x30, static_cast<short>(0));
        }
        fn_122_3FD4(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

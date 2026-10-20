#pragma force_active on
extern "C" {
void* fn_100_37FC(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_100_14FD0(void*, short);
void* fn_27_1D81C8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_14F48(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_100_37FC(members + 0x1EB4, memberDeleting);
        fn_27_1DBB60(members + 0x1E7C, memberDeleting);
        fn_100_14FD0(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

#pragma force_active on
extern "C" void* fn_104_1AEC(void*, short);
extern "C" void* fn_104_1BAC(void*, short);
extern "C" void* fn_104_1C08(void*, short);
extern "C" void* fn_104_1C64(void*, short);
extern "C" void* fn_104_1CC0(void*, short);
extern "C" void* fn_104_1D1C(void*, short);
extern "C" void* fn_104_1D78(void*, short);
extern "C" void* fn_104_1DD4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_1A34(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_1AEC(members + 0x84, memberDeleting);
        fn_104_1BAC(members + 0x70, memberDeleting);
        fn_104_1C08(members + 0x5C, memberDeleting);
        fn_104_1C64(members + 0x48, memberDeleting);
        fn_104_1CC0(members + 0x34, memberDeleting);
        fn_104_1D1C(members + 0x20, memberDeleting);
        fn_104_1D78(members + 0x8, memberDeleting);
        fn_104_1DD4(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

#pragma force_active on
extern "C" {
void* fn_119_1AE8(void*, short);
void* fn_119_1BA8(void*, short);
void* fn_119_1C04(void*, short);
void* fn_119_1C60(void*, short);
void* fn_119_1CBC(void*, short);
void* fn_119_1D18(void*, short);
void* fn_119_1D74(void*, short);
void* fn_119_1DD0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_119_1A30(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_119_1AE8(members + 0x84, memberDeleting);
        fn_119_1BA8(members + 0x70, memberDeleting);
        fn_119_1C04(members + 0x5C, memberDeleting);
        fn_119_1C60(members + 0x48, memberDeleting);
        fn_119_1CBC(members + 0x34, memberDeleting);
        fn_119_1D18(members + 0x20, memberDeleting);
        fn_119_1D74(members + 0x8, memberDeleting);
        fn_119_1DD0(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

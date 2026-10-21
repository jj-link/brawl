#pragma force_active on
extern "C" {
void* fn_92_1B20(void*, short);
void* fn_92_1BE0(void*, short);
void* fn_92_1C3C(void*, short);
void* fn_92_1C98(void*, short);
void* fn_92_1CF4(void*, short);
void* fn_92_1D50(void*, short);
void* fn_92_1DAC(void*, short);
void* fn_92_1E08(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_92_1A68(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_92_1B20(members + 0x84, memberDeleting);
        fn_92_1BE0(members + 0x70, memberDeleting);
        fn_92_1C3C(members + 0x5C, memberDeleting);
        fn_92_1C98(members + 0x48, memberDeleting);
        fn_92_1CF4(members + 0x34, memberDeleting);
        fn_92_1D50(members + 0x20, memberDeleting);
        fn_92_1DAC(members + 0x8, memberDeleting);
        fn_92_1E08(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

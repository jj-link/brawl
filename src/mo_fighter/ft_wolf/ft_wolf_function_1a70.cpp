#pragma force_active on
extern "C" {
void* fn_125_1B28(void*, short);
void* fn_125_1BE8(void*, short);
void* fn_125_1C44(void*, short);
void* fn_125_1CA0(void*, short);
void* fn_125_1CFC(void*, short);
void* fn_125_1D58(void*, short);
void* fn_125_1DB4(void*, short);
void* fn_125_1E10(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_125_1A70(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_125_1B28(members + 0x84, memberDeleting);
        fn_125_1BE8(members + 0x70, memberDeleting);
        fn_125_1C44(members + 0x5C, memberDeleting);
        fn_125_1CA0(members + 0x48, memberDeleting);
        fn_125_1CFC(members + 0x34, memberDeleting);
        fn_125_1D58(members + 0x20, memberDeleting);
        fn_125_1DB4(members + 0x8, memberDeleting);
        fn_125_1E10(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

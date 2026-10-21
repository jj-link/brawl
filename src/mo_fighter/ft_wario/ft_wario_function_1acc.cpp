#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* fn_110_1B84(void*, short);
void* fn_110_1C44(void*, short);
void* fn_110_1CA0(void*, short);
void* fn_110_1CFC(void*, short);
void* fn_110_1D58(void*, short);
void* fn_110_1DB4(void*, short);
void* fn_110_1E10(void*, short);
void* fn_110_1E6C(void*, short);
}

extern "C" void* fn_110_1ACC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_110_1B84(members + 0x84, memberDeleting);
        fn_110_1C44(members + 0x70, memberDeleting);
        fn_110_1CA0(members + 0x5C, memberDeleting);
        fn_110_1CFC(members + 0x48, memberDeleting);
        fn_110_1D58(members + 0x34, memberDeleting);
        fn_110_1DB4(members + 0x20, memberDeleting);
        fn_110_1E10(members + 0x08, memberDeleting);
        fn_110_1E6C(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

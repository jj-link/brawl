#pragma force_active on

extern "C" {
void* fn_94_1A74(void*, short);
void* fn_94_1B34(void*, short);
void* fn_94_1B90(void*, short);
void* fn_94_1BEC(void*, short);
void* fn_94_1C48(void*, short);
void* fn_94_1CA4(void*, short);
void* fn_94_1D00(void*, short);
void* fn_94_1D5C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_94_19BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_94_1A74(members + 0x84, memberDeleting);
        fn_94_1B34(members + 0x70, memberDeleting);
        fn_94_1B90(members + 0x5C, memberDeleting);
        fn_94_1BEC(members + 0x48, memberDeleting);
        fn_94_1C48(members + 0x34, memberDeleting);
        fn_94_1CA4(members + 0x20, memberDeleting);
        fn_94_1D00(members + 8, memberDeleting);
        fn_94_1D5C(object, static_cast<short>(0));
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}

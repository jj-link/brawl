#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_120_1AE0(void*, short);
void* fn_120_1BA0(void*, short);
void* fn_120_1BFC(void*, short);
void* fn_120_1C58(void*, short);
void* fn_120_1CB4(void*, short);
void* fn_120_1D10(void*, short);
void* fn_120_1D6C(void*, short);
void* fn_120_1DC8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_120_1A28(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_120_1AE0(members + 0x84, memberDeleting);
        fn_120_1BA0(members + 0x70, memberDeleting);
        fn_120_1BFC(members + 0x5C, memberDeleting);
        fn_120_1C58(members + 0x48, memberDeleting);
        fn_120_1CB4(members + 0x34, memberDeleting);
        fn_120_1D10(members + 0x20, memberDeleting);
        fn_120_1D6C(members + 0x8, memberDeleting);
        fn_120_1DC8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

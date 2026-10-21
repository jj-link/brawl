#pragma force_active on
extern "C" {
void* fn_95_1BFC(void*, short);
void* fn_95_1CBC(void*, short);
void* fn_95_1D18(void*, short);
void* fn_95_1D74(void*, short);
void* fn_95_1DD0(void*, short);
void* fn_95_1E2C(void*, short);
void* fn_95_1E88(void*, short);
void* fn_95_1EE4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_95_1B44(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_95_1BFC(members + 0x84, memberDeleting);
        fn_95_1CBC(members + 0x70, memberDeleting);
        fn_95_1D18(members + 0x5C, memberDeleting);
        fn_95_1D74(members + 0x48, memberDeleting);
        fn_95_1DD0(members + 0x34, memberDeleting);
        fn_95_1E2C(members + 0x20, memberDeleting);
        fn_95_1E88(members + 0x08, memberDeleting);
        fn_95_1EE4(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

#pragma force_active on
extern "C" {
void* fn_109_1A70(void*, short);
void* fn_109_1B30(void*, short);
void* fn_109_1B8C(void*, short);
void* fn_109_1BE8(void*, short);
void* fn_109_1C44(void*, short);
void* fn_109_1CA0(void*, short);
void* fn_109_1CFC(void*, short);
void* fn_109_1D58(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_109_19B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_109_1A70(members + 0x84, memberDeleting);
        fn_109_1B30(members + 0x70, memberDeleting);
        fn_109_1B8C(members + 0x5C, memberDeleting);
        fn_109_1BE8(members + 0x48, memberDeleting);
        fn_109_1C44(members + 0x34, memberDeleting);
        fn_109_1CA0(members + 0x20, memberDeleting);
        fn_109_1CFC(members + 0x8, memberDeleting);
        fn_109_1D58(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

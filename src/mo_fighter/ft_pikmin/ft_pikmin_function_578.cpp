#pragma force_active on
extern "C" {
void* fn_113_630(void*, short);
void* fn_113_6F0(void*, short);
void* fn_113_74C(void*, short);
void* fn_113_7A8(void*, short);
void* fn_113_804(void*, short);
void* fn_113_860(void*, short);
void* fn_113_8BC(void*, short);
void* fn_113_918(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_113_578(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_113_630(members + 0x84, memberDeleting);
        fn_113_6F0(members + 0x70, memberDeleting);
        fn_113_74C(members + 0x5C, memberDeleting);
        fn_113_7A8(members + 0x48, memberDeleting);
        fn_113_804(members + 0x34, memberDeleting);
        fn_113_860(members + 0x20, memberDeleting);
        fn_113_8BC(members + 0x8, memberDeleting);
        fn_113_918(object, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

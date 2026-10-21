#pragma force_active on
extern "C" {
void* fn_125_220C(void*, short);
void* fn_125_22A8(void*, short);
void* fn_125_22E8(void*, short);
void* fn_125_2904(void*, short);
void fn_27_1A60DC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_125_286C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_125_220C(members + 0x9E4, memberDeleting);
        fn_125_22A8(members + 0x9C8, memberDeleting);
        fn_125_22E8(members + 0x91C, memberDeleting);
        fn_125_2904(members + 0x48C, memberDeleting);
        if (object != 0) {
            fn_27_1A60DC(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

#pragma force_active on
extern "C" void* fn_125_220C(void*, short);
extern "C" void* fn_125_22A8(void*, short);
extern "C" void* fn_125_22E8(void*, short);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_2180(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_125_220C(members + 0xDC, memberDeleting);
        fn_125_22A8(members + 0xC0, memberDeleting);
        fn_125_22E8(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

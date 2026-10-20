#pragma force_active on
extern "C" void* fn_125_220C(void*, short);
extern "C" void* fn_125_22A8(void*, short);
extern "C" void* fn_125_22E8(void*, short);
extern "C" void* fn_27_C7770(void*, short);

extern "C" void* fn_125_2754(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_125_220C(members + 0xdc, memberDeleting);
        fn_125_22A8(members + 0xc0, memberDeleting);
        fn_125_22E8(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

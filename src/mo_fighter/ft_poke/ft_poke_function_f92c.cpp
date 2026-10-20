#pragma force_active on
extern "C" void* fn_116_2164(void*, short);
extern "C" void* fn_116_2200(void*, short);
extern "C" void* fn_116_38F0(void*, short);
extern "C" void* fn_27_C7770(void*, short);

extern "C" void* fn_116_F92C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_116_2164(members + 0x64, memberDeleting);
        fn_116_2200(members + 0x48, memberDeleting);
        fn_116_38F0(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

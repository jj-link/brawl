#pragma force_active on
extern "C" void* fn_109_2154(void*, short);
extern "C" void* fn_109_21F0(void*, short);
extern "C" void* fn_109_2230(void*, short);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_24F8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_109_2154(members + 0xDC, memberDeleting);
        fn_109_21F0(members + 0xC0, memberDeleting);
        fn_109_2230(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

#pragma force_active on
extern "C" void* fn_105_218C(void*, short);
extern "C" void* fn_105_2228(void*, short);
extern "C" void* fn_105_2268(void*, short);
extern "C" void* fn_27_C7770(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_1A568(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_105_218C(members + 0xdc, memberDeleting);
        fn_105_2228(members + 0xc0, memberDeleting);
        fn_105_2268(members + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

#pragma force_active on
extern "C" {
void* fn_105_218C(void*, short);
void* fn_105_2228(void*, short);
void* fn_105_2268(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_105_1A450(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;

        fn_105_218C(members + 0xDC, memberDeleting);
        fn_105_2228(members + 0xC0, memberDeleting);
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

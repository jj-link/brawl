#pragma force_active on
extern "C" {
void* fn_96_6B10(void*, short);
void* fn_96_6AD0(void*, short);
void* fn_96_6BAC(void*, short);
void* fn_96_A47C(void*, short);
void* fn_27_1A6E10(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_96_A4D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_96_6B10(members + 0xEE4, memberDeleting);
        fn_96_6AD0(members + 0xEC8, memberDeleting);
        fn_96_6BAC(members + 0xE1C, memberDeleting);
        fn_96_A47C(members + 0x70C, memberDeleting);
        if (object != 0) {
            fn_27_1A6E10(object, memberDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

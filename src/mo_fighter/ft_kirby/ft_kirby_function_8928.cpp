#pragma force_active on
extern "C" {
void* fn_96_7A08(void*, short);
void* fn_96_6B10(void*, short);
void* fn_96_6AD0(void*, short);
void* fn_96_6BAC(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_96_8928(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;

        fn_96_7A08(members + 0x4B0, memberDeleting);

        if (members + 0x384 != 0) {
            fn_96_6B10(members + 0x460, memberDeleting);
            fn_96_6AD0(members + 0x444, memberDeleting);
            fn_96_6BAC(members + 0x398, memberDeleting);
            if (members + 0x384 != 0) {
                fn_27_C7770(members + 0x384, memberDeleting);
            }
        }
        if (members + 0x258 != 0) {
            fn_96_6B10(members + 0x334, memberDeleting);
            fn_96_6AD0(members + 0x318, memberDeleting);
            fn_96_6BAC(members + 0x26C, memberDeleting);
            if (members + 0x258 != 0) {
                fn_27_C7770(members + 0x258, memberDeleting);
            }
        }
        if (members + 0x12C != 0) {
            fn_96_6B10(members + 0x208, memberDeleting);
            fn_96_6AD0(members + 0x1EC, memberDeleting);
            fn_96_6BAC(members + 0x140, memberDeleting);
            if (members + 0x12C != 0) {
                fn_27_C7770(members + 0x12C, memberDeleting);
            }
        }
        if (object != 0) {
            fn_96_6B10(members + 0xDC, memberDeleting);
            fn_96_6AD0(members + 0xC0, memberDeleting);
            fn_96_6BAC(members + 0x14, memberDeleting);
            if (object != 0) {
                fn_27_C7770(object, memberDeleting);
            }
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

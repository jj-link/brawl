#pragma force_active on
extern "C" {
void* fn_114_3AFC(void*, short);
void* fn_114_232C(void*, short);
void* fn_114_23C8(void*, short);
void* fn_114_2408(void*, short);
void* fn_27_C7770(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_114_5680(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;

        fn_114_3AFC(members + 0x4B0, memberDeleting);

        if (members + 0x384 != 0) {
            fn_114_232C(members + 0x460, memberDeleting);
            fn_114_23C8(members + 0x444, memberDeleting);
            fn_114_2408(members + 0x398, memberDeleting);
            if (members + 0x384 != 0) {
                fn_27_C7770(members + 0x384, memberDeleting);
            }
        }
        if (members + 0x258 != 0) {
            fn_114_232C(members + 0x334, memberDeleting);
            fn_114_23C8(members + 0x318, memberDeleting);
            fn_114_2408(members + 0x26C, memberDeleting);
            if (members + 0x258 != 0) {
                fn_27_C7770(members + 0x258, memberDeleting);
            }
        }
        if (members + 0x12C != 0) {
            fn_114_232C(members + 0x208, memberDeleting);
            fn_114_23C8(members + 0x1EC, memberDeleting);
            fn_114_2408(members + 0x140, memberDeleting);
            if (members + 0x12C != 0) {
                fn_27_C7770(members + 0x12C, memberDeleting);
            }
        }
        if (object != 0) {
            fn_114_232C(members + 0xDC, memberDeleting);
            fn_114_23C8(members + 0xC0, memberDeleting);
            fn_114_2408(members + 0x14, memberDeleting);
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
#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_105_3674(void*, short);
void* fn_105_36B4(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_105_3750(void*, short);
void* fn_105_3A80(void*, short);
void* fn_105_3ADC(void*, short);
void* fn_105_3B38(void*, short);
void* fn_105_3BC4(void*, short);
void* fn_105_3CC0(void*, short);
void* fn_105_3DFC(void*, short);
void* fn_105_4160(void*, short);
void* fn_105_4294(void*, short);
void* fn_105_42F0(void*, short);
void* fn_105_434C(void*, short);
void* fn_105_43B8(void*, short);
void* fn_105_4418(void*, short);
void* fn_105_4478(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_CCF74(void*, short);
void* fn_105_4558(void*, short);
void* fn_105_4624(void*, short);
void* fn_105_4680(void*, short);
void* fn_105_46F4(void*, short);
void* fn_105_47F4(void*, short);
void* fn_105_4918(void*, short);
void* fn_105_4958(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_105_49B4(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_105_6090(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1FF0 != 0) {
            if (members + 0x1FF0 != 0) {
                fn_105_3674(members + 0x1FF0, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_105_36B4(members + 0x1FA8, memberDeleting);
            fn_27_1DBB60(members + 0x1F70, memberDeleting);
            if (members + 0xCC != 0) {
                fn_105_3750(members + 0x19C0, memberDeleting);
                if (members + 0xCC != 0) {
                    fn_105_3A80(members + 0x197C, memberDeleting);
                    fn_105_3ADC(members + 0x1964, memberDeleting);
                    fn_105_3B38(members + 0x17C8, memberDeleting);
                    fn_105_3BC4(members + 0x1768, memberDeleting);
                    fn_105_3CC0(members + 0x16B4, memberDeleting);
                    fn_105_3DFC(members + 0x14F4, memberDeleting);
                    fn_105_4160(members + 0x1450, memberDeleting);
                    fn_105_4294(members + 0x141C, memberDeleting);
                    fn_105_42F0(members + 0x1404, memberDeleting);
                    fn_105_434C(members + 0x12A0, memberDeleting);
                    fn_105_43B8(members + 0x1238, memberDeleting);
                    fn_105_4418(members + 0x122C, memberDeleting);
                    fn_105_4478(members + 0x1204, memberDeleting);
                    if (members + 0xF14 != 0) {
                        __dt__27soCollisionAttackModuleImplFv(members + 0x1158, memberDeleting);
                        fn_27_82AD4(members + 0x1154, memberDeleting);
                        fn_27_4CAA0(members + 0x10D0, memberDeleting);
                        fn_27_CCF74(members + 0xF14, memberDeleting);
                    }
                    fn_105_4558(members + 0xEB0, memberDeleting);
                    fn_105_4624(members + 0xE74, memberDeleting);
                    fn_105_4680(members + 0xDBC, memberDeleting);
                    fn_105_46F4(members + 0xBB0, memberDeleting);
                    fn_105_47F4(members + 0x9D0, memberDeleting);
                    fn_105_4918(members + 0x9BC, memberDeleting);
                    fn_105_4958(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_105_49B4(members + 0xCC, memberDeleting);
                }
            }
            fn_27_1D81C8(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

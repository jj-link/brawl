void operator delete(void*);
extern "C" {
void* fn_101_2DD8(void*, short);
void* fn_101_2E34(void*, short);
void* fn_101_2E90(void*, short);
void* fn_101_2EEC(void*, short);
void* fn_101_2F48(void*, short);
void* fn_101_2FA4(void*, short);
void* fn_101_3080(void*, short);
void* fn_101_30DC(void*, short);
void* fn_101_3138(void*, short);
void* fn_101_31AC(void*, short);
void* fn_101_3244(void*, short);
void* fn_101_32A0(void*, short);
void* fn_101_33F0(void*, short);
void* fn_101_73EC(void*, short);
void* fn_101_744C(void*, short);
void* fn_101_75A0(void*, short);
void* fn_101_8110(void*, short);
void* fn_101_43D0(void*, short);
void* fn_101_81EC(void*, short);
void* fn_101_8260(void*, short);
void* fn_101_833C(void*, short);
void* fn_101_8398(void*, short);
void* fn_101_8404(void*, short);
void* fn_101_84B0(void*, short);
void* fn_101_8524(void*, short);
void* fn_101_8580(void*, short);
void* fn_101_85DC(void*, short);
void* fn_101_8638(void*, short);
void* fn_101_8694(void*, short);
void* fn_101_8708(void*, short);
void* fn_101_8774(void*, short);
void* fn_101_8804(void*, short);
void* fn_101_8894(void*, short);
void* fn_101_8924(void*, short);
void* fn_101_89A8(void*, short);
void* fn_101_8A2C(void*, short);
void* fn_101_47C4(void*, short);
void* fn_101_4820(void*, short);
void* fn_101_488C(void*, short);
void* fn_101_8B60(void*, short);
void* fn_101_8F24(void*, short);
void* fn_101_8FF8(void*, short);
void* fn_101_9070(void*, short);
void* fn_101_4AEC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_101_90CC(void*, short);
}

extern "C" void* fn_101_2B2C(void* object, short deleting) {
    if (object != 0) {
        // Destroy embedded modules in reverse construction order; only the
        // aggregate's deleting flag may release the enclosing storage.
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_2DD8(members + 0x48F64, memberDeleting);
        fn_101_2E34(members + 0x48F28, memberDeleting);
        fn_101_2E90(members + 0x48EC0, memberDeleting);
        fn_101_2EEC(members + 0x48E74, memberDeleting);
        fn_101_2F48(members + 0x48D20, memberDeleting);
        fn_101_2FA4(members + 0x48C10, memberDeleting);
        fn_101_3080(members + 0x48BC8, memberDeleting);
        fn_101_30DC(members + 0x48B48, memberDeleting);
        fn_101_3138(members + 0x48A84, memberDeleting);
        fn_101_31AC(members + 0x48710, memberDeleting);
        fn_101_3244(members + 0x486E0, memberDeleting);
        fn_101_32A0(members + 0x4853C, memberDeleting);
        fn_101_33F0(members + 0x5B30, memberDeleting);
        fn_101_73EC(members + 0x594C, memberDeleting);
        fn_101_744C(members + 0x5644, memberDeleting);
        fn_101_75A0(members + 0x47C0, memberDeleting);
        fn_101_8110(members + 0x46CC, memberDeleting);
        fn_101_43D0(members + 0x4698, memberDeleting);
        fn_101_81EC(members + 0x4624, memberDeleting);
        fn_101_8260(members + 0x3F00, memberDeleting);
        fn_101_833C(members + 0x3ED0, memberDeleting);
        fn_101_8398(members + 0x3CD0, memberDeleting);
        fn_101_8404(members + 0x3C60, memberDeleting);
        fn_101_84B0(members + 0x3BC8, memberDeleting);
        fn_101_8524(members + 0x3B90, memberDeleting);
        fn_101_8580(members + 0x3B6C, memberDeleting);
        fn_101_85DC(members + 0x3B38, memberDeleting);
        fn_101_8638(members + 0x3AD4, memberDeleting);
        fn_101_8694(members + 0x3924, memberDeleting);
        fn_101_8708(members + 0x36C0, memberDeleting);
        fn_101_8774(members + 0x34A8, memberDeleting);
        fn_101_8804(members + 0x2C10, memberDeleting);
        fn_101_8894(members + 0x29F8, memberDeleting);
        fn_101_8924(members + 0x209C, memberDeleting);
        fn_101_89A8(members + 0x19E0, memberDeleting);
        fn_101_8A2C(members + 0x196C, memberDeleting);
        fn_101_47C4(members + 0x1930, memberDeleting);
        fn_101_4820(members + 0x1888, memberDeleting);
        fn_101_488C(members + 0x17D4, memberDeleting);
        fn_101_8B60(members + 0x1440, memberDeleting);
        fn_101_8F24(members + 0x1180, memberDeleting);
        fn_101_8FF8(members + 0x115C, memberDeleting);
        fn_101_9070(members + 0xAC8, memberDeleting);
        fn_101_4AEC(members + 0xAB0, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x9D0, memberDeleting);
        fn_101_90CC(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

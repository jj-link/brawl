void operator delete(void*);
extern "C" {
void* fn_101_3C14(void*, short);
void* fn_101_3C70(void*, short);
void* fn_101_3CCC(void*, short);
void* fn_101_3D28(void*, short);
void* fn_101_3DB4(void*, short);
void* fn_101_3EB0(void*, short);
void* fn_101_151C4(void*, short);
void* fn_101_429C(void*, short);
void* fn_101_43D0(void*, short);
void* fn_101_4490(void*, short);
void* fn_101_44EC(void*, short);
void* fn_101_4558(void*, short);
void* fn_101_45B8(void*, short);
void* fn_101_4618(void*, short);
void* fn_101_152BC(void*, short);
void* fn_101_15330(void*, short);
void* fn_101_153B4(void*, short);
void* fn_101_46F8(void*, short);
void* fn_101_47C4(void*, short);
void* fn_101_4820(void*, short);
void* fn_101_488C(void*, short);
void* fn_101_15494(void*, short);
void* fn_101_4988(void*, short);
void* fn_101_49F4(void*, short);
void* fn_101_4AAC(void*, short);
void* fn_101_4AEC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_101_4B48(void*, short);
}

extern "C" void* fn_101_15020(void* object, short deleting) {
    if (object != 0) {
        // Preserve reverse member destruction until the aggregate's full layout is described.
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_3C14(members + 0x1C98, memberDeleting);
        fn_101_3C70(members + 0x1C58, memberDeleting);
        fn_101_3CCC(members + 0x1C40, memberDeleting);
        fn_101_3D28(members + 0x1AA4, memberDeleting);
        fn_101_3DB4(members + 0x1A44, memberDeleting);
        fn_101_3EB0(members + 0x1990, memberDeleting);
        fn_101_151C4(members + 0x17CC, memberDeleting);
        fn_101_429C(members + 0x1728, memberDeleting);
        fn_101_43D0(members + 0x16F4, memberDeleting);
        fn_101_4490(members + 0x16DC, memberDeleting);
        fn_101_44EC(members + 0x1578, memberDeleting);
        fn_101_4558(members + 0x1510, memberDeleting);
        fn_101_45B8(members + 0x1504, memberDeleting);
        fn_101_4618(members + 0x14DC, memberDeleting);
        fn_101_152BC(members + 0x1380, memberDeleting);
        fn_101_15330(members + 0x116C, memberDeleting);
        fn_101_153B4(members + 0xF18, memberDeleting);
        fn_101_46F8(members + 0xEB4, memberDeleting);
        fn_101_47C4(members + 0xE78, memberDeleting);
        fn_101_4820(members + 0xDD0, memberDeleting);
        fn_101_488C(members + 0xD1C, memberDeleting);
        fn_101_15494(members + 0xB10, memberDeleting);
        fn_101_4988(members + 0x930, memberDeleting);
        fn_101_49F4(members + 0x900, memberDeleting);
        fn_101_4AAC(members + 0x8F0, memberDeleting);
        fn_101_4AEC(members + 0x8D8, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x7F8, memberDeleting);
        fn_101_4B48(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

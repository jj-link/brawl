void operator delete(void*);
extern "C" {
void* fn_101_3C70(void*, short);
void* fn_101_3CCC(void*, short);
void* fn_101_6D38(void*, short);
void* fn_101_20674(void*, short);
void* fn_101_3D28(void*, short);
void* fn_101_3DB4(void*, short);
void* fn_101_3EB0(void*, short);
void* fn_101_206D4(void*, short);
void* fn_101_429C(void*, short);
void* fn_101_43D0(void*, short);
void* fn_101_4490(void*, short);
void* fn_101_5C30(void*, short);
void* fn_101_4558(void*, short);
void* fn_101_45B8(void*, short);
void* fn_101_4618(void*, short);
void* fn_101_4674(void*, short);
void* fn_101_46F8(void*, short);
void* fn_101_47C4(void*, short);
void* fn_101_488C(void*, short);
void* fn_101_5C9C(void*, short);
void* fn_101_4988(void*, short);
void* fn_101_49F4(void*, short);
void* fn_101_4AAC(void*, short);
void* fn_101_4AEC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_101_6DF0(void*, short);
}

extern "C" void* fn_101_204E8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_3C70(members + 0x19C4, memberDeleting);
        fn_101_3CCC(members + 0x19AC, memberDeleting);
        fn_101_6D38(members + 0x1854, memberDeleting);
        fn_101_20674(members + 0x1804, memberDeleting);
        fn_101_3D28(members + 0x1670, memberDeleting);
        fn_101_3DB4(members + 0x1610, memberDeleting);
        fn_101_3EB0(members + 0x155C, memberDeleting);
        fn_101_206D4(members + 0x1374, memberDeleting);
        fn_101_429C(members + 0x12D0, memberDeleting);
        fn_101_43D0(members + 0x129C, memberDeleting);
        fn_101_4490(members + 0x1284, memberDeleting);
        fn_101_5C30(members + 0x10EC, memberDeleting);
        fn_101_4558(members + 0x1084, memberDeleting);
        fn_101_45B8(members + 0x1078, memberDeleting);
        fn_101_4618(members + 0x1050, memberDeleting);
        fn_101_4674(members + 0x0E80, memberDeleting);
        fn_101_46F8(members + 0x0E1C, memberDeleting);
        fn_101_47C4(members + 0x0DE0, memberDeleting);
        fn_101_488C(members + 0x0D28, memberDeleting);
        fn_101_5C9C(members + 0x0B1C, memberDeleting);
        fn_101_4988(members + 0x093C, memberDeleting);
        fn_101_49F4(members + 0x090C, memberDeleting);
        fn_101_4AAC(members + 0x08FC, memberDeleting);
        fn_101_4AEC(members + 0x08E4, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x0804, memberDeleting);
        fn_101_6DF0(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

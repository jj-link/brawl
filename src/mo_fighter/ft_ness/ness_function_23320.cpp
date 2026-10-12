void operator delete(void*);
extern "C" {
void* fn_101_3C14(void*, short);
void* fn_101_3C70(void*, short);
void* fn_101_3CCC(void*, short);
void* fn_101_6D38(void*, short);
void* fn_101_3D28(void*, short);
void* fn_101_3DB4(void*, short);
void* fn_101_3EB0(void*, short);
void* fn_101_234B8(void*, short);
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
void* fn_101_4820(void*, short);
void* fn_101_488C(void*, short);
void* fn_101_235B4(void*, short);
void* fn_101_4988(void*, short);
void* fn_101_49F4(void*, short);
void* fn_101_4AAC(void*, short);
void* fn_101_4AEC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_101_6DF0(void*, short);
}

extern "C" void* fn_101_23320(void* object, short deleting) {
    if (object != 0) {
        // Embedded modules are destroyed in reverse construction order without
        // releasing their enclosing aggregate's storage.
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_3C14(members + 0x1A54, memberDeleting);
        fn_101_3C70(members + 0x1A14, memberDeleting);
        fn_101_3CCC(members + 0x19FC, memberDeleting);
        fn_101_6D38(members + 0x18A4, memberDeleting);
        fn_101_3D28(members + 0x170C, memberDeleting);
        fn_101_3DB4(members + 0x16AC, memberDeleting);
        fn_101_3EB0(members + 0x15F8, memberDeleting);
        fn_101_234B8(members + 0x1418, memberDeleting);
        fn_101_429C(members + 0x1374, memberDeleting);
        fn_101_43D0(members + 0x1340, memberDeleting);
        fn_101_4490(members + 0x1328, memberDeleting);
        fn_101_5C30(members + 0x1190, memberDeleting);
        fn_101_4558(members + 0x1128, memberDeleting);
        fn_101_45B8(members + 0x111C, memberDeleting);
        fn_101_4618(members + 0x10F4, memberDeleting);
        fn_101_4674(members + 0x0F24, memberDeleting);
        fn_101_46F8(members + 0x0EC0, memberDeleting);
        fn_101_47C4(members + 0x0E84, memberDeleting);
        fn_101_4820(members + 0x0DDC, memberDeleting);
        fn_101_488C(members + 0x0D28, memberDeleting);
        fn_101_235B4(members + 0x0B1C, memberDeleting);
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

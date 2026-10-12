void operator delete(void*);
extern "C" {
void* fn_101_3C14(void*, short);
void* fn_101_3C70(void*, short);
void* fn_101_3CCC(void*, short);
void* fn_101_3D28(void*, short);
void* fn_101_3DB4(void*, short);
void* fn_101_3EB0(void*, short);
void* fn_101_1C0C4(void*, short);
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
void* fn_101_4B48(void*, short);
}

extern "C" void* fn_101_1BF44(void* object, short deleting) {
    if (object != 0) {
        // Destroy embedded modules in reverse order before the aggregate base.
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_3C14(members + 0x1838, memberDeleting);
        fn_101_3C70(members + 0x17F8, memberDeleting);
        fn_101_3CCC(members + 0x17E0, memberDeleting);
        fn_101_3D28(members + 0x1644, memberDeleting);
        fn_101_3DB4(members + 0x15E4, memberDeleting);
        fn_101_3EB0(members + 0x1530, memberDeleting);
        fn_101_1C0C4(members + 0x1368, memberDeleting);
        fn_101_429C(members + 0x12C4, memberDeleting);
        fn_101_43D0(members + 0x1290, memberDeleting);
        fn_101_4490(members + 0x1278, memberDeleting);
        fn_101_5C30(members + 0x10E0, memberDeleting);
        fn_101_4558(members + 0x1078, memberDeleting);
        fn_101_45B8(members + 0x106C, memberDeleting);
        fn_101_4618(members + 0x1044, memberDeleting);
        fn_101_4674(members + 0x0E74, memberDeleting);
        fn_101_46F8(members + 0x0E10, memberDeleting);
        fn_101_47C4(members + 0x0DD4, memberDeleting);
        fn_101_488C(members + 0x0D1C, memberDeleting);
        fn_101_5C9C(members + 0x0B10, memberDeleting);
        fn_101_4988(members + 0x0930, memberDeleting);
        fn_101_49F4(members + 0x0900, memberDeleting);
        fn_101_4AAC(members + 0x08F0, memberDeleting);
        fn_101_4AEC(members + 0x08D8, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x07F8, memberDeleting);
        fn_101_4B48(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

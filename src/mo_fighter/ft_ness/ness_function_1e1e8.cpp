void operator delete(void*);
extern "C" {
void* fn_101_3C70(void*, short);
void* fn_101_3CCC(void*, short);
void* fn_101_3D28(void*, short);
void* fn_101_3DB4(void*, short);
void* fn_101_1E35C(void*, short);
void* fn_101_1E434(void*, short);
void* fn_101_429C(void*, short);
void* fn_101_43D0(void*, short);
void* fn_101_4490(void*, short);
void* fn_101_44EC(void*, short);
void* fn_101_4558(void*, short);
void* fn_101_45B8(void*, short);
void* fn_101_4618(void*, short);
void* fn_101_4674(void*, short);
void* fn_101_46F8(void*, short);
void* fn_101_47C4(void*, short);
void* fn_101_488C(void*, short);
void* fn_101_5C9C(void*, short);
void* fn_101_1E4D0(void*, short);
void* fn_101_49F4(void*, short);
void* fn_101_4AAC(void*, short);
void* fn_101_4AEC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_101_1E53C(void*, short);
}

extern "C" void* fn_101_1E1E8(void* object, short deleting) {
    if (object != 0) {
        // Destroy embedded modules in reverse order before the aggregate base.
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_3C70(members + 0x149C, memberDeleting);
        fn_101_3CCC(members + 0x1484, memberDeleting);
        fn_101_3D28(members + 0x12E8, memberDeleting);
        fn_101_3DB4(members + 0x1288, memberDeleting);
        fn_101_1E35C(members + 0x121C, memberDeleting);
        fn_101_1E434(members + 0x105C, memberDeleting);
        fn_101_429C(members + 0x0FB8, memberDeleting);
        fn_101_43D0(members + 0x0F84, memberDeleting);
        fn_101_4490(members + 0x0F6C, memberDeleting);
        fn_101_44EC(members + 0x0E08, memberDeleting);
        fn_101_4558(members + 0x0DA0, memberDeleting);
        fn_101_45B8(members + 0x0D94, memberDeleting);
        fn_101_4618(members + 0x0D6C, memberDeleting);
        fn_101_4674(members + 0x0B9C, memberDeleting);
        fn_101_46F8(members + 0x0B38, memberDeleting);
        fn_101_47C4(members + 0x0AFC, memberDeleting);
        fn_101_488C(members + 0x0A44, memberDeleting);
        fn_101_5C9C(members + 0x0838, memberDeleting);
        fn_101_1E4D0(members + 0x06F4, memberDeleting);
        fn_101_49F4(members + 0x06C4, memberDeleting);
        fn_101_4AAC(members + 0x06B4, memberDeleting);
        fn_101_4AEC(members + 0x069C, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x05BC, memberDeleting);
        fn_101_1E53C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

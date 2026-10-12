void operator delete(void*);
extern "C" {
void* fn_101_3C14(void*, short);
void* fn_101_3C70(void*, short);
void* fn_101_3CCC(void*, short);
void* fn_101_3D28(void*, short);
void* fn_101_185E4(void*, short);
void* fn_101_3DB4(void*, short);
void* fn_101_3EB0(void*, short);
void* fn_101_18CCC(void*, short);
void* fn_101_429C(void*, short);
void* fn_101_43D0(void*, short);
void* fn_101_442C(void*, short);
void* fn_101_4490(void*, short);
void* fn_101_44EC(void*, short);
void* fn_101_4558(void*, short);
void* fn_101_45B8(void*, short);
void* fn_101_4618(void*, short);
void* fn_101_4674(void*, short);
void* fn_101_46F8(void*, short);
void* fn_101_47C4(void*, short);
void* fn_101_4820(void*, short);
void* fn_101_488C(void*, short);
void* fn_101_5C9C(void*, short);
void* fn_101_4988(void*, short);
void* fn_101_49F4(void*, short);
void* fn_101_4AAC(void*, short);
void* fn_101_4AEC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_101_4B48(void*, short);
}

// Destroy the embedded modules in reverse lifetime order. The signed short
// argument is the deleting-destructor ABI, not a boolean.
extern "C" void* fn_101_18430(void* object, short deleting) {
    unsigned char* members = static_cast<unsigned char*>(object);
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_3C14(members + 0xD6BC, memberDeleting);
        fn_101_3C70(members + 0xD67C, memberDeleting);
        fn_101_3CCC(members + 0xD664, memberDeleting);
        fn_101_3D28(members + 0xD4C8, memberDeleting);
        fn_101_185E4(members + 0x16D0, memberDeleting);
        fn_101_3DB4(members + 0x1674, memberDeleting);
        fn_101_3EB0(members + 0x15C0, memberDeleting);
        fn_101_18CCC(members + 0x13F8, memberDeleting);
        fn_101_429C(members + 0x1354, memberDeleting);
        fn_101_43D0(members + 0x1320, memberDeleting);
        fn_101_442C(members + 0x12FC, memberDeleting);
        fn_101_4490(members + 0x12E8, memberDeleting);
        fn_101_44EC(members + 0x1184, memberDeleting);
        fn_101_4558(members + 0x111C, memberDeleting);
        fn_101_45B8(members + 0x1110, memberDeleting);
        fn_101_4618(members + 0x10E8, memberDeleting);
        fn_101_4674(members + 0x0F18, memberDeleting);
        fn_101_46F8(members + 0x0EB4, memberDeleting);
        fn_101_47C4(members + 0x0E78, memberDeleting);
        fn_101_4820(members + 0x0DD0, memberDeleting);
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

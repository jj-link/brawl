#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_110_3B0C(void*, short);
void* fn_110_3B68(void*, short);
void* fn_110_3BC4(void*, short);
void* fn_110_3C20(void*, short);
void* fn_110_2F10(void*, short);
void* fn_110_3C7C(void*, short);
void* fn_110_F9B4(void*, short);
void* fn_110_FA14(void*, short);
void* fn_110_FA8C(void*, short);
void* fn_110_412C(void*, short);
void* fn_110_4260(void*, short);
void* fn_110_FBE4(void*, short);
void* fn_110_42BC(void*, short);
void* fn_110_FCA0(void*, short);
void* fn_110_4318(void*, short);
void* fn_110_4378(void*, short);
void* fn_110_43D8(void*, short);
void* fn_110_4434(void*, short);
void* fn_110_FD0C(void*, short);
void* fn_110_FD80(void*, short);
void* fn_110_FE04(void*, short);
void* fn_110_4490(void*, short);
void* fn_110_455C(void*, short);
void* fn_110_45B8(void*, short);
void* fn_110_4624(void*, short);
void* fn_110_FEE4(void*, short);
void* fn_110_4720(void*, short);
void* fn_110_478C(void*, short);
void* fn_110_4844(void*, short);
void* fn_110_4884(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_110_48E0(void*, short);
}

extern "C" void* fn_110_F7E0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_110_3B0C(storage + 0x22E4, memberDeleting);
        fn_110_3B68(storage + 0x22A4, memberDeleting);
        fn_110_3BC4(storage + 0x228C, memberDeleting);
        fn_110_3C20(storage + 0x2134, memberDeleting);
        fn_110_2F10(storage + 0x20E8, memberDeleting);
        fn_110_3C7C(storage + 0x1F50, memberDeleting);
        fn_110_F9B4(storage + 0x1EFC, memberDeleting);
        fn_110_FA14(storage + 0x1D74, memberDeleting);
        fn_110_FA8C(storage + 0x1B34, memberDeleting);
        fn_110_412C(storage + 0x1A90, memberDeleting);
        fn_110_4260(storage + 0x1A5C, memberDeleting);
        fn_110_FBE4(storage + 0x1A38, memberDeleting);
        fn_110_42BC(storage + 0x1A08, memberDeleting);
        fn_110_FCA0(storage + 0x1870, memberDeleting);
        fn_110_4318(storage + 0x1808, memberDeleting);
        fn_110_4378(storage + 0x17FC, memberDeleting);
        fn_110_43D8(storage + 0x17C4, memberDeleting);
        fn_110_4434(storage + 0x17A0, memberDeleting);
        fn_110_FD0C(storage + 0x15EC, memberDeleting);
        fn_110_FD80(storage + 0x1308, memberDeleting);
        fn_110_FE04(storage + 0x0F24, memberDeleting);
        fn_110_4490(storage + 0x0EC0, memberDeleting);
        fn_110_455C(storage + 0x0E84, memberDeleting);
        fn_110_45B8(storage + 0x0DDC, memberDeleting);
        fn_110_4624(storage + 0x0D28, memberDeleting);
        fn_110_FEE4(storage + 0x0B1C, memberDeleting);
        fn_110_4720(storage + 0x093C, memberDeleting);
        fn_110_478C(storage + 0x090C, memberDeleting);
        fn_110_4844(storage + 0x08FC, memberDeleting);
        fn_110_4884(storage + 0x08E4, memberDeleting);
        __dt__16soModuleAccesserFv(storage + 0x0804, memberDeleting);
        fn_110_48E0(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

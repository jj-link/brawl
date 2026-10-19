#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_110_3B0C(void*, short);
void* fn_110_3B68(void*, short);
void* fn_110_3BC4(void*, short);
void* fn_110_3C20(void*, short);
void* fn_110_3C7C(void*, short);
void* fn_110_1C230(void*, short);
void* fn_110_1C290(void*, short);
void* fn_110_1C41C(void*, short);
void* fn_110_412C(void*, short);
void* fn_110_4260(void*, short);
void* fn_110_1C574(void*, short);
void* fn_110_1C5D0(void*, short);
void* fn_110_4318(void*, short);
void* fn_110_4378(void*, short);
void* fn_110_4434(void*, short);
void* fn_110_1C63C(void*, short);
void* fn_110_4490(void*, short);
void* fn_110_455C(void*, short);
void* fn_110_4624(void*, short);
void* fn_110_1C6C0(void*, short);
void* fn_110_4720(void*, short);
void* fn_110_478C(void*, short);
void* fn_110_4844(void*, short);
void* fn_110_4884(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_110_48E0(void*, short);
}

extern "C" void* fn_110_1C0A4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_110_3B0C(storage + 0x195C, memberDeleting);
        fn_110_3B68(storage + 0x191C, memberDeleting);
        fn_110_3BC4(storage + 0x1904, memberDeleting);
        fn_110_3C20(storage + 0x17AC, memberDeleting);
        fn_110_3C7C(storage + 0x1614, memberDeleting);
        fn_110_1C230(storage + 0x15B4, memberDeleting);
        fn_110_1C290(storage + 0x1500, memberDeleting);
        fn_110_1C41C(storage + 0x1340, memberDeleting);
        fn_110_412C(storage + 0x129C, memberDeleting);
        fn_110_4260(storage + 0x1268, memberDeleting);
        fn_110_1C574(storage + 0x1250, memberDeleting);
        fn_110_1C5D0(storage + 0x10EC, memberDeleting);
        fn_110_4318(storage + 0x1084, memberDeleting);
        fn_110_4378(storage + 0x1078, memberDeleting);
        fn_110_4434(storage + 0x1050, memberDeleting);
        fn_110_1C63C(storage + 0x0E80, memberDeleting);
        fn_110_4490(storage + 0x0E1C, memberDeleting);
        fn_110_455C(storage + 0x0DE0, memberDeleting);
        fn_110_4624(storage + 0x0D28, memberDeleting);
        fn_110_1C6C0(storage + 0x0B1C, memberDeleting);
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

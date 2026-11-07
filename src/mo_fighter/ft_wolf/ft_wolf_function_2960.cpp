#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_125_2C00(void*, short);
void* fn_125_2C5C(void*, short);
void* fn_125_2CB8(void*, short);
void* fn_125_2D14(void*, short);
void* fn_125_2D70(void*, short);
void* fn_125_2DCC(void*, short);
void* fn_125_2EA8(void*, short);
void* fn_125_2F04(void*, short);
void* fn_125_2F60(void*, short);
void* fn_125_2FD4(void*, short);
void* fn_125_306C(void*, short);
void* fn_125_30C8(void*, short);
void* fn_125_3218(void*, short);
void* fn_125_6400(void*, short);
void* fn_125_6460(void*, short);
void* fn_125_64D8(void*, short);
void* fn_125_7048(void*, short);
void* fn_125_4024(void*, short);
void* fn_125_7124(void*, short);
void* fn_125_7198(void*, short);
void* fn_125_7274(void*, short);
void* fn_125_72D0(void*, short);
void* fn_125_733C(void*, short);
void* fn_125_73E8(void*, short);
void* fn_125_745C(void*, short);
void* fn_125_74B8(void*, short);
void* fn_125_7514(void*, short);
void* fn_125_7570(void*, short);
void* fn_125_75CC(void*, short);
void* fn_125_7640(void*, short);
void* fn_125_76AC(void*, short);
void* fn_125_773C(void*, short);
void* fn_125_77CC(void*, short);
void* fn_125_7850(void*, short);
void* fn_125_78D4(void*, short);
void* fn_125_4330(void*, short);
void* fn_125_4F90(void*, short);
void* fn_125_438C(void*, short);
void* fn_125_7A08(void*, short);
void* fn_125_7C3C(void*, short);
void* fn_125_7D10(void*, short);
void* fn_125_7D88(void*, short);
void* fn_125_4648(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_125_7DE4(void*, short);
}

extern "C" void* fn_125_2960(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_125_2C00(storage + 0x1ADD0, destroy);
        fn_125_2C5C(storage + 0x1AD94, destroy);
        fn_125_2CB8(storage + 0x1AD2C, destroy);
        fn_125_2D14(storage + 0x1ACE0, destroy);
        fn_125_2D70(storage + 0x1AB8C, destroy);
        fn_125_2DCC(storage + 0x1AA7C, destroy);
        fn_125_2EA8(storage + 0x1AA34, destroy);
        fn_125_2F04(storage + 0x1A9B4, destroy);
        fn_125_2F60(storage + 0x1A8F0, destroy);
        fn_125_2FD4(storage + 0x1A57C, destroy);
        fn_125_306C(storage + 0x1A54C, destroy);
        fn_125_30C8(storage + 0x1A3A8, destroy);
        fn_125_3218(storage + 0x56CC, destroy);
        fn_125_6400(storage + 0x54E8, destroy);
        fn_125_6460(storage + 0x51E0, destroy);
        fn_125_64D8(storage + 0x4360, destroy);
        fn_125_7048(storage + 0x426C, destroy);
        fn_125_4024(storage + 0x4238, destroy);
        fn_125_7124(storage + 0x41C4, destroy);
        fn_125_7198(storage + 0x3AA0, destroy);
        fn_125_7274(storage + 0x3A70, destroy);
        fn_125_72D0(storage + 0x38A4, destroy);
        fn_125_733C(storage + 0x3834, destroy);
        fn_125_73E8(storage + 0x379C, destroy);
        fn_125_745C(storage + 0x3764, destroy);
        fn_125_74B8(storage + 0x3740, destroy);
        fn_125_7514(storage + 0x370C, destroy);
        fn_125_7570(storage + 0x36A8, destroy);
        fn_125_75CC(storage + 0x34F8, destroy);
        fn_125_7640(storage + 0x3294, destroy);
        fn_125_76AC(storage + 0x2938, destroy);
        fn_125_773C(storage + 0x2720, destroy);
        fn_125_77CC(storage + 0x2104, destroy);
        fn_125_7850(storage + 0x1A48, destroy);
        fn_125_78D4(storage + 0x19D4, destroy);
        fn_125_4330(storage + 0x1998, destroy);
        fn_125_4F90(storage + 0x18F0, destroy);
        fn_125_438C(storage + 0x183C, destroy);
        fn_125_7A08(storage + 0x14A8, destroy);
        fn_125_7C3C(storage + 0x1180, destroy);
        fn_125_7D10(storage + 0x115C, destroy);
        fn_125_7D88(storage + 0xAC8, destroy);
        fn_125_4648(storage + 0xAB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x9D0, destroy);
        fn_125_7DE4(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

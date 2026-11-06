#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_112_2BE0(void*, short);
void* fn_112_2C3C(void*, short);
void* fn_112_2C98(void*, short);
void* fn_112_2CF4(void*, short);
void* fn_112_2D50(void*, short);
void* fn_112_2DAC(void*, short);
void* fn_112_2E88(void*, short);
void* fn_112_2EE4(void*, short);
void* fn_112_2F40(void*, short);
void* fn_112_2FB4(void*, short);
void* fn_112_304C(void*, short);
void* fn_112_30A8(void*, short);
void* fn_112_31F8(void*, short);
void* fn_112_5A18(void*, short);
void* fn_112_5A78(void*, short);
void* fn_112_5AF0(void*, short);
void* fn_112_6660(void*, short);
void* fn_112_38D8(void*, short);
void* fn_112_673C(void*, short);
void* fn_112_67B0(void*, short);
void* fn_112_688C(void*, short);
void* fn_112_68E8(void*, short);
void* fn_112_6954(void*, short);
void* fn_112_6A00(void*, short);
void* fn_112_6A74(void*, short);
void* fn_112_6AD0(void*, short);
void* fn_112_6B2C(void*, short);
void* fn_112_6B88(void*, short);
void* fn_112_6BE4(void*, short);
void* fn_112_6C58(void*, short);
void* fn_112_6CC4(void*, short);
void* fn_112_6D54(void*, short);
void* fn_112_6DE4(void*, short);
void* fn_112_6E68(void*, short);
void* fn_112_6EEC(void*, short);
void* fn_112_4C2C(void*, short);
void* fn_112_4C88(void*, short);
void* fn_112_4CF4(void*, short);
void* fn_112_7020(void*, short);
void* fn_112_7388(void*, short);
void* fn_112_745C(void*, short);
void* fn_112_74D4(void*, short);
void* fn_112_3ECC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_112_7530(void*, short);
}

extern "C" void* fn_112_2940(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_112_2BE0(members + 0x278F0, memberDeleting);
        fn_112_2C3C(members + 0x278B4, memberDeleting);
        fn_112_2C98(members + 0x2784C, memberDeleting);
        fn_112_2CF4(members + 0x27800, memberDeleting);
        fn_112_2D50(members + 0x276AC, memberDeleting);
        fn_112_2DAC(members + 0x2759C, memberDeleting);
        fn_112_2E88(members + 0x27554, memberDeleting);
        fn_112_2EE4(members + 0x274D4, memberDeleting);
        fn_112_2F40(members + 0x27410, memberDeleting);
        fn_112_2FB4(members + 0x2709C, memberDeleting);
        fn_112_304C(members + 0x2706C, memberDeleting);
        fn_112_30A8(members + 0x26EC8, memberDeleting);
        fn_112_31F8(members + 0x588C, memberDeleting);
        fn_112_5A18(members + 0x56A8, memberDeleting);
        fn_112_5A78(members + 0x53A0, memberDeleting);
        fn_112_5AF0(members + 0x451C, memberDeleting);
        fn_112_6660(members + 0x4428, memberDeleting);
        fn_112_38D8(members + 0x43F4, memberDeleting);
        fn_112_673C(members + 0x4380, memberDeleting);
        fn_112_67B0(members + 0x3C5C, memberDeleting);
        fn_112_688C(members + 0x3C2C, memberDeleting);
        fn_112_68E8(members + 0x3A94, memberDeleting);
        fn_112_6954(members + 0x3A24, memberDeleting);
        fn_112_6A00(members + 0x398C, memberDeleting);
        fn_112_6A74(members + 0x3954, memberDeleting);
        fn_112_6AD0(members + 0x3930, memberDeleting);
        fn_112_6B2C(members + 0x38FC, memberDeleting);
        fn_112_6B88(members + 0x3898, memberDeleting);
        fn_112_6BE4(members + 0x36E8, memberDeleting);
        fn_112_6C58(members + 0x3484, memberDeleting);
        fn_112_6CC4(members + 0x29F8, memberDeleting);
        fn_112_6D54(members + 0x2650, memberDeleting);
        fn_112_6DE4(members + 0x209C, memberDeleting);
        fn_112_6E68(members + 0x19E0, memberDeleting);
        fn_112_6EEC(members + 0x196C, memberDeleting);
        fn_112_4C2C(members + 0x1930, memberDeleting);
        fn_112_4C88(members + 0x1888, memberDeleting);
        fn_112_4CF4(members + 0x17D4, memberDeleting);
        fn_112_7020(members + 0x1440, memberDeleting);
        fn_112_7388(members + 0x1180, memberDeleting);
        fn_112_745C(members + 0x115C, memberDeleting);
        fn_112_74D4(members + 0xAC8, memberDeleting);
        fn_112_3ECC(members + 0xAB0, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x9D0, memberDeleting);
        fn_112_7530(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

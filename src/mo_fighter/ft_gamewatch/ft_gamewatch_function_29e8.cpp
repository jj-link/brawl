#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_107_2C94(void*, short);
void* fn_107_2CF0(void*, short);
void* fn_107_2D4C(void*, short);
void* fn_107_2DA8(void*, short);
void* fn_107_2E04(void*, short);
void* fn_107_2E60(void*, short);
void* fn_107_2F3C(void*, short);
void* fn_107_2F98(void*, short);
void* fn_107_2FF4(void*, short);
void* fn_107_3068(void*, short);
void* fn_107_3100(void*, short);
void* fn_107_315C(void*, short);
void* fn_107_32AC(void*, short);
void* fn_107_6880(void*, short);
void* fn_107_68E0(void*, short);
void* fn_107_6A34(void*, short);
void* fn_107_75A4(void*, short);
void* fn_107_4204(void*, short);
void* fn_107_7680(void*, short);
void* fn_107_76F4(void*, short);
void* fn_107_77D0(void*, short);
void* fn_107_782C(void*, short);
void* fn_107_7898(void*, short);
void* fn_107_7944(void*, short);
void* fn_107_79B8(void*, short);
void* fn_107_7A14(void*, short);
void* fn_107_7A70(void*, short);
void* fn_107_7ACC(void*, short);
void* fn_107_7B28(void*, short);
void* fn_107_7B9C(void*, short);
void* fn_107_7C08(void*, short);
void* fn_107_7C98(void*, short);
void* fn_107_7D28(void*, short);
void* fn_107_7DB8(void*, short);
void* fn_107_7E3C(void*, short);
void* fn_107_7EC0(void*, short);
void* fn_107_4594(void*, short);
void* fn_107_45F0(void*, short);
void* fn_107_465C(void*, short);
void* fn_107_7FF4(void*, short);
void* fn_107_835C(void*, short);
void* fn_107_8430(void*, short);
void* fn_107_84A8(void*, short);
void* fn_107_4918(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_107_8504(void*, short);
}

extern "C" void* fn_107_29E8(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_107_2C94(storage + 0x1DE3C, destroy);
        fn_107_2CF0(storage + 0x1DE00, destroy);
        fn_107_2D4C(storage + 0x1DD98, destroy);
        fn_107_2DA8(storage + 0x1DD4C, destroy);
        fn_107_2E04(storage + 0x1DBF8, destroy);
        fn_107_2E60(storage + 0x1DAE8, destroy);
        fn_107_2F3C(storage + 0x1DAA0, destroy);
        fn_107_2F98(storage + 0x1DA20, destroy);
        fn_107_2FF4(storage + 0x1D95C, destroy);
        fn_107_3068(storage + 0x1D5E8, destroy);
        fn_107_3100(storage + 0x1D5B8, destroy);
        fn_107_315C(storage + 0x1D414, destroy);
        fn_107_32AC(storage + 0x5CF8, destroy);
        fn_107_6880(storage + 0x5B14, destroy);
        fn_107_68E0(storage + 0x580C, destroy);
        fn_107_6A34(storage + 0x4928, destroy);
        fn_107_75A4(storage + 0x4834, destroy);
        fn_107_4204(storage + 0x4800, destroy);
        fn_107_7680(storage + 0x478C, destroy);
        fn_107_76F4(storage + 0x4068, destroy);
        fn_107_77D0(storage + 0x4038, destroy);
        fn_107_782C(storage + 0x3EA0, destroy);
        fn_107_7898(storage + 0x3E30, destroy);
        fn_107_7944(storage + 0x3D98, destroy);
        fn_107_79B8(storage + 0x3D60, destroy);
        fn_107_7A14(storage + 0x3D3C, destroy);
        fn_107_7A70(storage + 0x3D08, destroy);
        fn_107_7ACC(storage + 0x3CA4, destroy);
        fn_107_7B28(storage + 0x3AF4, destroy);
        fn_107_7B9C(storage + 0x3890, destroy);
        fn_107_7C08(storage + 0x3678, destroy);
        fn_107_7C98(storage + 0x2C10, destroy);
        fn_107_7D28(storage + 0x29F8, destroy);
        fn_107_7DB8(storage + 0x209C, destroy);
        fn_107_7E3C(storage + 0x19E0, destroy);
        fn_107_7EC0(storage + 0x196C, destroy);
        fn_107_4594(storage + 0x1930, destroy);
        fn_107_45F0(storage + 0x1888, destroy);
        fn_107_465C(storage + 0x17D4, destroy);
        fn_107_7FF4(storage + 0x1440, destroy);
        fn_107_835C(storage + 0x1180, destroy);
        fn_107_8430(storage + 0x115C, destroy);
        fn_107_84A8(storage + 0xAC8, destroy);
        fn_107_4918(storage + 0xAB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x9D0, destroy);
        fn_107_8504(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

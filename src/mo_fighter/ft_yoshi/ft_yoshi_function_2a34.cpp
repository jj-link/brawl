#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_95_2CD4(void*, short);
void* fn_95_2D30(void*, short);
void* fn_95_2D8C(void*, short);
void* fn_95_2DE8(void*, short);
void* fn_95_2E44(void*, short);
void* fn_95_2EA0(void*, short);
void* fn_95_2F7C(void*, short);
void* fn_95_2FD8(void*, short);
void* fn_95_3034(void*, short);
void* fn_95_30A8(void*, short);
void* fn_95_3140(void*, short);
void* fn_95_319C(void*, short);
void* fn_95_32EC(void*, short);
void* fn_95_61F8(void*, short);
void* fn_95_6258(void*, short);
void* fn_95_63AC(void*, short);
void* fn_95_6F1C(void*, short);
void* fn_95_4288(void*, short);
void* fn_95_6FF8(void*, short);
void* fn_95_706C(void*, short);
void* fn_95_7148(void*, short);
void* fn_95_71A4(void*, short);
void* fn_95_7210(void*, short);
void* fn_95_72BC(void*, short);
void* fn_95_7330(void*, short);
void* fn_95_738C(void*, short);
void* fn_95_73E8(void*, short);
void* fn_95_7444(void*, short);
void* fn_95_74A0(void*, short);
void* fn_95_7514(void*, short);
void* fn_95_7580(void*, short);
void* fn_95_7610(void*, short);
void* fn_95_76A0(void*, short);
void* fn_95_7724(void*, short);
void* fn_95_77A8(void*, short);
void* fn_95_4618(void*, short);
void* fn_95_4674(void*, short);
void* fn_95_46E0(void*, short);
void* fn_95_78DC(void*, short);
void* fn_95_7C44(void*, short);
void* fn_95_7D18(void*, short);
void* fn_95_7D90(void*, short);
void* fn_95_49B8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_95_7DEC(void*, short);
}

extern "C" void* fn_95_2A34(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_95_2CD4(storage + 0x203A8, destroy);
        fn_95_2D30(storage + 0x2036C, destroy);
        fn_95_2D8C(storage + 0x20304, destroy);
        fn_95_2DE8(storage + 0x202B8, destroy);
        fn_95_2E44(storage + 0x20164, destroy);
        fn_95_2EA0(storage + 0x20054, destroy);
        fn_95_2F7C(storage + 0x2000C, destroy);
        fn_95_2FD8(storage + 0x1FF8C, destroy);
        fn_95_3034(storage + 0x1FEC8, destroy);
        fn_95_30A8(storage + 0x1FB54, destroy);
        fn_95_3140(storage + 0x1FB24, destroy);
        fn_95_319C(storage + 0x1F980, destroy);
        fn_95_32EC(storage + 0x5B24, destroy);
        fn_95_61F8(storage + 0x5940, destroy);
        fn_95_6258(storage + 0x5638, destroy);
        fn_95_63AC(storage + 0x47A4, destroy);
        fn_95_6F1C(storage + 0x46B0, destroy);
        fn_95_4288(storage + 0x467C, destroy);
        fn_95_6FF8(storage + 0x4608, destroy);
        fn_95_706C(storage + 0x3EE4, destroy);
        fn_95_7148(storage + 0x3EB4, destroy);
        fn_95_71A4(storage + 0x3D1C, destroy);
        fn_95_7210(storage + 0x3CAC, destroy);
        fn_95_72BC(storage + 0x3C14, destroy);
        fn_95_7330(storage + 0x3BDC, destroy);
        fn_95_738C(storage + 0x3BB8, destroy);
        fn_95_73E8(storage + 0x3B84, destroy);
        fn_95_7444(storage + 0x3B20, destroy);
        fn_95_74A0(storage + 0x3970, destroy);
        fn_95_7514(storage + 0x370C, destroy);
        fn_95_7580(storage + 0x2CA0, destroy);
        fn_95_7610(storage + 0x2A88, destroy);
        fn_95_76A0(storage + 0x212C, destroy);
        fn_95_7724(storage + 0x1A70, destroy);
        fn_95_77A8(storage + 0x19FC, destroy);
        fn_95_4618(storage + 0x19C0, destroy);
        fn_95_4674(storage + 0x1918, destroy);
        fn_95_46E0(storage + 0x1864, destroy);
        fn_95_78DC(storage + 0x1440, destroy);
        fn_95_7C44(storage + 0x1180, destroy);
        fn_95_7D18(storage + 0x115C, destroy);
        fn_95_7D90(storage + 0x0AC8, destroy);
        fn_95_49B8(storage + 0x0AB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x09D0, destroy);
        fn_95_7DEC(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

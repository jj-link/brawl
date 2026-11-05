#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_107_3A8C(void*, short);
void* fn_107_3AE8(void*, short);
void* fn_107_3B44(void*, short);
void* fn_107_3BA0(void*, short);
void* fn_107_3C2C(void*, short);
void* fn_107_3D28(void*, short);
void* fn_107_1EC74(void*, short);
void* fn_107_40D0(void*, short);
void* fn_107_4204(void*, short);
void* fn_107_4260(void*, short);
void* fn_107_42BC(void*, short);
void* fn_107_4328(void*, short);
void* fn_107_4388(void*, short);
void* fn_107_43E8(void*, short);
void* fn_107_1EDCC(void*, short);
void* fn_107_1EE40(void*, short);
void* fn_107_1EEC4(void*, short);
void* fn_107_44C8(void*, short);
void* fn_107_4594(void*, short);
void* fn_107_465C(void*, short);
void* fn_107_1EF48(void*, short);
void* fn_107_47B4(void*, short);
void* fn_107_4820(void*, short);
void* fn_107_48D8(void*, short);
void* fn_107_4918(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_107_4974(void*, short);
}

extern "C" void* fn_107_1EADC(void* object, short deleting)
{
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_107_3A8C(p + 0x2180, -1);
        fn_107_3AE8(p + 0x2168, -1);
        fn_107_3B44(p + 0x2010, -1);
        fn_107_3BA0(p + 0x1E78, -1);
        fn_107_3C2C(p + 0x1E18, -1);
        fn_107_3D28(p + 0x1D64, -1);
        fn_107_1EC74(p + 0x1B94, -1);
        fn_107_40D0(p + 0x1AF0, -1);
        fn_107_4204(p + 0x1ABC, -1);
        fn_107_4260(p + 0x1AA4, -1);
        fn_107_42BC(p + 0x1940, -1);
        fn_107_4328(p + 0x18D8, -1);
        fn_107_4388(p + 0x18CC, -1);
        fn_107_43E8(p + 0x18A4, -1);
        fn_107_1EDCC(p + 0x1748, -1);
        fn_107_1EE40(p + 0x1464, -1);
        fn_107_1EEC4(p + 0xEB0, -1);
        fn_107_44C8(p + 0xE4C, -1);
        fn_107_4594(p + 0xE10, -1);
        fn_107_465C(p + 0xD58, -1);
        fn_107_1EF48(p + 0xB10, -1);
        fn_107_47B4(p + 0x930, -1);
        fn_107_4820(p + 0x900, -1);
        fn_107_48D8(p + 0x8F0, -1);
        fn_107_4918(p + 0x8D8, -1);
        __dt__16soModuleAccesserFv(p + 0x7F8, -1);
        fn_107_4974(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

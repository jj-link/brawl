#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_111_2AD0(void*, short);
void* fn_111_2B2C(void*, short);
void* fn_111_2B88(void*, short);
void* fn_111_2BE4(void*, short);
void* fn_111_2C40(void*, short);
void* fn_111_2C9C(void*, short);
void* fn_111_2D78(void*, short);
void* fn_111_2DD4(void*, short);
void* fn_111_2E30(void*, short);
void* fn_111_2EA4(void*, short);
void* fn_111_2F3C(void*, short);
void* fn_111_2F98(void*, short);
void* fn_111_30E8(void*, short);
void* fn_111_40BC(void*, short);
void* fn_111_411C(void*, short);
void* fn_111_4270(void*, short);
void* fn_111_4DE0(void*, short);
void* fn_111_3D98(void*, short);
void* fn_111_4EBC(void*, short);
void* fn_111_4F30(void*, short);
void* fn_111_500C(void*, short);
void* fn_111_5068(void*, short);
void* fn_111_50D4(void*, short);
void* fn_111_5180(void*, short);
void* fn_111_51F4(void*, short);
void* fn_111_5250(void*, short);
void* fn_111_52AC(void*, short);
void* fn_111_5308(void*, short);
void* fn_111_5364(void*, short);
void* fn_111_53D8(void*, short);
void* fn_111_5444(void*, short);
void* fn_111_54D4(void*, short);
void* fn_111_5564(void*, short);
void* fn_111_55E8(void*, short);
void* fn_111_566C(void*, short);
void* fn_111_3E34(void*, short);
void* fn_111_57A0(void*, short);
void* fn_111_3E90(void*, short);
void* fn_111_580C(void*, short);
void* fn_111_5B74(void*, short);
void* fn_111_5C48(void*, short);
void* fn_111_5CC0(void*, short);
void* fn_111_3FA0(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_111_5D1C(void*, short);
}

extern "C" void* fn_111_283C(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_111_2AD0(storage + 0x8748, destroy);
        fn_111_2B2C(storage + 0x870C, destroy);
        fn_111_2B88(storage + 0x86A4, destroy);
        fn_111_2BE4(storage + 0x8658, destroy);
        fn_111_2C40(storage + 0x8504, destroy);
        fn_111_2C9C(storage + 0x83F4, destroy);
        fn_111_2D78(storage + 0x83AC, destroy);
        fn_111_2DD4(storage + 0x832C, destroy);
        fn_111_2E30(storage + 0x8268, destroy);
        fn_111_2EA4(storage + 0x7EF4, destroy);
        fn_111_2F3C(storage + 0x7EC4, destroy);
        fn_111_2F98(storage + 0x7D20, destroy);
        fn_111_30E8(storage + 0x5BA8, destroy);
        fn_111_40BC(storage + 0x59C4, destroy);
        fn_111_411C(storage + 0x56BC, destroy);
        fn_111_4270(storage + 0x480C, destroy);
        fn_111_4DE0(storage + 0x4718, destroy);
        fn_111_3D98(storage + 0x46E4, destroy);
        fn_111_4EBC(storage + 0x4670, destroy);
        fn_111_4F30(storage + 0x3F4C, destroy);
        fn_111_500C(storage + 0x3F1C, destroy);
        fn_111_5068(storage + 0x3C4C, destroy);
        fn_111_50D4(storage + 0x3BDC, destroy);
        fn_111_5180(storage + 0x3B44, destroy);
        fn_111_51F4(storage + 0x3B0C, destroy);
        fn_111_5250(storage + 0x3AE8, destroy);
        fn_111_52AC(storage + 0x3AB4, destroy);
        fn_111_5308(storage + 0x3A50, destroy);
        fn_111_5364(storage + 0x38A0, destroy);
        fn_111_53D8(storage + 0x363C, destroy);
        fn_111_5444(storage + 0x2BD0, destroy);
        fn_111_54D4(storage + 0x29B8, destroy);
        fn_111_5564(storage + 0x205C, destroy);
        fn_111_55E8(storage + 0x19E0, destroy);
        fn_111_566C(storage + 0x196C, destroy);
        fn_111_3E34(storage + 0x1930, destroy);
        fn_111_57A0(storage + 0x1888, destroy);
        fn_111_3E90(storage + 0x17D4, destroy);
        fn_111_580C(storage + 0x1440, destroy);
        fn_111_5B74(storage + 0x1180, destroy);
        fn_111_5C48(storage + 0x115C, destroy);
        fn_111_5CC0(storage + 0x0AC8, destroy);
        fn_111_3FA0(storage + 0x0AB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x09D0, destroy);
        fn_111_5D1C(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

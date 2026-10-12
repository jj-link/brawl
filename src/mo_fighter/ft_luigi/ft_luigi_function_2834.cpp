void operator delete(void*);
extern "C" {
void* fn_99_2AD4(void*, short);
void* fn_99_2B30(void*, short);
void* fn_99_2B8C(void*, short);
void* fn_99_2BE8(void*, short);
void* fn_99_2C44(void*, short);
void* fn_99_2CA0(void*, short);
void* fn_99_2D7C(void*, short);
void* fn_99_2DD8(void*, short);
void* fn_99_2E34(void*, short);
void* fn_99_2EA8(void*, short);
void* fn_99_2F40(void*, short);
void* fn_99_2F9C(void*, short);
void* fn_99_30EC(void*, short);
void* fn_99_42A0(void*, short);
void* fn_99_4300(void*, short);
void* fn_99_4454(void*, short);
void* fn_99_4FC4(void*, short);
void* fn_99_3FD8(void*, short);
void* fn_99_50A0(void*, short);
void* fn_99_5114(void*, short);
void* fn_99_51F0(void*, short);
void* fn_99_524C(void*, short);
void* fn_99_52B8(void*, short);
void* fn_99_5364(void*, short);
void* fn_99_53D8(void*, short);
void* fn_99_5434(void*, short);
void* fn_99_5490(void*, short);
void* fn_99_54EC(void*, short);
void* fn_99_5548(void*, short);
void* fn_99_55BC(void*, short);
void* fn_99_5628(void*, short);
void* fn_99_56B8(void*, short);
void* fn_99_5748(void*, short);
void* fn_99_57CC(void*, short);
void* fn_99_5850(void*, short);
void* fn_99_4074(void*, short);
void* fn_99_5984(void*, short);
void* fn_99_40D0(void*, short);
void* fn_99_59F0(void*, short);
void* fn_99_5DB4(void*, short);
void* fn_99_5E88(void*, short);
void* fn_99_5F00(void*, short);
void* fn_99_4184(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_99_5F5C(void*, short);
}

// The module aggregate owns these embedded lifetimes. Tear them down in
// reverse construction order before releasing the aggregate itself.
extern "C" void* fn_99_2834(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_99_2AD4(storage + 0xC368, destroy);
        fn_99_2B30(storage + 0xC32C, destroy);
        fn_99_2B8C(storage + 0xC2C4, destroy);
        fn_99_2BE8(storage + 0xC278, destroy);
        fn_99_2C44(storage + 0xC124, destroy);
        fn_99_2CA0(storage + 0xC014, destroy);
        fn_99_2D7C(storage + 0xBFCC, destroy);
        fn_99_2DD8(storage + 0xBF4C, destroy);
        fn_99_2E34(storage + 0xBE88, destroy);
        fn_99_2EA8(storage + 0xBB14, destroy);
        fn_99_2F40(storage + 0xBAE4, destroy);
        fn_99_2F9C(storage + 0xB940, destroy);
        fn_99_30EC(storage + 0x5940, destroy);
        fn_99_42A0(storage + 0x575C, destroy);
        fn_99_4300(storage + 0x5454, destroy);
        fn_99_4454(storage + 0x45E0, destroy);
        fn_99_4FC4(storage + 0x44EC, destroy);
        fn_99_3FD8(storage + 0x44B8, destroy);
        fn_99_50A0(storage + 0x4444, destroy);
        fn_99_5114(storage + 0x3D20, destroy);
        fn_99_51F0(storage + 0x3CF0, destroy);
        fn_99_524C(storage + 0x3B58, destroy);
        fn_99_52B8(storage + 0x3AE8, destroy);
        fn_99_5364(storage + 0x3A50, destroy);
        fn_99_53D8(storage + 0x3A18, destroy);
        fn_99_5434(storage + 0x39F4, destroy);
        fn_99_5490(storage + 0x39C0, destroy);
        fn_99_54EC(storage + 0x395C, destroy);
        fn_99_5548(storage + 0x37AC, destroy);
        fn_99_55BC(storage + 0x3548, destroy);
        fn_99_5628(storage + 0x2CAC, destroy);
        fn_99_56B8(storage + 0x2A94, destroy);
        fn_99_5748(storage + 0x2138, destroy);
        fn_99_57CC(storage + 0x1A7C, destroy);
        fn_99_5850(storage + 0x1A08, destroy);
        fn_99_4074(storage + 0x19CC, destroy);
        fn_99_5984(storage + 0x1924, destroy);
        fn_99_40D0(storage + 0x1870, destroy);
        fn_99_59F0(storage + 0x14DC, destroy);
        fn_99_5DB4(storage + 0x1180, destroy);
        fn_99_5E88(storage + 0x115C, destroy);
        fn_99_5F00(storage + 0x0AC8, destroy);
        fn_99_4184(storage + 0x0AB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x09D0, destroy);
        fn_99_5F5C(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma force_active on
extern "C" void* fn_116_394C(void*, short);
extern "C" void* fn_116_3A04(void*, short);
extern "C" void* fn_116_3A60(void*, short);
extern "C" void* fn_116_FCB8(void*, short);
extern "C" void* fn_116_FD30(void*, short);
extern "C" void* fn_116_3B68(void*, short);
extern "C" void* fn_116_FD90(void*, short);
extern "C" void* fn_116_3D88(void*, short);
extern "C" void* fn_116_3EBC(void*, short);
extern "C" void* fn_116_FEE8(void*, short);
extern "C" void* fn_116_3F18(void*, short);
extern "C" void* fn_116_FF44(void*, short);
extern "C" void* fn_116_3F84(void*, short);
extern "C" void* fn_116_3FE4(void*, short);
extern "C" void* fn_116_FFF0(void*, short);
extern "C" void* fn_116_40C4(void*, short);
extern "C" void* fn_116_4190(void*, short);
extern "C" void* fn_116_41EC(void*, short);
extern "C" void* fn_116_100D0(void*, short);
extern "C" void* fn_116_10144(void*, short);
extern "C" void* fn_116_4C04(void*, short);
extern "C" void* fn_116_4C70(void*, short);
extern "C" void* fn_116_42CC(void*, short);
extern "C" void* fn_116_430C(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_116_102B4(void*, short);
void operator delete(void*);

extern "C" void* fn_116_FB2C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_394C(storage + 0x142c, -1);
        fn_116_3A04(storage + 0x1410, -1);
        fn_116_3A60(storage + 0x12b8, -1);
        fn_116_FCB8(storage + 0x124c, -1);
        fn_116_FD30(storage + 0x11e0, -1);
        fn_116_3B68(storage + 0x1174, -1);
        fn_116_FD90(storage + 0xff8, -1);
        fn_116_3D88(storage + 0xf54, -1);
        fn_116_3EBC(storage + 0xf20, -1);
        fn_116_FEE8(storage + 0xf08, -1);
        fn_116_3F18(storage + 0xda4, -1);
        fn_116_FF44(storage + 0xd3c, -1);
        fn_116_3F84(storage + 0xd30, -1);
        fn_116_3FE4(storage + 0xd08, -1);
        fn_116_FFF0(storage + 0xb5c, -1);
        fn_116_40C4(storage + 0xaf4, -1);
        fn_116_4190(storage + 0xab8, -1);
        fn_116_41EC(storage + 0xa10, -1);
        fn_116_100D0(storage + 0x92c, -1);
        fn_116_10144(storage + 0x750, -1);
        fn_116_4C04(storage + 0x60c, -1);
        fn_116_4C70(storage + 0x5dc, -1);
        fn_116_42CC(storage + 0x5cc, -1);
        fn_116_430C(storage + 0x5b4, -1);
        __dt__16soModuleAccesserFv(storage + 0x4d4, -1);
        fn_116_102B4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

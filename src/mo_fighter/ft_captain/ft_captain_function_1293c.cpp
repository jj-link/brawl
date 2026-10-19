#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_100_3904(void*, short);
void* fn_100_3960(void*, short);
void* fn_100_12AC8(void*, short);
void* fn_100_2DF4(void*, short);
void* fn_100_39BC(void*, short);
void* fn_100_3A48(void*, short);
void* fn_100_3B44(void*, short);
void* fn_100_12B24(void*, short);
void* fn_100_3EEC(void*, short);
void* fn_100_4020(void*, short);
void* fn_100_407C(void*, short);
void* fn_100_40D8(void*, short);
void* fn_100_4144(void*, short);
void* fn_100_41A4(void*, short);
void* fn_100_4204(void*, short);
void* fn_100_4260(void*, short);
void* fn_100_42E4(void*, short);
void* fn_100_43B0(void*, short);
void* fn_100_440C(void*, short);
void* fn_100_12C78(void*, short);
void* fn_100_4564(void*, short);
void* fn_100_45D0(void*, short);
void* fn_100_4688(void*, short);
void* fn_100_46C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_100_4724(void*, short);
}

extern "C" void* fn_100_1293C(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_3904(storage + 0x19a4, destroy);
        fn_100_3960(storage + 0x198c, destroy);
        fn_100_12AC8(storage + 0x1834, destroy);
        fn_100_2DF4(storage + 0x17e8, destroy);
        fn_100_39BC(storage + 0x1650, destroy);
        fn_100_3A48(storage + 0x15f0, destroy);
        fn_100_3B44(storage + 0x153c, destroy);
        fn_100_12B24(storage + 0x1370, destroy);
        fn_100_3EEC(storage + 0x12cc, destroy);
        fn_100_4020(storage + 0x1298, destroy);
        fn_100_407C(storage + 0x1280, destroy);
        fn_100_40D8(storage + 0x111c, destroy);
        fn_100_4144(storage + 0x10b4, destroy);
        fn_100_41A4(storage + 0x10a8, destroy);
        fn_100_4204(storage + 0x1080, destroy);
        fn_100_4260(storage + 0xeb0, destroy);
        fn_100_42E4(storage + 0xe4c, destroy);
        fn_100_43B0(storage + 0xe10, destroy);
        fn_100_440C(storage + 0xd58, destroy);
        fn_100_12C78(storage + 0xb10, destroy);
        fn_100_4564(storage + 0x930, destroy);
        fn_100_45D0(storage + 0x900, destroy);
        fn_100_4688(storage + 0x8f0, destroy);
        fn_100_46C8(storage + 0x8d8, destroy);
        __dt__16soModuleAccesserFv(storage + 0x7f8, destroy);
        fn_100_4724(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_100_3904(void*, short);
void* fn_100_3960(void*, short);
void* fn_100_39BC(void*, short);
void* fn_100_3A48(void*, short);
void* fn_100_3B44(void*, short);
void* fn_100_15474(void*, short);
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
void* fn_100_1556C(void*, short);
void* fn_100_4564(void*, short);
void* fn_100_45D0(void*, short);
void* fn_100_4688(void*, short);
void* fn_100_46C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_100_4724(void*, short);
}

extern "C" void* fn_100_15300(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_3904(storage + 0x17BC, destroy);
        fn_100_3960(storage + 0x17A4, destroy);
        fn_100_39BC(storage + 0x1608, destroy);
        fn_100_3A48(storage + 0x15A8, destroy);
        fn_100_3B44(storage + 0x14F4, destroy);
        fn_100_15474(storage + 0x1334, destroy);
        fn_100_3EEC(storage + 0x1290, destroy);
        fn_100_4020(storage + 0x125C, destroy);
        fn_100_407C(storage + 0x1244, destroy);
        fn_100_40D8(storage + 0x10E0, destroy);
        fn_100_4144(storage + 0x1078, destroy);
        fn_100_41A4(storage + 0x106C, destroy);
        fn_100_4204(storage + 0x1044, destroy);
        fn_100_4260(storage + 0xE74, destroy);
        fn_100_42E4(storage + 0xE10, destroy);
        fn_100_43B0(storage + 0xDD4, destroy);
        fn_100_440C(storage + 0xD1C, destroy);
        fn_100_1556C(storage + 0xB10, destroy);
        fn_100_4564(storage + 0x930, destroy);
        fn_100_45D0(storage + 0x900, destroy);
        fn_100_4688(storage + 0x8F0, destroy);
        fn_100_46C8(storage + 0x8D8, destroy);
        __dt__16soModuleAccesserFv(storage + 0x7F8, destroy);
        fn_100_4724(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

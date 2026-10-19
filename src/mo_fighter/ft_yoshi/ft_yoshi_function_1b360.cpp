#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_95_3AC8(void*, short);
void* fn_95_3B24(void*, short);
void* fn_95_3B80(void*, short);
void* fn_95_3C0C(void*, short);
void* fn_95_3D08(void*, short);
void* fn_95_3E44(void*, short);
void* fn_95_4154(void*, short);
void* fn_95_4288(void*, short);
void* fn_95_42E4(void*, short);
void* fn_95_4340(void*, short);
void* fn_95_43AC(void*, short);
void* fn_95_440C(void*, short);
void* fn_95_446C(void*, short);
void* fn_95_44C8(void*, short);
void* fn_95_454C(void*, short);
void* fn_95_4618(void*, short);
void* fn_95_46E0(void*, short);
void* fn_95_4754(void*, short);
void* fn_95_4854(void*, short);
void* fn_95_48C0(void*, short);
void* fn_95_4978(void*, short);
void* fn_95_49B8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_95_4A14(void*, short);

void* fn_95_1B360(void* object, short deleting)
{
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;

        fn_95_3AC8(storage + 0x17BC, destroy);
        fn_95_3B24(storage + 0x17A4, destroy);
        fn_95_3B80(storage + 0x1608, destroy);
        fn_95_3C0C(storage + 0x15A8, destroy);
        fn_95_3D08(storage + 0x14F4, destroy);
        fn_95_3E44(storage + 0x1334, destroy);
        fn_95_4154(storage + 0x1290, destroy);
        fn_95_4288(storage + 0x125C, destroy);
        fn_95_42E4(storage + 0x1244, destroy);
        fn_95_4340(storage + 0x10E0, destroy);
        fn_95_43AC(storage + 0x1078, destroy);
        fn_95_440C(storage + 0x106C, destroy);
        fn_95_446C(storage + 0x1044, destroy);
        fn_95_44C8(storage + 0x0E74, destroy);
        fn_95_454C(storage + 0x0E10, destroy);
        fn_95_4618(storage + 0x0DD4, destroy);
        fn_95_46E0(storage + 0x0D1C, destroy);
        fn_95_4754(storage + 0x0B10, destroy);
        fn_95_4854(storage + 0x0930, destroy);
        fn_95_48C0(storage + 0x0900, destroy);
        fn_95_4978(storage + 0x08F0, destroy);
        fn_95_49B8(storage + 0x08D8, destroy);
        __dt__16soModuleAccesserFv(storage + 0x07F8, destroy);
        fn_95_4A14(object, destroy);

        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}

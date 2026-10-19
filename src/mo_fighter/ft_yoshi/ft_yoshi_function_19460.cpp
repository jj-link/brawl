#pragma force_active on

void operator delete(void*);

extern "C" {
void* fn_95_3AC8(void*, short);
void* fn_95_3B24(void*, short);
void* fn_95_195EC(void*, short);
void* fn_95_2F7C(void*, short);
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
void* fn_95_19648(void*, short);
void* fn_95_4854(void*, short);
void* fn_95_48C0(void*, short);
void* fn_95_4978(void*, short);
void* fn_95_49B8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_95_196CC(void*, short);

void* fn_95_19460(void* object, short deleting)
{
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;

        fn_95_3AC8(storage + 0x19A4, destroy);
        fn_95_3B24(storage + 0x198C, destroy);
        fn_95_195EC(storage + 0x1834, destroy);
        fn_95_2F7C(storage + 0x17E8, destroy);
        fn_95_3B80(storage + 0x1650, destroy);
        fn_95_3C0C(storage + 0x15F0, destroy);
        fn_95_3D08(storage + 0x153C, destroy);
        fn_95_3E44(storage + 0x137C, destroy);
        fn_95_4154(storage + 0x12D8, destroy);
        fn_95_4288(storage + 0x12A4, destroy);
        fn_95_42E4(storage + 0x128C, destroy);
        fn_95_4340(storage + 0x1128, destroy);
        fn_95_43AC(storage + 0x10C0, destroy);
        fn_95_440C(storage + 0x10B4, destroy);
        fn_95_446C(storage + 0x108C, destroy);
        fn_95_44C8(storage + 0x0EBC, destroy);
        fn_95_454C(storage + 0x0E58, destroy);
        fn_95_4618(storage + 0x0E1C, destroy);
        fn_95_46E0(storage + 0x0D64, destroy);
        fn_95_19648(storage + 0x0B1C, destroy);
        fn_95_4854(storage + 0x093C, destroy);
        fn_95_48C0(storage + 0x090C, destroy);
        fn_95_4978(storage + 0x08FC, destroy);
        fn_95_49B8(storage + 0x08E4, destroy);
        __dt__16soModuleAccesserFv(storage + 0x0804, destroy);
        fn_95_196CC(object, destroy);

        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}

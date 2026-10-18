#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_95_3AC8(void*, short);
void* fn_95_3B24(void*, short);
void* fn_95_3B80(void*, short);
void* fn_95_3C0C(void*, short);
void* fn_95_3D08(void*, short);
void* fn_95_1D4D8(void*, short);
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
void* fn_95_4674(void*, short);
void* fn_95_46E0(void*, short);
void* fn_95_5140(void*, short);
void* fn_95_4854(void*, short);
void* fn_95_48C0(void*, short);
void* fn_95_4978(void*, short);
void* fn_95_49B8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_95_4A14(void*, short);

void* fn_95_1D358(void* object, short deleting)
{
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_3AC8(storage + 0x1868, -1);
        fn_95_3B24(storage + 0x1850, -1);
        fn_95_3B80(storage + 0x16B4, -1);
        fn_95_3C0C(storage + 0x1654, -1);
        fn_95_3D08(storage + 0x15A0, -1);
        fn_95_1D4D8(storage + 0x13D8, -1);
        fn_95_4154(storage + 0x1334, -1);
        fn_95_4288(storage + 0x1300, -1);
        fn_95_42E4(storage + 0x12E8, -1);
        fn_95_4340(storage + 0x1184, -1);
        fn_95_43AC(storage + 0x111C, -1);
        fn_95_440C(storage + 0x1110, -1);
        fn_95_446C(storage + 0x10E8, -1);
        fn_95_44C8(storage + 0x0F18, -1);
        fn_95_454C(storage + 0x0EB4, -1);
        fn_95_4618(storage + 0x0E78, -1);
        fn_95_4674(storage + 0x0DD0, -1);
        fn_95_46E0(storage + 0x0D1C, -1);
        fn_95_5140(storage + 0x0B10, -1);
        fn_95_4854(storage + 0x0930, -1);
        fn_95_48C0(storage + 0x0900, -1);
        fn_95_4978(storage + 0x08F0, -1);
        fn_95_49B8(storage + 0x08D8, -1);
        __dt__16soModuleAccesserFv(storage + 0x07F8, -1);
        fn_95_4A14(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}

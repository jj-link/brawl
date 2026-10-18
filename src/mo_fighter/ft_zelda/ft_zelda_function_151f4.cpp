#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_104_3AF0(void*, short);
void* fn_104_3B4C(void*, short);
void* fn_104_3BA8(void*, short);
void* fn_104_3C04(void*, short);
void* fn_104_3D50(void*, short);
void* fn_104_3E4C(void*, short);
void* fn_104_15374(void*, short);
void* fn_104_4194(void*, short);
void* fn_104_42C8(void*, short);
void* fn_104_4324(void*, short);
void* fn_104_4380(void*, short);
void* fn_104_43EC(void*, short);
void* fn_104_444C(void*, short);
void* fn_104_44AC(void*, short);
void* fn_104_4508(void*, short);
void* fn_104_458C(void*, short);
void* fn_104_4658(void*, short);
void* fn_104_4720(void*, short);
void* fn_104_51C0(void*, short);
void* fn_104_4894(void*, short);
void* fn_104_4900(void*, short);
void* fn_104_49B8(void*, short);
void* fn_104_49F8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_104_4A54(void*, short);

void* fn_104_151F4(void* object, short deleting)
{
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_3AF0(storage + 0x1800, -1);
        fn_104_3B4C(storage + 0x17C0, -1);
        fn_104_3BA8(storage + 0x17A8, -1);
        fn_104_3C04(storage + 0x160C, -1);
        fn_104_3D50(storage + 0x15AC, -1);
        fn_104_3E4C(storage + 0x14F8, -1);
        fn_104_15374(storage + 0x1334, -1);
        fn_104_4194(storage + 0x1290, -1);
        fn_104_42C8(storage + 0x125C, -1);
        fn_104_4324(storage + 0x1244, -1);
        fn_104_4380(storage + 0x10E0, -1);
        fn_104_43EC(storage + 0x1078, -1);
        fn_104_444C(storage + 0x106C, -1);
        fn_104_44AC(storage + 0x1044, -1);
        fn_104_4508(storage + 0x0E74, -1);
        fn_104_458C(storage + 0x0E10, -1);
        fn_104_4658(storage + 0x0DD4, -1);
        fn_104_4720(storage + 0x0D1C, -1);
        fn_104_51C0(storage + 0x0B10, -1);
        fn_104_4894(storage + 0x0930, -1);
        fn_104_4900(storage + 0x0900, -1);
        fn_104_49B8(storage + 0x08F0, -1);
        fn_104_49F8(storage + 0x08D8, -1);
        __dt__16soModuleAccesserFv(storage + 0x07F8, -1);
        fn_104_4A54(object, -1);

        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}

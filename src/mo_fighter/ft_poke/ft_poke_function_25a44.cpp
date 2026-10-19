#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_116_394C(void*, short);
void* fn_116_3A04(void*, short);
void* fn_116_25BB8(void*, short);
void* fn_116_25C14(void*, short);
void* fn_116_25C74(void*, short);
void* fn_116_25D00(void*, short);
void* fn_116_25D60(void*, short);
void* fn_116_3D88(void*, short);
void* fn_116_3EBC(void*, short);
void* fn_116_FEE8(void*, short);
void* fn_116_3F18(void*, short);
void* fn_116_3F84(void*, short);
void* fn_116_3FE4(void*, short);
void* fn_116_4040(void*, short);
void* fn_116_40C4(void*, short);
void* fn_116_4190(void*, short);
void* fn_116_4258(void*, short);
void* fn_116_25FEC(void*, short);
void* fn_116_261A4(void*, short);
void* fn_116_4C70(void*, short);
void* fn_116_42CC(void*, short);
void* fn_116_430C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_116_26210(void*, short);

void* fn_116_25A44(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_394C(storage + 0x18AC, -1);
        fn_116_3A04(storage + 0x1890, -1);
        fn_116_25BB8(storage + 0x1738, -1);
        fn_116_25C14(storage + 0x16E8, -1);
        fn_116_25C74(storage + 0x1554, -1);
        fn_116_25D00(storage + 0x14F4, -1);
        fn_116_25D60(storage + 0x130C, -1);
        fn_116_3D88(storage + 0x1268, -1);
        fn_116_3EBC(storage + 0x1234, -1);
        fn_116_FEE8(storage + 0x121C, -1);
        fn_116_3F18(storage + 0x10B8, -1);
        fn_116_3F84(storage + 0x10A8, -1);
        fn_116_3FE4(storage + 0x1080, -1);
        fn_116_4040(storage + 0x0EB0, -1);
        fn_116_40C4(storage + 0x0E4C, -1);
        fn_116_4190(storage + 0x0E10, -1);
        fn_116_4258(storage + 0x0D58, -1);
        fn_116_25FEC(storage + 0x0B10, -1);
        fn_116_261A4(storage + 0x0930, -1);
        fn_116_4C70(storage + 0x0900, -1);
        fn_116_42CC(storage + 0x08F0, -1);
        fn_116_430C(storage + 0x08D8, -1);
        __dt__16soModuleAccesserFv(storage + 0x07F8, -1);
        fn_116_26210(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}

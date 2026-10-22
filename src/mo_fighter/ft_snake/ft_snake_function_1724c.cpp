#pragma force_active on
extern "C" void* fn_122_3BC4(void*, short);
extern "C" void* fn_122_3C20(void*, short);
extern "C" void* fn_122_3C7C(void*, short);
extern "C" void* fn_122_3CD8(void*, short);
extern "C" void* fn_122_3D5C(void*, short);
extern "C" void* fn_122_3DE8(void*, short);
extern "C" void* fn_122_6A84(void*, short);
extern "C" void* fn_122_17408(void*, short);
extern "C" void* fn_122_430C(void*, short);
extern "C" void* fn_122_4440(void*, short);
extern "C" void* fn_122_449C(void*, short);
extern "C" void* fn_122_17500(void*, short);
extern "C" void* fn_122_593C(void*, short);
extern "C" void* fn_122_4558(void*, short);
extern "C" void* fn_122_45C4(void*, short);
extern "C" void* fn_122_4624(void*, short);
extern "C" void* fn_122_4684(void*, short);
extern "C" void* fn_122_4754(void*, short);
extern "C" void* fn_122_5998(void*, short);
extern "C" void* fn_122_4850(void*, short);
extern "C" void* fn_122_491C(void*, short);
extern "C" void* fn_122_4978(void*, short);
extern "C" void* fn_122_6B74(void*, short);
extern "C" void* fn_122_17638(void*, short);
extern "C" void* fn_122_4B58(void*, short);
extern "C" void* fn_122_4BC4(void*, short);
extern "C" void* fn_122_4C7C(void*, short);
extern "C" void* fn_122_4CBC(void*, short);
extern "C" void __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_122_4D18(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_1724C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_3BC4(storage + 0x1CC8, -1);
        fn_122_3C20(storage + 0x1C88, -1);
        fn_122_3C7C(storage + 0x1C70, -1);
        fn_122_3CD8(storage + 0x1B5C, -1);
        fn_122_3D5C(storage + 0x19C8, -1);
        fn_122_3DE8(storage + 0x1968, -1);
        fn_122_6A84(storage + 0x18E4, -1);
        fn_122_17408(storage + 0x1708, -1);
        fn_122_430C(storage + 0x1664, -1);
        fn_122_4440(storage + 0x1630, -1);
        fn_122_449C(storage + 0x1614, -1);
        fn_122_17500(storage + 0x1540, -1);
        fn_122_593C(storage + 0x1510, -1);
        fn_122_4558(storage + 0x13AC, -1);
        fn_122_45C4(storage + 0x1344, -1);
        fn_122_4624(storage + 0x1338, -1);
        fn_122_4684(storage + 0x1310, -1);
        fn_122_4754(storage + 0x1114, -1);
        fn_122_5998(storage + 0xF48, -1);
        fn_122_4850(storage + 0xEE4, -1);
        fn_122_491C(storage + 0xEA8, -1);
        fn_122_4978(storage + 0xE00, -1);
        fn_122_6B74(storage + 0xD1C, -1);
        fn_122_17638(storage + 0xB10, -1);
        fn_122_4B58(storage + 0x930, -1);
        fn_122_4BC4(storage + 0x900, -1);
        fn_122_4C7C(storage + 0x8F0, -1);
        fn_122_4CBC(storage + 0x8D8, -1);
        __dt__16soModuleAccesserFv(storage + 0x7F8, -1);
        fn_122_4D18(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

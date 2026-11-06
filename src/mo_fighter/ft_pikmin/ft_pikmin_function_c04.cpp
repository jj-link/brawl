#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_113_CDC(void*, short);
extern "C" void* fn_113_EFC(void*, short);
extern "C" void* fn_113_FC4(void*, short);
extern "C" void* fn_113_1050(void*, short);
extern "C" void* fn_113_10DC(void*, short);
extern "C" void* fn_113_1168(void*, short);
extern "C" void* fn_113_11F4(void*, short);
extern "C" void* fn_113_1280(void*, short);
extern "C" void* fn_113_130C(void*, short);
extern "C" void* fn_113_1398(void*, short);
extern "C" void* fn_113_1424(void*, short);

extern "C" void* fn_113_C04(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_CDC(storage + 0x1498, -1);
        fn_113_EFC(storage + 0x1374, -1);
        fn_113_FC4(storage + 0x1248, -1);
        fn_113_1050(storage + 0x111C, -1);
        fn_113_10DC(storage + 0xFF0, -1);
        fn_113_1168(storage + 0xEC4, -1);
        fn_113_11F4(storage + 0xD98, -1);
        fn_113_1280(storage + 0xC6C, -1);
        fn_113_130C(storage + 0xB40, -1);
        fn_113_1398(storage + 0xA14, -1);
        fn_113_1424(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

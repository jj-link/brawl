#pragma force_active on
extern "C" void* fn_109_20C8(void*, short);
extern "C" void* fn_109_228C(void*, short);
extern "C" void* fn_109_2354(void*, short);
extern "C" void* fn_109_23E0(void*, short);
extern "C" void* fn_109_246C(void*, short);
extern "C" void* fn_109_24F8(void*, short);
extern "C" void* fn_109_2584(void*, short);
extern "C" void* fn_109_2610(void*, short);
extern "C" void* fn_109_269C(void*, short);
extern "C" void* fn_109_2728(void*, short);
extern "C" void* fn_109_27B4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_1FF0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_20C8(storage + 0x14C8, -1);
        fn_109_228C(storage + 0x13A4, -1);
        fn_109_2354(storage + 0x1278, -1);
        fn_109_23E0(storage + 0x114C, -1);
        fn_109_246C(storage + 0x1020, -1);
        fn_109_24F8(storage + 0xEF4, -1);
        fn_109_2584(storage + 0xDC8, -1);
        fn_109_2610(storage + 0xC9C, -1);
        fn_109_269C(storage + 0xB70, -1);
        fn_109_2728(storage + 0xA44, -1);
        fn_109_27B4(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
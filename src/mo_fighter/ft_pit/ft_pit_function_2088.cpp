#pragma force_active on
extern "C" void* fn_112_2160(void*, short);
extern "C" void* fn_112_2324(void*, short);
extern "C" void* fn_112_23EC(void*, short);
extern "C" void* fn_112_2478(void*, short);
extern "C" void* fn_112_2504(void*, short);
extern "C" void* fn_112_2590(void*, short);
extern "C" void* fn_112_261C(void*, short);
extern "C" void* fn_112_26A8(void*, short);
extern "C" void* fn_112_2734(void*, short);
extern "C" void* fn_112_27C0(void*, short);
extern "C" void* fn_112_284C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_2088(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_2160(storage + 0x14c0, -1);
        fn_112_2324(storage + 0x139c, -1);
        fn_112_23EC(storage + 0x1270, -1);
        fn_112_2478(storage + 0x1144, -1);
        fn_112_2504(storage + 0x1018, -1);
        fn_112_2590(storage + 0xeec, -1);
        fn_112_261C(storage + 0xdc0, -1);
        fn_112_26A8(storage + 0xc94, -1);
        fn_112_2734(storage + 0xb68, -1);
        fn_112_27C0(storage + 0xa3c, -1);
        fn_112_284C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

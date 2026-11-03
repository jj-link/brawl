#pragma force_active on
extern "C" void* fn_94_20CC(void*, short);
extern "C" void* fn_94_2290(void*, short);
extern "C" void* fn_94_2358(void*, short);
extern "C" void* fn_94_23E4(void*, short);
extern "C" void* fn_94_2470(void*, short);
extern "C" void* fn_94_24FC(void*, short);
extern "C" void* fn_94_2588(void*, short);
extern "C" void* fn_94_2614(void*, short);
extern "C" void* fn_94_26A0(void*, short);
extern "C" void* fn_94_272C(void*, short);
extern "C" void* fn_94_27B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_1FF4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_94_20CC(storage + 0x1520, -1);
        fn_94_2290(storage + 0x13FC, -1);
        fn_94_2358(storage + 0x12D0, -1);
        fn_94_23E4(storage + 0x11A4, -1);
        fn_94_2470(storage + 0x1078, -1);
        fn_94_24FC(storage + 0xF4C, -1);
        fn_94_2588(storage + 0xE20, -1);
        fn_94_2614(storage + 0xCF4, -1);
        fn_94_26A0(storage + 0xBC8, -1);
        fn_94_272C(storage + 0xA9C, -1);
        fn_94_27B8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
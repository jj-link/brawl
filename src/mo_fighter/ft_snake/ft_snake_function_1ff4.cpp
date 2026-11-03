#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_122_20CC(void*, short);
extern "C" void* fn_122_2290(void*, short);
extern "C" void* fn_122_2358(void*, short);
extern "C" void* fn_122_23E4(void*, short);
extern "C" void* fn_122_2470(void*, short);
extern "C" void* fn_122_24FC(void*, short);
extern "C" void* fn_122_2588(void*, short);
extern "C" void* fn_122_2614(void*, short);
extern "C" void* fn_122_26A0(void*, short);
extern "C" void* fn_122_272C(void*, short);
extern "C" void* fn_122_27B8(void*, short);

extern "C" void* fn_122_1FF4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_20CC(storage + 0x1560, -1);
        fn_122_2290(storage + 0x143C, -1);
        fn_122_2358(storage + 0x1310, -1);
        fn_122_23E4(storage + 0x11E4, -1);
        fn_122_2470(storage + 0x10B8, -1);
        fn_122_24FC(storage + 0xF8C, -1);
        fn_122_2588(storage + 0xE60, -1);
        fn_122_2614(storage + 0xD34, -1);
        fn_122_26A0(storage + 0xC08, -1);
        fn_122_272C(storage + 0xADC, -1);
        fn_122_27B8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

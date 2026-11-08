#pragma force_active on
extern "C" void* fn_119_2140(void*, short);
extern "C" void* fn_119_2304(void*, short);
extern "C" void* fn_119_23CC(void*, short);
extern "C" void* fn_119_2458(void*, short);
extern "C" void* fn_119_24E4(void*, short);
extern "C" void* fn_119_2570(void*, short);
extern "C" void* fn_119_25FC(void*, short);
extern "C" void* fn_119_2688(void*, short);
extern "C" void* fn_119_2714(void*, short);
extern "C" void* fn_119_27A0(void*, short);
extern "C" void* fn_119_282C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_2068(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_119_2140(storage + 0x14F0, static_cast<short>(-1));
        fn_119_2304(storage + 0x13CC, static_cast<short>(-1));
        fn_119_23CC(storage + 0x12A0, static_cast<short>(-1));
        fn_119_2458(storage + 0x1174, static_cast<short>(-1));
        fn_119_24E4(storage + 0x1048, static_cast<short>(-1));
        fn_119_2570(storage + 0xF1C, static_cast<short>(-1));
        fn_119_25FC(storage + 0xDF0, static_cast<short>(-1));
        fn_119_2688(storage + 0xCC4, static_cast<short>(-1));
        fn_119_2714(storage + 0xB98, static_cast<short>(-1));
        fn_119_27A0(storage + 0xA6C, static_cast<short>(-1));
        fn_119_282C(object, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

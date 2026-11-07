#pragma force_active on
extern "C" void* fn_97_2184(void*, short);
extern "C" void* fn_97_2348(void*, short);
extern "C" void* fn_97_2410(void*, short);
extern "C" void* fn_97_249C(void*, short);
extern "C" void* fn_97_2528(void*, short);
extern "C" void* fn_97_25B4(void*, short);
extern "C" void* fn_97_2640(void*, short);
extern "C" void* fn_97_26CC(void*, short);
extern "C" void* fn_97_2758(void*, short);
extern "C" void* fn_97_27E4(void*, short);
extern "C" void* fn_97_2870(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_20AC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_2184(storage + 0x14B8, -1);
        fn_97_2348(storage + 0x1394, -1);
        fn_97_2410(storage + 0x1268, -1);
        fn_97_249C(storage + 0x113C, -1);
        fn_97_2528(storage + 0x1010, -1);
        fn_97_25B4(storage + 0xEE4, -1);
        fn_97_2640(storage + 0xDB8, -1);
        fn_97_26CC(storage + 0xC8C, -1);
        fn_97_2758(storage + 0xB60, -1);
        fn_97_27E4(storage + 0xA34, -1);
        fn_97_2870(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
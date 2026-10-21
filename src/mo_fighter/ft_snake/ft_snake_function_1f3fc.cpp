#pragma force_active on
extern "C" void* fn_122_39B4(void*, short);
extern "C" void* fn_122_3A20(void*, short);
extern "C" void* fn_122_3AAC(void*, short);
extern "C" void* fn_122_3B38(void*, short);
extern "C" void* fn_122_1F48C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_1F3FC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_39B4(storage + 0x4B0, -1);
        fn_122_3A20(storage + 0x384, -1);
        fn_122_3AAC(storage + 0x258, -1);
        fn_122_3B38(storage + 0x12C, -1);
        fn_122_1F48C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

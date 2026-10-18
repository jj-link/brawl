#pragma force_active on
extern "C" void* fn_110_3F20(void*, short);
extern "C" void* fn_110_3FA4(void*, short);
extern "C" void* fn_110_1C4B8(void*, short);
extern "C" void* fn_110_4004(void*, short);
extern "C" void* fn_110_1C514(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_110_1C41C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_110_3F20(storage + 0x110, -1);
        fn_110_3FA4(storage + 0xFC, -1);
        fn_110_1C4B8(storage + 0xEC, -1);
        fn_110_4004(storage + 0x48, -1);
        fn_110_1C514(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

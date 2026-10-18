#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* fn_113_2C28(void*, short);
extern "C" void* fn_113_2CAC(void*, short);
extern "C" void* fn_113_14EB8(void*, short);
extern "C" void* fn_113_14F14(void*, short);
extern "C" void* fn_113_15048(void*, short);

extern "C" void* fn_113_14E1C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_2C28(static_cast<unsigned char*>(object) + 0x288, -1);
        fn_113_2CAC(storage + 0x274, -1);
        fn_113_14EB8(storage + 0x198, -1);
        fn_113_14F14(storage + 0x54, -1);
        fn_113_15048(storage + 0x10, -1);
        fn_27_C74E8(storage, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

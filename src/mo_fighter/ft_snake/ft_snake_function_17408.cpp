#pragma force_active on
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* fn_122_40A0(void*, short);
extern "C" void* fn_122_4124(void*, short);
extern "C" void* fn_122_174A4(void*, short);
extern "C" void* fn_122_4184(void*, short);
extern "C" void* fn_122_42AC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_17408(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_40A0(storage + 0x12C, -1);
        fn_122_4124(storage + 0x118, -1);
        fn_122_174A4(storage + 0xEC, -1);
        fn_122_4184(storage + 0x48, -1);
        fn_122_42AC(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

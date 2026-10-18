#pragma force_active on
extern "C" void* fn_122_40A0(void*, short);
extern "C" void* fn_122_4124(void*, short);
extern "C" void* fn_122_1CEAC(void*, short);
extern "C" void* fn_122_4184(void*, short);
extern "C" void* fn_122_42AC(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* __dl__FPv(void*);

extern "C" void* fn_122_1CE10(void* object, short deleting) {
    if (object != 0) {
        fn_122_40A0(static_cast<unsigned char*>(object) + 0x11C, -1);
        fn_122_4124(static_cast<unsigned char*>(object) + 0x108, -1);
        fn_122_1CEAC(static_cast<unsigned char*>(object) + 0xEC, -1);
        fn_122_4184(static_cast<unsigned char*>(object) + 0x48, -1);
        fn_122_42AC(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

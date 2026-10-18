#pragma force_active on
extern "C" void* fn_122_40A0(void*, short);
extern "C" void* fn_122_4124(void*, short);
extern "C" void* fn_122_58E0(void*, short);
extern "C" void* fn_122_4184(void*, short);
extern "C" void* fn_122_42AC(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_5844(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_122_40A0(p + 0x118, -1);
        fn_122_4124(p + 0x104, -1);
        fn_122_58E0(p + 0xec, -1);
        fn_122_4184(p + 0x48, -1);
        fn_122_42AC(p + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

#pragma force_active on
extern "C" void* fn_108_3C2C(void*, short);
extern "C" void* fn_108_3CB0(void*, short);
extern "C" void* fn_108_651C(void*, short);
extern "C" void* fn_108_6578(void*, short);
extern "C" void* fn_108_6F90(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_6480(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_108_3C2C(p + 0xdc4, -1);
        fn_108_3CB0(p + 0xdb0, -1);
        fn_108_651C(p + 0x930, -1);
        fn_108_6578(p + 0xbc, -1);
        fn_108_6F90(p + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

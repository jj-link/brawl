#pragma force_active on
extern "C" void* fn_120_3CA0(void*, short);
extern "C" void* fn_120_3D24(void*, short);
extern "C" void* fn_120_17940(void*, short);
extern "C" void* fn_120_12B3C(void*, short);
extern "C" void* fn_120_178E0(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_1799C(void* object, short deleting) {
    if (object != 0) {
        short del = -1;
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_120_3CA0(p + 0x11C, del);
        fn_120_3D24(p + 0x108, del);
        fn_120_17940(p + 0xEC, del);
        fn_120_12B3C(p + 0x48, del);
        fn_120_178E0(p + 0x10, del);
        fn_27_C74E8(object, del);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

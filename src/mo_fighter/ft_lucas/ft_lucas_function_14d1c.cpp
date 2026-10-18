#pragma force_active on
extern "C" void* fn_114_3FE4(void*, short);
extern "C" void* fn_114_4068(void*, short);
extern "C" void* fn_114_14DB8(void*, short);
extern "C" void* fn_114_40C8(void*, short);
extern "C" void* fn_114_5120(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_14D1C(void* object, short deleting) {
    if (object) {
        fn_114_3FE4((char*)object + 0x114, -1);
        fn_114_4068((char*)object + 0x100, -1);
        fn_114_14DB8((char*)object + 0xec, -1);
        fn_114_40C8((char*)object + 0x48, -1);
        fn_114_5120((char*)object + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

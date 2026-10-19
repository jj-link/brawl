#pragma force_active on
extern "C" void* fn_92_3AA4(void*, short);
extern "C" void* fn_92_3B00(void*, short);
extern "C" void* fn_92_3B5C(void*, short);
extern "C" void* fn_92_3BE8(void*, short);
extern "C" void* fn_92_3CE4(void*, short);
extern "C" void* fn_92_14B00(void*, short);
extern "C" void* fn_92_408C(void*, short);
extern "C" void* fn_92_41C0(void*, short);
extern "C" void* fn_92_421C(void*, short);
extern "C" void* fn_92_4278(void*, short);
extern "C" void* fn_92_42E4(void*, short);
extern "C" void* fn_92_4344(void*, short);
extern "C" void* fn_92_43A4(void*, short);
extern "C" void* fn_92_14BF8(void*, short);
extern "C" void* fn_92_4400(void*, short);
extern "C" void* fn_92_44CC(void*, short);
extern "C" void* fn_92_4528(void*, short);
extern "C" void* fn_92_14C7C(void*, short);
extern "C" void* fn_92_4624(void*, short);
extern "C" void* fn_92_4690(void*, short);
extern "C" void* fn_92_4748(void*, short);
extern "C" void* fn_92_4788(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_92_14CF4(void*, short);
extern "C" void* __dl__FPv(void*);

extern "C" void* fn_92_1498C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = (unsigned char*)object;
        fn_92_3AA4(p + 0x1850, -1);
        fn_92_3B00(p + 0x1838, -1);
        fn_92_3B5C(p + 0x169C, -1);
        fn_92_3BE8(p + 0x163C, -1);
        fn_92_3CE4(p + 0x1588, -1);
        fn_92_14B00(p + 0x13C4, -1);
        fn_92_408C(p + 0x1320, -1);
        fn_92_41C0(p + 0x12EC, -1);
        fn_92_421C(p + 0x12D4, -1);
        fn_92_4278(p + 0x1170, -1);
        fn_92_42E4(p + 0x1108, -1);
        fn_92_4344(p + 0x10FC, -1);
        fn_92_43A4(p + 0x10D4, -1);
        fn_92_14BF8(p + 0xE74, -1);
        fn_92_4400(p + 0xE10, -1);
        fn_92_44CC(p + 0xDD4, -1);
        fn_92_4528(p + 0xD1C, -1);
        fn_92_14C7C(p + 0xB10, -1);
        fn_92_4624(p + 0x930, -1);
        fn_92_4690(p + 0x900, -1);
        fn_92_4748(p + 0x8F0, -1);
        fn_92_4788(p + 0x8D8, -1);
        __dt__16soModuleAccesserFv(p + 0x7F8, -1);
        fn_92_14CF4(object, -1);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}

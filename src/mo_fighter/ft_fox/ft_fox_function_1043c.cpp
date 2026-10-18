#pragma force_active on
extern "C" void* fn_97_3D5C(void*, short);
extern "C" void* fn_97_3DE0(void*, short);
extern "C" void* fn_97_104D8(void*, short);
extern "C" void* fn_97_3E40(void*, short);
extern "C" void* fn_97_3F68(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_1043C(void* object, short deleting) {
    if (object != 0) {
        fn_97_3D5C(static_cast<unsigned char*>(object) + 0x118, -1);
        fn_97_3DE0(static_cast<unsigned char*>(object) + 0x104, -1);
        fn_97_104D8(static_cast<unsigned char*>(object) + 0xEC, -1);
        fn_97_3E40(static_cast<unsigned char*>(object) + 0x48, -1);
        fn_97_3F68(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

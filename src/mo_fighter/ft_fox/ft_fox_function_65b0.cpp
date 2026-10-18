#pragma force_active on
extern "C" void* fn_97_3D5C(void* object, short deleting);
extern "C" void* fn_97_3DE0(void* object, short deleting);
extern "C" void* fn_97_664C(void* object, short deleting);
extern "C" void* fn_97_66A8(void* object, short deleting);
extern "C" void* fn_97_70C0(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_65B0(void* object, short deleting) {
    if (object != 0) {
        fn_97_3D5C(static_cast<unsigned char*>(object) + 0xDD0, -1);
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_3DE0(storage + 0xDBC, -1);
        fn_97_664C(storage + 0x930, -1);
        fn_97_66A8(storage + 0xBC, -1);
        fn_97_70C0(storage + 0x10, -1);
        fn_27_C74E8(storage, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

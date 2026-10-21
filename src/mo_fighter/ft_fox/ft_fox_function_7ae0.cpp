#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_97_7B94(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_97_7C00(void*, short);
extern "C" void* fn_97_7C5C(void*, short);
extern "C" void* fn_97_44D8(void*, short);
extern "C" void* fn_97_7CB8(void*, short);
extern "C" void* fn_97_63A4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_7AE0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, -1);
        fn_97_7B94(storage + 0x1E8, -1);
        fn_27_21038(storage + 0x1D8, -1);
        fn_97_7C00(storage + 0x1B8, -1);
        fn_97_7C5C(storage + 0x198, -1);
        fn_97_44D8(storage + 0x160, -1);
        fn_97_7CB8(storage + 0xC4, -1);
        fn_97_63A4(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

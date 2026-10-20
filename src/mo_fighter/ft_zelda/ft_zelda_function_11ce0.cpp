#pragma force_active on
extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_104_11D64(void*, short);
extern "C" void fn_27_19EFFC(void*, short);
extern "C" void* fn_27_1A51A0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_11CE0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_93100(storage + 0x4C, -1);
        fn_104_11D64(storage + 0x40, -1);
        fn_27_19EFFC(storage + 0x14, -1);
        fn_27_1A51A0(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

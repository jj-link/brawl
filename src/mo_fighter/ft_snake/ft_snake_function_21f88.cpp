#pragma force_active on
extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_122_2200C(void*, short);
extern "C" void* fn_27_19EFFC(void*, short);
extern "C" void* fn_27_1A51A0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_21F88(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_93100(storage + 0x4B24, -1);
        fn_122_2200C(storage + 0x40, -1);
        fn_27_19EFFC(storage + 0x14, -1);
        fn_27_1A51A0(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

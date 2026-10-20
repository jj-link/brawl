#pragma force_active on
extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_110_3304(void*, short);
extern "C" void* fn_27_19F4C4(void*, short);
extern "C" void* fn_27_1A55B0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_3280(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_93100(storage + 0x4B8C, -1);
        fn_110_3304(storage + 0x7C, -1);
        fn_27_19F4C4(storage + 0x20, -1);
        fn_27_1A55B0(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

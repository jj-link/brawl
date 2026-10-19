#pragma force_active on
extern "C" void* fn_121_CFFC(void*, short);
extern "C" void* fn_121_CEDC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_D05C(void* object, short deleting) {
    if (object != 0) {
        fn_121_CFFC(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_121_CEDC(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

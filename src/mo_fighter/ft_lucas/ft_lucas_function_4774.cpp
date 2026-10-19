#pragma force_active on
extern "C" void* fn_27_25740(void*, short);
extern "C" void* fn_27_CC0F0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_4774(void* object, short flag) {
    if (object != 0) {
        fn_27_25740(static_cast<unsigned char*>(object) + 0x50, -1);
        fn_27_CC0F0(object, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

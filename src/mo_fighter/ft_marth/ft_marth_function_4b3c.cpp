#pragma force_active on
extern "C" void* fn_27_25740(void*, short);
extern "C" void* fn_27_CC0F0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_4B3C(void* obj, short del) {
    if (obj) {
        fn_27_25740(static_cast<unsigned char*>(obj) + 0x50, static_cast<short>(-1));
        fn_27_CC0F0(obj, static_cast<short>(-1));
        if (del > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}

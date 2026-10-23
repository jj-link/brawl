#pragma force_active on
extern "C" void* fn_106_2320(void*, short);
extern "C" void* fn_106_217C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_22B4(void* obj, short del) {
    if (obj) {
        fn_106_2320(static_cast<unsigned char*>(obj) + 0x50, static_cast<short>(-1));
        fn_106_217C(obj, static_cast<short>(-1));
        if (del > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}

#pragma force_active on
extern "C" void* fn_106_40F4(void*, short);
extern "C" void* fn_106_4154(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_4088(void* obj, short del) {
    if (obj) {
        fn_106_40F4(static_cast<unsigned char*>(obj) + 0x24, static_cast<short>(-1));
        fn_106_4154(obj, static_cast<short>(-1));
        if (del > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}

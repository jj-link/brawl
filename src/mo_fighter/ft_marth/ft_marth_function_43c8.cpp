#pragma force_active on
extern "C" void* fn_27_6A3D8(void*, short);
extern "C" void* fn_27_199F7C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_43C8(void* obj, short del) {
    if (obj) {
        fn_27_6A3D8(static_cast<unsigned char*>(obj) + 0x178, static_cast<short>(-1));
        fn_27_199F7C(obj, static_cast<short>(-1));
        if (del > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}

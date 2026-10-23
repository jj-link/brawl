#pragma force_active on
extern "C" void* fn_27_4B53C(void*, short);
extern "C" void* fn_27_19C45C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_4738(void* obj, short del) {
    if (obj) {
        fn_27_4B53C(static_cast<unsigned char*>(obj) + 0x17C, static_cast<short>(-1));
        fn_27_19C45C(obj, static_cast<short>(-1));
        if (del > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}

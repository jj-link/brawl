#pragma force_active on
extern "C" void* fn_27_22A38(void*, short);
extern "C" void* fn_27_1A2910(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_4CD0(void* obj, short del) {
    if (obj) {
        fn_27_22A38(static_cast<unsigned char*>(obj) + 0x34, static_cast<short>(-1));
        fn_27_1A2910(obj, static_cast<short>(-1));
        if (del > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}

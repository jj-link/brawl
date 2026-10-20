#pragma force_active on
extern "C" void fn_114_21C8(void*, short);
extern "C" void fn_27_C74E8(void*, short);
extern "C" void fn_114_2A80(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_2144(void* obj, short param) {
    if (obj) {
        fn_114_21C8((char*)obj + 0x46F8C, -1);
        fn_27_C74E8((char*)obj + 0x46F7C, -1);
        fn_114_2A80(obj, 0);
        if (param > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}

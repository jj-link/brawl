#pragma force_active on
extern "C" void fn_27_48BE8(void*, short);
extern "C" void fn_27_4742C(void*, short);
extern "C" void fn_27_4CAA0(void*, short);
extern "C" void fn_27_CDDE8(void*, short);
extern "C" void fn_27_CD78C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_816C(void* object, short destroy) {
    if (object != 0) {
        fn_27_48BE8(static_cast<char*>(object) + 0x1C4, -1);
        fn_27_4742C(static_cast<char*>(object) + 0x1B4, -1);
        fn_27_4CAA0(static_cast<char*>(object) + 0x130, -1);
        fn_27_CDDE8(static_cast<char*>(object) + 0x6C, -1);
        fn_27_CD78C(object, -1);
        if (destroy > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

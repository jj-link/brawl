#pragma force_active on
extern "C" void fn_114_1B90(void*, short);
extern "C" void fn_114_1F70(void*, short);
extern "C" void* fn_114_200C(void*, short);
extern "C" void fn_114_2144(void*, short);
extern "C" void fn_27_125E20(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_1AF0(void* object, short flag) {
    if (object != 0) {
        fn_114_1B90((char*)object + 0x48C08, -1);
        fn_114_1F70((char*)object + 0x48750, -1);
        fn_114_200C((char*)object + 0x48714, -1);
        fn_114_2144((char*)object + 0x194, -1);
        fn_27_125E20(object, 0);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

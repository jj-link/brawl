#pragma force_active on
extern "C" void fn_27_75E0C(void*, short);
extern "C" void fn_27_64930(void*, short);
extern "C" void fn_100_1EB8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_3C80(void* object, short flag) {
    if (object != 0) {
        fn_27_75E0C(static_cast<char*>(object) + 0x4C, -1);
        if (static_cast<char*>(object) + 0x20 != 0) {
            fn_27_64930(static_cast<char*>(object) + 0x20, 0);
        }
        fn_100_1EB8(static_cast<char*>(object) + 0x14, 0);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

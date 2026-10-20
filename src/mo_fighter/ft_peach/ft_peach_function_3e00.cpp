#pragma force_active on
extern "C" void fn_27_75E0C(void*, short);
extern "C" void fn_27_64930(void*, short);
extern "C" void fn_103_1EE8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_103_3E00(void* object, short flag) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        fn_27_75E0C(storage + 0x4C, -1);
        if (storage + 0x20 != 0) {
            fn_27_64930(storage + 0x20, 0);
        }
        fn_103_1EE8(storage + 0x14, 0);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

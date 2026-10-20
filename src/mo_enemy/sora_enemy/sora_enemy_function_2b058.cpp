#pragma force_active on
extern "C" void fn_27_75E0C(void*, short);
extern "C" void fn_27_64930(void*, short);
extern "C" void fn_27_7700(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2B058(char* ptr, short flag) {
    if (ptr != 0) {
        fn_27_75E0C(ptr + 0x4C, -1);
        if (ptr + 0x20 != 0) {
            fn_27_64930(ptr + 0x20, 0);
        }
        if (ptr + 0x14 != 0) {
            fn_27_7700(ptr + 0x14, 0);
        }
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

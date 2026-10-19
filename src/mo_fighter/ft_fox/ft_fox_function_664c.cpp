#pragma force_active on
extern "C" void* fn_27_1A3940(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_664C(void* ptr, short count) {
    if (ptr != 0) {
        fn_27_1A3940(ptr, (short)0xFFFFFFFF);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

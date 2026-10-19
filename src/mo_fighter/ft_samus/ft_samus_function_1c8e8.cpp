#pragma force_active on
extern "C" void* fn_27_1A4D90(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_1C8E8(void* ptr, short count) {
    if (ptr != 0) {
        fn_27_1A4D90(ptr, -1);
        if (count > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}

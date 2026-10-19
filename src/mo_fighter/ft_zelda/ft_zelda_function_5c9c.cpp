#pragma force_active on
extern "C" void* fn_27_1A3530(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_5C9C(void* ptr, int shouldDelete) {
    if (ptr != 0) {
        fn_27_1A3530(ptr, -1);
        if ((short)shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

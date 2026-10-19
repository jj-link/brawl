#pragma force_active on
extern "C" void* fn_27_1A4160(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_50CC(void* ptr, int shouldDelete) {
    if (ptr != 0) {
        fn_27_1A4160(ptr, (short)-1);
        if ((short)shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

#pragma force_active on
extern "C" void fn_27_19BFCC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_5EB8(void* ptr, int count) {
    if (ptr != 0) {
        fn_27_19BFCC(ptr, static_cast<short>(-1));
        if (static_cast<short>(count) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

#pragma force_active on
extern "C" void fn_27_19BFCC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_4B80(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        fn_27_19BFCC(ptr, static_cast<short>(-1));
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

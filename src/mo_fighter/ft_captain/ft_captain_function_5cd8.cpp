#pragma force_active on
extern "C" void fn_27_19BFCC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_5CD8(void* ptr, short count) {
    if (ptr != 0) {
        fn_27_19BFCC((char*)ptr, -1);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

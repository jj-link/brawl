#pragma force_active on
extern "C" void fn_27_19BFCC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_71C0(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_19BFCC(ptr, static_cast<short>(-1));
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}

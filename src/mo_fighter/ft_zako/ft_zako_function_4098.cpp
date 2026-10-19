#pragma force_active on
extern "C" {
void fn_27_19BFCC(void*, short);
void __dl__FPv(void*);
void* fn_126_4098(void* ptr, short flag);
}

void* fn_126_4098(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_19BFCC(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

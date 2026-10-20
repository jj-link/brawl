#pragma force_active on
extern "C" {
void fn_27_270880(void*, int);
void __dl__FPv(void*);

void* fn_27_27BE90(void* ptr, int flag) {
    if (ptr) {
        fn_27_270880(ptr, 0);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
}

#pragma force_active on
extern "C" {
typedef int s32;

extern void fn_81_4F40(void*, int);
extern void __dl__FPv(void*);

void* fn_81_5254(void* ptr, int flags) {
    if (ptr != 0) {
        fn_81_4F40(ptr, 0);
        if (flags > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
}

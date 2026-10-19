#pragma force_active on
extern "C" {
void fn_66_2C60(void*, int);
void __dl__FPv(void*);

void* fn_66_12984(void* ptr, int shouldDelete) {
    if (ptr) {
        fn_66_2C60(ptr, 0);
        if (shouldDelete > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
}

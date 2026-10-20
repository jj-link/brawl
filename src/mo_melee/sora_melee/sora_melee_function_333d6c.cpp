#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);
void fn_27_3335CC(void*, int);
void fn_27_333DD4(void*, int);

void* fn_27_333D6C(void* ptr, int release) {
    if (ptr) {
        fn_27_3335CC((char*)ptr + 0x1F58, -1);
        fn_27_333DD4((char*)ptr + 4, -1);
        if (release > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
}

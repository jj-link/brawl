#pragma force_active on
extern "C" {
void fn_27_271FFC(void*, int);
void __dl__FPv(void*);

void* fn_27_271858(void* ptr, int flag) {
    if (ptr) {
        ((char*)ptr)[0x4C] = 0;
        fn_27_271FFC((char*)ptr + 0x20, -1);
        fn_27_271FFC((char*)ptr + 4, -1);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
}

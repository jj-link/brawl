#pragma force_active on
extern "C" {
void fn_27_7700(void*, short);
void __dl__FPv(void*);

void* fn_93_1A0C(void* ptr, short count) {
    if (ptr != 0) {
        fn_27_7700(ptr, 0);
        if (count > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
}

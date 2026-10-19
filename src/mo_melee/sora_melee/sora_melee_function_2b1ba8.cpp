#pragma force_active on
extern "C" {
void __dl__FPv(void*);

void* fn_27_2B1BA8(void* ptr, int count) {
    if (ptr && count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
}

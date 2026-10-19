#pragma force_active on
extern "C" {
void __dl__FPv(void*);

void* fn_27_1DC870(void* ptr, int flag) {
    if (ptr != 0 && flag > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
}

#pragma force_active on
extern "C" {
void __dl__FPv(void*);

void* fn_95_F31C(void* ptr, short release) {
    if (ptr != 0 && release > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
}

#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_107_1317C(void* ptr, short count) {
    if (ptr != 0 && count > 0)
        __dl__FPv(ptr);
    return ptr;
}
}

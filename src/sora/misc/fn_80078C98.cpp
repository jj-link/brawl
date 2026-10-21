#pragma force_active on
extern "C" {
    void __dl__FPv(void*);

    void* fn_80078C98(void* ptr, int destroy) {
        if (ptr != 0 && destroy > 0) {
            __dl__FPv(ptr);
        }
        return ptr;
    }
}

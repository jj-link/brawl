#pragma force_active on
// Free a heap block when the counter/flag argument is positive,
// returning the original pointer unchanged.
extern "C" void __dl__FPv(void*);

extern "C" void* fn_8018BCB0(void* ptr, int count) {
    if (ptr != 0 && count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}

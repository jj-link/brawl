#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_1268C(void* ptr, short doDelete) {
    if (ptr != 0 && doDelete > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}

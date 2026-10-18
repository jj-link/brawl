#pragma force_active on
extern "C" void fn_124_8414(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9A2C(void* ptr, int flag) {
    if (ptr != 0) {
        if (ptr != 0)
            fn_124_8414(ptr, 0);
        if ((short)flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}

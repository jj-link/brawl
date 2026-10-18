#pragma force_active on
extern "C" void fn_41_59310(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5921C(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        fn_41_59310((char*)ptr + 8, -1);
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

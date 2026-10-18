#pragma force_active on
extern "C" void fn_800C2BB4(void*, void*);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_6_8D0(void* ptr, int shouldFree) {
    if (ptr) {
        if (static_cast<char*>(ptr) + 8)
            fn_800C2BB4(static_cast<char*>(ptr) + 8, 0);

        if (shouldFree > 0)
            __dl__FPv(ptr);
    }

    return ptr;
}

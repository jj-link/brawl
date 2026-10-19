#pragma force_active on
extern "C" void __dl__FPv(void* p);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void* fn_63_9D80(void* p, int size);

extern "C" void* fn_63_9E28(void* p, int size) {
    if (p != 0) {
        __destroy_arr(static_cast<void*>(static_cast<char*>(p) + 0xc), reinterpret_cast<void (*)(void*, int)>(fn_63_9D80), 8, 6);
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

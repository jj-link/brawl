#pragma force_active on
extern "C" void* fn_125_4CD8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_D318(void* ptr, short count)
{
    if (ptr != 0) {
        fn_125_4CD8(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_4978(void* ptr, int count)
{
    if (ptr != 0 && static_cast<short>(count) > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}

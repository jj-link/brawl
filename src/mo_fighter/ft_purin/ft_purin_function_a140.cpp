#pragma force_active on
extern "C" void fn_124_A0E0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_A140(void* ptr, short flag)
{
    if (ptr != 0) {
        fn_124_A0E0((char*)ptr + 8, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

#pragma force_active on
extern "C" void fn_79_46C0(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), int, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_79_4768(void* object, int deallocate)
{
    if (object) {
        __destroy_arr((char*)object + 0xC, fn_79_46C0, 8, 6);
        if (deallocate > 0)
            __dl__FPv(object);
    }
    return object;
}

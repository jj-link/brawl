#pragma force_active on
extern "C" void fn_48_3E50(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_48_B05C(void* object, int flag)
{
    if (object != 0) {
        __destroy_arr((char*)object + 12, fn_48_3E50, 160, 25);
        if (flag > 0)
            __dl__FPv(object);
    }
    return object;
}

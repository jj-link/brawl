#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_37D3C(void*, int);

extern "C" void* fn_72_4470(void* object, int should_free)
{
    if (object != 0) {
        __destroy_arr((char*)object + 0x0C, (void (*)(void*, int))fn_27_37D3C, 0x78, 1);
        if (should_free > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

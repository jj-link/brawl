#pragma force_active on
extern "C" void* fn_51_6278(void*, int);
extern "C" void __destroy_arr(void*, void* (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_51_D5EC(void* object, int shouldDelete)
{
    if (object != 0) {
        __destroy_arr((void*)((char*)object + 0xC), fn_51_6278, 0xA0UL, 2UL);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

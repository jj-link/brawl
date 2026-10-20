#pragma force_active on
typedef int s32;
typedef void (*ArrayDestructor)(void*, int);

extern "C" void __destroy_arr(void*, ArrayDestructor, unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_AB510(void*, int);

extern "C" void* fn_27_1A1E70(void* object, s32 shouldDelete) {
    if (object) {
        __destroy_arr((char*)object + 0xC, fn_27_AB510, 0x10, 6);
        if (shouldDelete > 0)
            __dl__FPv(object);
    }
    return object;
}

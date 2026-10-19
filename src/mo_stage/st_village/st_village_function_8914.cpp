#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_70_8F44(void*, int);

extern "C" void* fn_70_8914(void* object, int flag) {
    if (object != 0) {
        __destroy_arr((char*)object + 0xC, (void (*)(void*, int))fn_70_8F44, 0xA0ul, 1ul);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

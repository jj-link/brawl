#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_40_1DF14(void*, int);

extern "C" void* fn_40_1DF54(void* object, int shouldDelete) {
    if (object) {
        __destroy_arr((char*)object + 0xC, (void (*)(void*, int))fn_40_1DF14, 8, 6);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

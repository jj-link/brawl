#pragma force_active on
extern "C" void* fn_27_25290(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_CEC78(void* object, int deleting) {
    if (object) {
        void (*dtor)(void*, int) = (void (*)(void*, int))fn_27_25290;
        __destroy_arr((void*)((char*)object + 0xc), dtor, 0x30UL, 0x16UL);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}

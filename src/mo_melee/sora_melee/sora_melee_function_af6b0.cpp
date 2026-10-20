#pragma force_active on
extern "C" void* fn_27_84158(void* ptr, int size);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_AF6B0(void* self, int doDelete) {
    if (self != 0) {
        __destroy_arr((char*)self + 0xC, (void (*)(void*, int))fn_27_84158, 0xC, 8);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

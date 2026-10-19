#pragma force_active on
extern "C" void* fn_51_5ADC(void* slot, int destroy);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_51_5B84(char* self, int destroy) {
    if (self) {
        __destroy_arr(self + 0xc, (void (*)(void*, int))fn_51_5ADC, 8, 6);
        if (destroy > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

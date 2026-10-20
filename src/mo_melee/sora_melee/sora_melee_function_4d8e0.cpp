#pragma force_active on
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dt__8clTargetFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_4D8E0(char* self, int flags) {
    if (self) {
        if (self + 0x1c) {
            __destroy_arr(self + 0x28, __dt__8clTargetFv, 8, 6);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

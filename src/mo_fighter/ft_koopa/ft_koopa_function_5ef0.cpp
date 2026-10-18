#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_5EF0(void* self, short flag) {
    if (self != 0 && flag > 0) {
        __dl__FPv(self);
    }
    return self;
}

#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_114_3E98(void* self, short flags) {
    if (self != 0 && flags > 0) {
        __dl__FPv(self);
    }
    return self;
}

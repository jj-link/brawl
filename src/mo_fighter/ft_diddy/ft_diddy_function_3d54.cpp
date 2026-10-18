#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_3D54(void* self, short flags) {
    if (self != 0 && flags > 0) {
        __dl__FPv(self);
    }
    return self;
}

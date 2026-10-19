#pragma force_active on
extern "C" {
void* __dt__22soControllerModuleImplFv(void*, short);
void __dl__FPv(void*);
void* fn_110_FC44(void* self, short flags);
}

void* fn_110_FC44(void* self, short flags) {
    if (self != 0) {
        __dt__22soControllerModuleImplFv(self, static_cast<short>(0));
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

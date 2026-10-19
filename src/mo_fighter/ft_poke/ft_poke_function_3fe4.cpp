#pragma force_active on
extern "C" void* __dt__16soStopModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_3FE4(void* self, short flags) {
    if (self != 0) {
        __dt__16soStopModuleImplFv(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

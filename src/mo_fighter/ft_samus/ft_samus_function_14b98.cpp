#pragma force_active on
extern "C" void* __dt__16soStopModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_94_14B98(void* self, short flag) {
    if (self != 0) {
        __dt__16soStopModuleImplFv(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

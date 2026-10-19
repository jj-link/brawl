#pragma force_active on
extern "C" void __dt__19soPostureModuleImplFv(void*, short);
extern "C" void* fn_27_19FFEC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_47E0(unsigned char* self, short flags) {
    if (self != 0) {
        __dt__19soPostureModuleImplFv(self + 0x3C, -1);
        if (self != 0) {
            fn_27_19FFEC(self, -1);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

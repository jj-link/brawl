#pragma force_active on
extern "C" void __dt__19soPostureModuleImplFv(void*, short);
extern "C" void fn_27_CF938(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2F2F4(void* self, short flag) {
    if (self != 0) {
        __dt__19soPostureModuleImplFv(static_cast<unsigned char*>(self) + 0x9C, -1);
        if (self != 0) {
            fn_27_CF938(self, -1);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

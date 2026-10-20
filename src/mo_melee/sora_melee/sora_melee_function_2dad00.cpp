#pragma force_active on
extern "C" void __dt__19soPostureModuleImplFv(void*, short);
extern "C" void fn_27_25290();
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_2DAD00(char* self, int param) {
    if (self) {
        __dt__19soPostureModuleImplFv(self + 0x3C, -1);
        if (self && self) {
            __destroy_arr(self + 0xC, (void (*)(void*, int))fn_27_25290, 0x30, 1);
        }
        if (param > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

#pragma force_active on
extern "C" void* __dt__22soControllerModuleImplFv(void* object, short deleting);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_27_313EF4(void* self, int flag) {
    if (self) {
        void* sub = (char*)self + 4;
        if (sub) {
            __dt__22soControllerModuleImplFv(sub, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

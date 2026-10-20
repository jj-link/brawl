#pragma force_active on
extern "C" void* fn_27_5CC1C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_614C4(void* self, int doDelete) {
    if (self) {
        fn_27_5CC1C(self, 0);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

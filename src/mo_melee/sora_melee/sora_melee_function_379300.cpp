#pragma force_active on
extern "C" void fn_27_ACC5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_379300(void* self, int flag) {
    if (self) {
        fn_27_ACC5C(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

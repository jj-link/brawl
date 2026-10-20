#pragma force_active on
extern "C" void fn_27_ACC5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_102_2E24(void* self, short flag) {
    if (self != 0) {
        fn_27_ACC5C(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

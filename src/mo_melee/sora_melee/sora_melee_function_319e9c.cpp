#pragma force_active on
extern "C" {
void* fn_27_25740(void*, short);
void __dl__FPv(void*);

void* fn_27_319E9C(void* self, short flag) {
    if (self) {
        fn_27_25740(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

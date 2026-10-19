#pragma force_active on
extern "C" {
void fn_46_4570(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_46_6E2C(void* self, int flag) {
    if (self != 0) {
        fn_46_4570(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

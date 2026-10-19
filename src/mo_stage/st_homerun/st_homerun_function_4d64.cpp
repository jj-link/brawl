#pragma force_active on
extern "C" {
void fn_88_43CC(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_88_4D64(void* self, int flag) {
    if (self != 0) {
        fn_88_43CC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

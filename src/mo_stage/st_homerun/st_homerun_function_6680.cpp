#pragma force_active on
extern "C" {
void fn_88_43CC(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_88_6680(void* self, int size) {
    if (self != 0) {
        fn_88_43CC(self, 0);
        if (size > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

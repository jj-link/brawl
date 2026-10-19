#pragma force_active on
extern "C" {
void fn_88_43CC(void* self, int arg);
void __dl__FPv(void*);
}

extern "C" void* fn_88_6D58(void* self, int flag) {
    if (self) {
        fn_88_43CC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

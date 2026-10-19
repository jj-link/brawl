#pragma force_active on
extern "C" {
void fn_47_9A74(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_47_A640(void* self, int n) {
    if (self != 0) {
        fn_47_9A74(self, 0);
        if (n > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

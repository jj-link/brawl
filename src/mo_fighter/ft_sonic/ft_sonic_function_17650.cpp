#pragma force_active on
extern "C" {
void fn_123_175E0(void* self, short flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_123_17650(void* self, short flag) {
    if (self != 0) {
        fn_123_175E0(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

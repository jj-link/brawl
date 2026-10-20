#pragma force_active on
extern "C" {
void* fn_106_90B4(void* ptr, short should_delete);
void fn_106_8F7C(void* self, short flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_106_9114(char* self, short flag) {
    short neg = -1;
    short zero = 0;
    if (self != 0) {
        fn_106_90B4(self + 0x17c, neg);
        if (self != 0) {
            fn_106_8F7C(self, zero);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

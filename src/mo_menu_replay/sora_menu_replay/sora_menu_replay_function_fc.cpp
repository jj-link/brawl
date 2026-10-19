#pragma force_active on
extern "C" {
void fn_6_1E4(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_7_FC(void* self, int flag) {
    if (self) {
        fn_6_1E4(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

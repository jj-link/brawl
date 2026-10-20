#pragma force_active on
extern "C" {
void fn_27_3335CC(void* p, int x);
void fn_27_333D04(void* p, int x);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_333C9C(char* self, int flag) {
    if (self) {
        fn_27_3335CC(self + 0x5df8, -1);
        fn_27_333D04(self + 4, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

#pragma force_active on
extern "C" {
void fn_27_3335CC(void* p, int x);
void fn_27_333C9C(void* p, int x);
}

extern "C" void* fn_27_333C34(char* self, int flag) {
    if (self) {
        fn_27_3335CC(self + 0x7d48, -1);
        fn_27_333C9C(self + 4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}

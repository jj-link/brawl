#pragma force_active on
extern "C" {
void fn_27_27D1CC(void* self, int arg);
}

extern "C" void* fn_27_2D7BCC(void* self, int arg) {
    if (self) {
        fn_27_27D1CC(self, 0);
        if (arg > 0) {
            operator delete(self);
        }
    }
    return self;
}

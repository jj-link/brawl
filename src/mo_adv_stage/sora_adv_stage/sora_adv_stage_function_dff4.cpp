#pragma force_active on
extern "C" void fn_27_234C8C(void* self, int flag);

extern "C" void* fn_40_DFF4(void* self, int size) {
    if (self) {
        fn_27_234C8C(self, 0);
        if (size > 0) {
            ::operator delete(self);
        }
    }
    return self;
}

#pragma force_active on
extern "C" void fn_27_C9EDC(void*, short);

extern "C" {
void* fn_110_68B0(void* self, short flags) {
    if (self != 0) {
        fn_27_C9EDC(self, -1);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
}

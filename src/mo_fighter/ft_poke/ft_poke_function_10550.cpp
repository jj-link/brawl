#pragma force_active on
extern "C" void* fn_116_53D8(void* ptr, short count);

extern "C" void* fn_116_10550(void* self, short flag) {
    if (self != 0) {
        fn_116_53D8(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}

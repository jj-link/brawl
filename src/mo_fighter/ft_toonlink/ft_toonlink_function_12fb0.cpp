#pragma force_active on
extern "C" void* fn_27_1A4778(void*, short);

extern "C" void* fn_121_12FB0(void* self, short flags) {
    if (self) {
        fn_27_1A4778(self, static_cast<short>(-1));
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}

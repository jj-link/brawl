#pragma force_active on
extern "C" void fn_27_B4780(void*, short);

extern "C" void* fn_27_B21D0(void* self, int flag) {
    if (self != 0) {
        fn_27_B4780(self, 0);
        if (flag > 0) {
            delete static_cast<unsigned char*>(self);
        }
    }
    return self;
}

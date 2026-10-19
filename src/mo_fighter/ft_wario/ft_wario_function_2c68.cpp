#pragma force_active on
extern "C" void* fn_27_14CD30(void*, short);
void operator delete(void* p);

extern "C" {
void* fn_110_2C68(void* self, short flag) {
    if (self != 0) {
        fn_27_14CD30(self, static_cast<short>(-1));
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}

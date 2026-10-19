#pragma force_active on
extern "C" void* fn_27_1A3940(void*, short);

extern "C" void* fn_98_58A4(void* self, int deleting) {
    if (self) {
        fn_27_1A3940(self, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) operator delete(self);
    }
    return self;
}

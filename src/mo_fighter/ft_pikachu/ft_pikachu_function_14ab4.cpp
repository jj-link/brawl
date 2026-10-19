#pragma force_active on
extern "C" void fn_98_1362C(void*, short);

extern "C" void* fn_98_14AB4(void* self, int deleting) {
    if (self) {
        fn_98_1362C(self, static_cast<short>(0));
        if (static_cast<short>(deleting) > 0) operator delete(self);
    }
    return self;
}

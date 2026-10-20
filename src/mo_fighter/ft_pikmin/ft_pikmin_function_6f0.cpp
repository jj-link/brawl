#pragma force_active on
extern "C" void fn_113_68C(void* self, short arg);

extern "C" void* fn_113_6F0(void* self, short flags) {
    if (self != 0) {
        fn_113_68C(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}

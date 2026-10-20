#pragma force_active on
extern "C" void* fn_113_4770(void* p, short n);

extern "C" void* fn_113_1BE0C(void* self, short flags) {
    if (self != 0) {
        fn_113_4770(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}

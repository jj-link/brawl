#pragma force_active on
extern "C" void fn_54_2CB0(void*, int);

extern "C" void* fn_54_C170(void* self, int flags) {
    if (self != 0) {
        fn_54_2CB0(self, 0);
        if (flags > 0) {
            ::operator delete(self);
        }
    }
    return self;
}

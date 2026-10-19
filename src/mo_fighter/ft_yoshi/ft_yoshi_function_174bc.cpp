#pragma force_active on
extern "C" void* fn_95_6138(void* ptr, short count);

extern "C" void* fn_95_174BC(void* self, short flags) {
    if (self != 0) {
        fn_95_6138(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}

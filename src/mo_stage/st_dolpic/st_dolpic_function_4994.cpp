#pragma force_active on
extern "C" void fn_46_4570(void* self, int flag);

extern "C" void* fn_46_4994(void* self, int size) {
    if (self != 0) {
        fn_46_4570(self, 0);
        if (size > 0) {
            operator delete(self);
        }
    }
    return self;
}

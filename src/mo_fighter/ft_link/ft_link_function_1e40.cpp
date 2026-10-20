#pragma force_active on
extern "C" void fn_93_1BB4(void* self, short flag);

extern "C" void* fn_93_1E40(void* self, short size) {
    if (self != 0) {
        fn_93_1BB4(self, 0);
        if (size > 0) {
            operator delete(self);
        }
    }
    return self;
}

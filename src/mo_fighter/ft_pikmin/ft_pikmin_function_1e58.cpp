#pragma force_active on
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_113_1EB4(void* object, short deleting);

extern "C" void* fn_113_1E58(void* self, short deleting) {
    if (self != 0) {
        fn_113_1EB4(self, -1);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

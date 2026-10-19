#pragma force_active on
extern "C" void* fn_95_D684(void* object, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_95_D81C(void* self, short deleting) {
    if (self != 0) {
        fn_95_D684(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

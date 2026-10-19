#pragma force_active on
extern "C" void* fn_122_1249C(void* object, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_122_12634(void* self, short deleting) {
    if (self != 0) {
        fn_122_1249C(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

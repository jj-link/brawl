#pragma force_active on
extern "C" void* fn_95_7BE4(void* object, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_95_7B88(void* self, short deleting) {
    if (self != 0) {
        fn_95_7BE4(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

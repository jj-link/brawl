#pragma force_active on
extern "C" void* fn_120_38FC(void* p, short size);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_120_13B80(void* self, short flag) {
    if (self != 0) {
        fn_120_38FC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

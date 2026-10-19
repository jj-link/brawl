#pragma force_active on
extern "C" void fn_27_C9D44(void* self, short arg);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_41_2F1AC(void* self, short del) {
    if (self != 0) {
        fn_27_C9D44(self, -1);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

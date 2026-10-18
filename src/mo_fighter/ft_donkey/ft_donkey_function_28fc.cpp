#pragma force_active on
extern "C" void fn_27_1A6B04(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_28FC(void* self, int flag) {
    if (self != 0) {
        fn_27_1A6B04(self, -1);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

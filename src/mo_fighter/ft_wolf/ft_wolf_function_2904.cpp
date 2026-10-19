#pragma force_active on
extern "C" void fn_27_1A60DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_2904(void* self, short flag) {
    if (self != 0) {
        fn_27_1A60DC(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

#pragma force_active on
extern "C" void __dl__FPv(void* p);
extern "C" void fn_27_1A6C08(void* ptr, short size);

extern "C" void* fn_107_298C(void* self, short flag) {
    if (self != 0) {
        fn_27_1A6C08(self, (short)-1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

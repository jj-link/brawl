#pragma force_active on
extern "C" void* fn_27_1A3E54(void* ptr, short size);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_95_6448(void* self, short flags) {
    if (self != 0) {
        fn_27_1A3E54(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

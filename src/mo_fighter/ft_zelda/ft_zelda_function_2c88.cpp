#pragma force_active on
extern "C" void* fn_27_1966BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_2C88(void* self, short flags) {
    if (self != 0) {
        fn_27_1966BC(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

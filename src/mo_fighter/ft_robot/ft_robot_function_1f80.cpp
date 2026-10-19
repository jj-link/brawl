#pragma force_active on
extern "C" void fn_27_1362C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_1F80(void* self, short del) {
    if (self != 0) {
        fn_27_1362C(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

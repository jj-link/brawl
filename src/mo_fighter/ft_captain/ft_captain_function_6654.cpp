#pragma force_active on
extern "C" void fn_27_1A75E4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_6654(void* self, short count) {
    if (self != 0) {
        fn_27_1A75E4(self, -1);
        if (count > 0)
            __dl__FPv(self);
    }
    return self;
}

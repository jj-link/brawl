#pragma force_active on
extern "C" void fn_27_5CC1C(void*, short);
extern "C" void* fn_27_D3080(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_14E14(void* self, short deleteFlag) {
    if (self != 0) {
        fn_27_5CC1C((char*)self + 0xAC, -1);
        if (self != 0) {
            fn_27_D3080(self, -1);
        }
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

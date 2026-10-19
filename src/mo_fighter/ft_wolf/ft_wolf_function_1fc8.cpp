#pragma force_active on
extern "C" void fn_27_1362C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_125_1FC8(void* self, short flag) {
    if (self != 0) {
        fn_27_1362C(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

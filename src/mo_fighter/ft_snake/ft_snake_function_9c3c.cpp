#pragma force_active on
extern "C" void fn_27_19BFCC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_9C3C(void* self, short flag) {
    if (self != 0) {
        fn_27_19BFCC(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

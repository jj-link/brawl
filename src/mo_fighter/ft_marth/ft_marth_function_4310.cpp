#pragma force_active on
extern "C" {
extern void fn_27_19BFCC(void*, short);
extern void __dl__FPv(void*);

void* fn_106_4310(void* self, short flag) {
    if (self != 0) {
        fn_27_19BFCC(self, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

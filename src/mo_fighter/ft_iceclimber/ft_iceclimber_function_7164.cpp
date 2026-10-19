#pragma force_active on
extern "C" void fn_27_19BFCC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_7164(void* self, short deleting) {
    if (self != 0) {
        fn_27_19BFCC(self, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

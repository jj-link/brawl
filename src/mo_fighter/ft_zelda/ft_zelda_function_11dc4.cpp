#pragma force_active on
extern "C" void fn_104_3C90(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_11DC4(void* self, short flag) {
    if (self != 0) {
        fn_104_3C90(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

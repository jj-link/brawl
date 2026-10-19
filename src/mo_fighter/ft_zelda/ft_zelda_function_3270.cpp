#pragma force_active on
extern "C" void fn_104_32CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_3270(void* self, short flag) {
    if (self != 0) {
        fn_104_32CC(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

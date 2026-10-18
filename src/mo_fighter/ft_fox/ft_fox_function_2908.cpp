#pragma force_active on
extern "C" void fn_27_1A60DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_2908(void* self, short flag) {
    if (self != 0) {
        fn_27_1A60DC(self, -1);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}

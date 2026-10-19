#pragma force_active on
extern "C" void* fn_27_CC7EC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_69AC(void* self, short arg2) {
    if (self != 0) {
        fn_27_CC7EC(self, -1);
        if (arg2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

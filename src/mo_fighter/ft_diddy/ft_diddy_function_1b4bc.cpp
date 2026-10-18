#pragma force_active on
extern "C" void fn_115_1B434(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_1B4BC(void* self, short count) {
    if (self != 0) {
        fn_115_1B434(self, 0);
        if (count > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

#pragma force_active on
extern "C" void fn_94_3248(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_31EC(void* self, short param) {
    if (self != 0) {
        fn_94_3248(self, -1);
        if (param > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

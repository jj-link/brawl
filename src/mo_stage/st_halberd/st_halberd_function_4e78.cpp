#pragma force_active on
extern "C" void fn_57_39EC(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_57_4E78(void* self, int shouldDelete) {
    if (self != 0) {
        fn_57_39EC(self, 0);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

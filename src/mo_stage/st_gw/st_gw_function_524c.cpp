#pragma force_active on
extern "C" {
void fn_63_34F8(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_63_524C(void* self, int size) {
    if (self) {
        fn_63_34F8(self, 0);
        if (size > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

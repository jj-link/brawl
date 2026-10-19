#pragma force_active on
void operator delete(void*);

extern "C" void fn_63_34F8(void*, int);

extern "C" void* fn_63_3A3C(void* self, int del) {
    if (self != 0) {
        fn_63_34F8(self, 0);
        if (del > 0) {
            operator delete(self);
        }
    }
    return self;
}

#pragma force_active on
extern "C" {
void fn_51_289C(void* self, int flag);
void __dl__FPv(void* p);

void* fn_51_13228(void* self, int del) {
    if (self != 0) {
        fn_51_289C(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

#pragma force_active on
extern "C" {
void fn_27_C9EDC(void*, short);
void __dl__FPv(void*);

void* fn_113_5E78(void* self, int p2) {
    if (self != 0) {
        fn_27_C9EDC(self, -1);
        if ((short)p2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

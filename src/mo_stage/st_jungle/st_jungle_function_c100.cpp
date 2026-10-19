#pragma force_active on
extern "C" void fn_51_3C30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_51_C100(void* self, int flag) {
    if (self != 0) {
        fn_51_3C30(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

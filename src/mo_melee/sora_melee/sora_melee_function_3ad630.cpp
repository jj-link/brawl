#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_27_3AD630(void* self, int destroy) {
    if (self) {
        fn_27_93100(self, 0);
        if (destroy > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

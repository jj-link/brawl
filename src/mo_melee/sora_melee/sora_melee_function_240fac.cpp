#pragma force_active on
extern "C" {

extern void fn_27_240848(void*, int);
extern void __dl__FPv(void*);

void* fn_27_240FAC(void* self, int release) {
    if (self) {
        fn_27_240848(self, 0);
        if (release > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

}

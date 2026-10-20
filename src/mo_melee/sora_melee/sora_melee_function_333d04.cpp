#pragma force_active on
extern "C" {
void fn_27_3335CC(void*, int);
void fn_27_333D6C(void*, int);
void __dl__FPv(void*);

void* fn_27_333D04(char* self, int arg) {
    if (self) {
        fn_27_3335CC(self + 0x3ea8, -1);
        fn_27_333D6C(self + 4, -1);
        if (arg > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

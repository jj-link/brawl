#pragma force_active on
extern "C" {
void fn_40_43A04(void* self, int arg);
void __dl__FPv(void* p);

void* fn_40_47DF8(void* self, int flag) {
    if (self != 0) {
        fn_40_43A04(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

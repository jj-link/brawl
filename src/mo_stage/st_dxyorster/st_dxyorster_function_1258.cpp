#pragma force_active on
extern "C" {
void fn_76_C44(void* self, int flag);
void __dl__FPv(void* p);

void* fn_76_1258(void* self, int flag) {
    if (self) {
        fn_76_C44(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

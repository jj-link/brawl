#pragma force_active on
extern "C" {
void* fn_800A6A94(void* base, short deleteFlag);
void __dl__FPv(void* p);

void* fn_106_5368(void* self, short flag) {
    if (self != 0) {
        fn_800A6A94(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

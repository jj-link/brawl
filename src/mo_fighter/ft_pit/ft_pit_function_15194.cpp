#pragma force_active on
typedef signed short s16;

extern "C" {
void fn_112_151F0(void* self, s16 arg);
void __dl__FPv(void* p);

void* fn_112_15194(void* self, s16 flags) {
    if (self != 0) {
        fn_112_151F0(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

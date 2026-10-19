#pragma force_active on
extern "C" {
void fn_27_19C818(void*, short);
void __dl__FPv(void*);

void* fn_102_5B5C(void* self, short p2) {
    if (self != 0) {
        fn_27_19C818(self, -1);
        if (p2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

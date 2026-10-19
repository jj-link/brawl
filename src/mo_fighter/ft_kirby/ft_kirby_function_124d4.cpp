#pragma force_active on
extern "C" {
typedef signed short s16;
void fn_96_1245C(void* self, s16 arg);
void __dl__FPv(void* p);

void* fn_96_124D4(void* self, s16 flag) {
    if (self != 0) {
        fn_96_1245C(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

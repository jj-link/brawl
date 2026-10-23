#pragma force_active on
extern "C" {
void fn_27_C9EDC(void*, short);
void __dl__FPv(void*);

void* fn_106_4E50(void* self, short flag) {
    if (self != 0) {
        fn_27_C9EDC(self, (short)-1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

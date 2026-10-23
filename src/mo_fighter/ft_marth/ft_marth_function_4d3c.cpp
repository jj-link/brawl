#pragma force_active on
extern "C" {
void fn_27_1A75E4(void*, short);
void __dl__FPv(void*);

void* fn_106_4D3C(void* self, short flag) {
    if (self != 0) {
        fn_27_1A75E4(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

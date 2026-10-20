#pragma force_active on
extern "C" {
void* fn_27_1A15B8(void*, short);
void fn_100_5870(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_57F8(char* self, short flags) {
    if (self != 0) {
        fn_27_1A15B8(self + 0x11C, -1);
        if (self != 0) {
            fn_100_5870(self, 0);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

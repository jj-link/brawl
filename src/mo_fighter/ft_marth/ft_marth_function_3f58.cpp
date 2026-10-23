#pragma force_active on
extern "C" {
void fn_27_1A1E70(void* ptr, short flag);
void* fn_106_3FC8(void* self, short shouldDelete);
void __dl__FPv(void* p);

void* fn_106_3F58(void* self, short flag) {
    if (self != 0) {
        fn_27_1A1E70((char*)self + 0x1C, -1);
        fn_106_3FC8(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

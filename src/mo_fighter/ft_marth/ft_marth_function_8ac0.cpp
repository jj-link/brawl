#pragma force_active on
extern "C" {
void* fn_106_8A60(void* ptr, short flag);
void* fn_106_8940(void* self, short shouldDelete);
void __dl__FPv(void* p);

void* fn_106_8AC0(void* self, short flag) {
    if (self != 0) {
        fn_106_8A60((char*)self + 0x60, -1);
        fn_106_8940(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

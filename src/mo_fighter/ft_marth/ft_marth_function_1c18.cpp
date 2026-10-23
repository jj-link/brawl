#pragma force_active on
extern "C" {
extern void fn_106_1AFC(void*, short);
extern void __dl__FPv(void*);

void* fn_106_1C18(void* self, short flag) {
    if (self != 0) {
        fn_106_1AFC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

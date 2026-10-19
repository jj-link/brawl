#pragma force_active on
extern "C" {
void fn_106_943C(void* self, short mode);
void __dl__FPv(void* p);

void* fn_106_94B4(void* self, short flags) {
    if (self != 0) {
        fn_106_943C(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

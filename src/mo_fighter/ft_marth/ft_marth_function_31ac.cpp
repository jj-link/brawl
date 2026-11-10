#pragma force_active on
extern "C" {
void fn_106_3208(void*, short);
void __dl__FPv(void*);

void* fn_106_31AC(void* self, short flags) {
    if (self != 0) {
        fn_106_3208(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
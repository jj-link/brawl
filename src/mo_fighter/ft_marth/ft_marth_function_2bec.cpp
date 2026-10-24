#pragma force_active on
extern "C" {
void fn_27_1966BC(void*, short);
void __dl__FPv(void*);

void* fn_106_2BEC(void* self, short flags) {
    if (self != 0) {
        fn_27_1966BC(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

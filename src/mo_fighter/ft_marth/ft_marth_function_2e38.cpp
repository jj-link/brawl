#pragma force_active on
extern "C" {
void fn_27_ACC5C(void*, short);
void __dl__FPv(void*);

void* fn_106_2E38(void* self, short flags) {
    if (self != 0) {
        fn_27_ACC5C(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
#pragma force_active on
extern "C" {
void fn_27_5B39C(void*, short);
void __dl__FPv(void*);

void* fn_106_436C(void* self, short flag) {
    if (self != 0) {
        fn_27_5B39C(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

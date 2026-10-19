#pragma force_active on
extern "C" {
void* fn_27_5BFA0(void*, short);
void __dl__FPv(void*);

void* fn_104_2C2C(void* self, short flags) {
    if (self != 0) {
        fn_27_5BFA0(self, -1);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}

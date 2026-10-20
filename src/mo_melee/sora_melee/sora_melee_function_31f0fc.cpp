#pragma force_active on
extern "C" {
void fn_27_31F178(void* p, int arg);
void fn_27_31F23C(void* p, int arg);
void* fn_27_1D81C8(void* self, short flag);
void __dl__FPv(void* p);
}

struct FnSelf {
    char pad[0xcc];
    char sub[0x1798 - 0xcc];
};

extern "C" void* fn_27_31F0FC(void* self, int flag) {
    FnSelf* s = (FnSelf*)self;
    if (s) {
        if (s->sub) {
            fn_27_31F178(s->sub + (0x1798 - 0xcc), -1);
            fn_27_31F23C(s->sub, 0);
        }
        fn_27_1D81C8(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

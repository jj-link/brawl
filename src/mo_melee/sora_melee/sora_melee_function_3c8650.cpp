#pragma force_active on
extern "C" {
void fn_27_31F178(void* p, int v);
void fn_27_3C86CC(void* p, int v);
void* fn_27_1D81C8(void* self, short flag);
void __dl__FPv(void* p);
}

struct FnObj {
    int unk0;
};

struct FnSelf {
    char pad[0xcc];
    FnObj obj;
};

extern "C" void* fn_27_3C8650(FnSelf* self, int flag) {
    if (self) {
        if (&self->obj) {
            fn_27_31F178((char*)self + 0x17a4, -1);
            fn_27_3C86CC(&self->obj, 0);
        }
        fn_27_1D81C8(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

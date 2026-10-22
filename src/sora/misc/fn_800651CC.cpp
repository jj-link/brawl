#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void fn_801AB078(void*, int);
void fn_801AB0CC(void*, int);
extern unsigned char lbl_80453E40[];
}

struct Sub {
    unsigned char pad0[0xD4];
    int field_D4;
};

struct Obj {
    unsigned char* vtable;
    Sub* sub;
};

extern "C" Obj* fn_800651CC(Obj* self, int flag) {
    if (self) {
        Sub* s = self->sub;
        self->vtable = lbl_80453E40;
        if (s) {
            if (s) {
                s->field_D4 = 0;
                fn_801AB078(self->sub, 1);
                fn_801AB078(self->sub, 4);
                fn_801AB0CC(self->sub, 4);
            }
            self->sub = 0;
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

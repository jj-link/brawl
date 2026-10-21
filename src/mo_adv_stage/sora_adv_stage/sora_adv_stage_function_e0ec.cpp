#pragma force_active on
extern "C" {
void __dl__FPv(void*);
extern char lbl_40_data_1B30[];
}

struct Base {
    int unk0;
};

struct Child : Base {
    virtual void vf1();
    virtual void vfn(int);
};

struct Obj {
    Child* child;
    void* unk4;
};

extern "C" void* fn_40_E0EC(Obj* self, int flag) {
    if (self != 0) {
        if (self != 0) {
            Child* child = self->child;
            self->unk4 = lbl_40_data_1B30;
            if (child != 0 && child != 0) {
                child->vfn(1);
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

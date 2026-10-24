#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void fn_800B8A0C(void*, int);
void fn_800B8EDC(void*, void*);
extern char lbl_8045C594[];
}

struct Sub {
    char pad[0x5C];
    virtual ~Sub();
};

struct Obj {
    char pad0[4];
    Sub* unk4;
    void* unk8;
    char pad1[0xC0];
    void* unkCC;
};

extern "C" Obj* fn_800FBB80(Obj* self, int flag) {
    if (self) {
        self->unkCC = lbl_8045C594;
        fn_800B8EDC(self->unk8, self->unk4);

        for (unsigned int i = 0; i < 1; ++i) {
            if ((&self->unk4)[i]) {
                delete (&self->unk4)[i];
                (&self->unk4)[i] = 0;
            }
        }

        if (self->unk8) {
            fn_800B8A0C(self->unk8, 1);
            self->unk8 = 0;
        }

        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}

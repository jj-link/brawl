#pragma force_active on

struct SubObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int, int);
};

struct MainObj {
    virtual void v0(int);
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    SubObj* unk14;
    SubObj* unk18;
    int unk1C;
    int unk20;
};

extern "C" void fn_802C08FC(MainObj* self) {
    if (self->unk1C == 0x1A) {
        self->unk14->v9(self->unkC, self->unk10);
    }
    if (self->unk20 == 0x1A) {
        self->unk18->v9(self->unk10, self->unkC);
    }
    if (self != 0) {
        self->v0(1);
    }
}

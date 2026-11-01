#pragma force_active on
extern "C" unsigned char lbl_27_data_99358[];
extern "C" unsigned char lbl_27_data_99390[];
extern "C" unsigned char lbl_27_data_8B48[];

class Emb1 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

class Emb2 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

struct Self {
    unsigned int f00;
    unsigned int f04;
    unsigned char f08;
    unsigned char f09;
    unsigned char f0A;
    unsigned char f0B;
    unsigned int f0C;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1C;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2C;
    unsigned int f30;
    unsigned int f34;
    unsigned int f38;
};

extern "C" Self* fn_27_387594(Self* self, signed char arg1) {
    unsigned int saved38 = self->f38;
    unsigned int saved1c = self->f1C;
    Emb1* e1 = (Emb1*)((char*)self + 0x14);
    unsigned int v00 = (unsigned int)lbl_27_data_99358;
    unsigned int v18 = (unsigned int)(lbl_27_data_99390 + 0x48);

    self->f00 = v00;
    self->f04 = 0;
    self->f08 = (unsigned char)arg1;
    self->f09 = 0;
    self->f0A = 0;
    self->f0C = 0;
    self->f10 = 0;
    *(void**)e1 = (void*)lbl_27_data_99390;
    self->f18 = v18;
    self->f1C = saved1c & 0x7FFFF;
    self->f30 = (unsigned int)lbl_27_data_8B48;
    self->f34 = (unsigned int)(lbl_27_data_8B48 + 0x48);
    self->f38 = saved38 & 0xFFFF;

    e1->v8();
    ((Emb2*)((char*)self + 0x30))->v8();

    return self;
}

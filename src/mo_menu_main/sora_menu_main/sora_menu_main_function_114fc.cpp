#pragma force_active on

class MuMsg;

struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13(void* a);
};

struct Mid {
    char pad[0x48];
    Sub* sub;
};

struct Arg {
    char pad[0xc];
    void* val;
};

struct Self {
    char pad0[0x40];
    Mid* mid;
    char pad44[0x517c - 0x44];
    Arg* a517c[5];
    char pad5190[0x5198 - 0x5190];
    Arg* a5198;
    Arg* a519c[8];
    Arg* a51bc[32];
    Arg* a523c[32];
    Sub* s52bc;
    char pad52c0[0x52c8 - 0x52c0];
    MuMsg* msg52c8;
    char pad52cc[4];
    MuMsg* msg52d0;
    char pad52d4[4];
    void* buf52d8[32];
    char pad5358[0x5414 - 0x5358];
    unsigned char flag5414;
};

extern "C" void printf__5MuMsgFUlPCce(MuMsg*, unsigned long, const char*, ...);
extern "C" void free__13gfHeapManagerFPv(void*);
extern "C" char lbl_2_data_17A0[];

extern "C" void fn_2_114FC(Self* self) {
    int i;
    for (i = 6; i < 10; i++) {
        printf__5MuMsgFUlPCce(self->msg52c8, i, lbl_2_data_17A0);
    }
    printf__5MuMsgFUlPCce(self->msg52d0, 1, lbl_2_data_17A0);
    printf__5MuMsgFUlPCce(self->msg52d0, 2, lbl_2_data_17A0);
    for (i = 0; i < 5; i++) {
        self->s52bc->f13(self->a517c[i]->val);
    }
    for (i = 0; i < 32; i++) {
        self->mid->sub->f13(self->a51bc[i]->val);
        if (self->buf52d8[i]) {
            free__13gfHeapManagerFPv(self->buf52d8[i]);
            self->buf52d8[i] = 0;
        }
        self->mid->sub->f13(self->a523c[i]->val);
    }
    for (i = 0; i < 8; i++) {
        self->mid->sub->f13(self->a519c[i]->val);
    }
    self->mid->sub->f13(self->a5198->val);
    printf__5MuMsgFUlPCce(self->msg52d0, 0, lbl_2_data_17A0);
    self->flag5414 = 0;
}

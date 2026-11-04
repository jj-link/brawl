#pragma force_active on
extern "C" {

void fn_801EC158(void*);
void fn_8015BFB4(void*, void*);
extern float lbl_805A2C68;

}

struct Base1C {
    int pad0;
    int pad4;
    int pad8;
    int f0c;
    int f10;
    int pad14;
    int pad18;
};

class SelfObj : public Base1C {
public:
    virtual void sv0();
    virtual void sv1();
    virtual int sv2(void*, void*, int, int);
    virtual void sv3();
    virtual void sv4();
    virtual void sv5();
    void* f20;
    int f24;
    int f28;
    short f2c;
    char pad2e[2];
    int f30;
    int f34;
    short f38;
    char pad3a[2];
    unsigned short f3c;
    char pad3e[2];
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    char pad54[0x30];
    float f84;
    float f88;
    float f8c;
    char pad90[0xc];
    int f9c;
};

class InnerObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void* v7();
    virtual void v8(void*);
};

class ResultObj : public Base1C {
public:
    virtual void v0();
    virtual void v1();
    virtual int v2(void*, int, int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad20[0xc8];
    unsigned short fe8;
};

struct Arg1Obj {
    InnerObj* inner;
    int val;
};

extern "C" int fn_80163AA0(SelfObj* self, Arg1Obj* arg1, int arg2, int arg3) {
    self->f10 = 0;
    self->f0c = 1;
    self->f24 = 0;
    self->f2c = 0;
    self->f28 = 0;
    self->f30 = 0;
    self->f38 = 0;
    self->f34 = 0;
    self->f3c = 0;
    self->f9c = arg1->val;
    fn_801EC158((void*)((char*)self + 0x54));
    float val = lbl_805A2C68;
    self->f20 = arg1;
    self->f44 = 0;
    self->f48 = 0;
    self->f4c = 0;
    self->f50 = 0;
    self->f84 = val;
    self->f88 = val;
    self->f8c = val;

    void* result = arg1->inner->v7();
    if (result == 0) return 0;
    ResultObj* r = (ResultObj*)result;
    if (r->v2(self, arg2, 0x80) == 0) {
        arg1->inner->v8(result);
        return 0;
    }
    fn_8015BFB4((void*)((char*)self + 0x24), result);
    self->f3c++;
    r->f0c = 1;
    r->fe8 += arg3;
    return 1;
}
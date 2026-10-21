#pragma force_active on
typedef float f32;
typedef int s32;
extern const float lbl_27_rodata_8B0;

struct Item {
    char pad0[4];
    float w;
    char pad1[0x14];
    unsigned int id;
};

struct Sub {
    virtual void v0();
    virtual Item* get(int i);
    virtual void v2();
    virtual int size();
};

struct Ret {
    char pad[0x28];
    unsigned int val;
};

struct Q {
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void q7();
    virtual void q8();
    virtual void q9();
    virtual void q10();
    virtual Ret* f13(int x);
};

struct Z {
    char pad[0x54];
    Q* q;
};

struct X {
    char pad[0xD8];
    Z* z;
};

struct Outer {
    char pad0[0x3C];
    X* x;
    Sub* sub;
};

extern "C" f32 fn_27_61B78(Outer* self) {
    f32 sum = lbl_27_rodata_8B0;
    for (int i = 0; i < self->sub->size(); i++) {
        Item* it = self->sub->get(i);
        Ret* r = self->x->z->q->f13(0);
        if (it->id != r->val) {
            sum += it->w;
        }
    }
    return sum;
}

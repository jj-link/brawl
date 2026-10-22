#pragma force_active on
class Obj14 {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void invoke();
};

struct Ctx {
    unsigned char pad[0x14];
    Obj14* sub;
    unsigned char pad2[0x08];
    float a;
    float b;
    float c;
    float d;
};

struct Vec4 {
    float x;
    float y;
    float z;
    float w;
};

extern "C" void fn_802D128C(Ctx* self, Vec4* out) {
    self->sub->invoke();
    out->x = out->x + self->a;
    out->y = out->y + self->b;
    out->z = out->z + self->c;
    out->w = out->w + self->d;
}

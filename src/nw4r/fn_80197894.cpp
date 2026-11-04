#pragma force_active on
extern float lbl_8059E8E0;

class Obj {
public:
    virtual void v0();
    virtual void v1(int a, int b, int c);
    char pad[0x14];
    float f18;
    float f1c;
    float f20;
    float f24;
    float (*fn)(Obj*, float, float, float);
};

extern "C" void fn_80197894(Obj* self) {
    self->f18 = self->fn(self, self->f20, self->f24, self->f18 + self->f1c * lbl_8059E8E0);
    self->v1(8, 0, 0);
}

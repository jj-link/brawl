#pragma force_active on
class Obj {
public:
    virtual void v0();
    virtual void v1(int a, int b, int c);
    char pad[0x14];
    float f18;
    float f1c;
    float f20;
    float f24;
    float (*fn)(float, float, float);
};

extern "C" void fn_80197818(Obj* self, float f) {
    self->f18 = self->fn(self->f20, self->f24, f);
    self->v1(8, 0, 0);
}

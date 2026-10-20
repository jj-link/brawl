#pragma force_active on
typedef unsigned char u8;

struct StPlanktonObj {
    char pad[0x184];
    u8 field184;
    int field188;
    float field18C;
};

extern "C" {
void fn_74_246C(StPlanktonObj* self, u8 v, int w, float f)
{
    self->field184 = v;
    self->field188 = w;
    self->field18C = f;
}
}
